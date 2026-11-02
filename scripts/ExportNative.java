// Static export of application functions and selected symbol references.
// @category Sigma
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ExportNative extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long lo = Long.decode(args[1]), hi = Long.decode(args[2]);
        DecompInterface decomp = new DecompInterface(); decomp.openProgram(currentProgram);
        try (PrintWriter out = new PrintWriter(args[0])) {
            out.println("Program " + currentProgram.getName() + " language=" + currentProgram.getLanguageID());
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                long a = f.getEntryPoint().getOffset();
                if (a < lo || a >= hi) continue;
                out.println("\n// FUNCTION " + f.getName() + " @ " + f.getEntryPoint());
                DecompileResults r = decomp.decompileFunction(f, 45, monitor);
                if (r.decompileCompleted()) out.println(r.getDecompiledFunction().getC());
                else out.println("// ERROR " + r.getErrorMessage());
            }
            for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(true)) {
                if (!(s.getName().startsWith("Hid") || s.getName().contains("Resource") || s.getName().equals("WriteFile") || s.getName().equals("ReadFile"))) continue;
                out.println("// SYMBOL " + s.getName() + " @ " + s.getAddress());
                for (Reference r : getReferencesTo(s.getAddress())) out.println("// XREF " + r.getFromAddress() + " " + r.getReferenceType());
            }
        } finally { decomp.dispose(); }
    }
}
