// Index functions and decompile only caller-selected addresses.
// @category Sigma
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportFirmware extends GhidraScript {
    public void run() throws Exception {
        String[] args=getScriptArgs();
        try(PrintWriter idx=new PrintWriter(args[0]+".functions.tsv")) {
            for(Function f:currentProgram.getFunctionManager().getFunctions(true)) idx.println(f.getEntryPoint()+"\t"+f.getBody().getNumAddresses()+"\t"+f.getName());
        }
        Set<Function> selected=new TreeSet<>((a,b)->a.getEntryPoint().compareTo(b.getEntryPoint()));
        for(int i=1;i<args.length;i++) {
            Address a=toAddr(Long.decode(args[i])); Function f=getFunctionContaining(a);
            if(f!=null) selected.add(f);
            else for(Reference r:getReferencesTo(a)) { f=getFunctionContaining(r.getFromAddress());if(f!=null)selected.add(f); }
        }
        DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
        try(PrintWriter out=new PrintWriter(args[0]+".c")) {
            for(Function f:selected) {
                out.println("\n// FUNCTION "+f.getName()+" @ "+f.getEntryPoint());
                for(Reference r:getReferencesTo(f.getEntryPoint())) out.println("// XREF "+r.getFromAddress());
                DecompileResults x=d.decompileFunction(f,60,monitor);
                if(x.decompileCompleted())out.println(x.getDecompiledFunction().getC());else out.println(x.getErrorMessage());
            }
        } finally {d.dispose();}
    }
}
