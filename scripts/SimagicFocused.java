// @category Sigma
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class SimagicFocused extends GhidraScript {
 public void run() throws Exception {
  String[] args=getScriptArgs();
  for(int i=1;i<args.length;i++) { Address a=toAddr(args[i]); disassemble(a); if(getFunctionAt(a)==null) createFunction(a,null); }
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
  try(PrintWriter o=new PrintWriter(args[0])){
   for(int i=1;i<args.length;i++){
    Address a=toAddr(args[i]);Function f=getFunctionAt(a);o.println("// FUNCTION "+a);
    if(f==null){o.println("// NO FUNCTION");continue;}
    DecompileResults r=d.decompileFunction(f,60,monitor);
    if(r.decompileCompleted())o.println(r.getDecompiledFunction().getC());else o.println("// ERROR "+r.getErrorMessage());
    for(Instruction ins:currentProgram.getListing().getInstructions(f.getBody(),true))o.println("// "+ins.getAddress()+" "+ins);
   }
  }finally{d.dispose();}
 }
}
