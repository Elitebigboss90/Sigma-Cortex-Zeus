// @category Sigma
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.SourceType;
import java.math.BigInteger;
public class SigmaCompareSeeds extends GhidraScript {
 public void run() throws Exception {
  long base=0x08020000L, end=base+currentProgram.getMemory().getSize();
  currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),toAddr(base),toAddr(end-1),BigInteger.ONE);
  if (currentProgram.getMemory().getBlock(toAddr(0x20000000L))==null)
   currentProgram.getMemory().createUninitializedBlock("RAM_hypothesis",toAddr(0x20000000L),0x20000L,false);
  for(int i=1;i<98;i++) {
   long val=getInt(toAddr(base+4*i))&0xffffffffL;
   if((val&1)==1 && val>=base && val<end) {
    Address a=toAddr(val&~1L); addEntryPoint(a); disassemble(a);
    if(getFunctionAt(a)==null) createFunction(a,"vector_"+i);
   }
  }
 }
}
