// Evidence-based Zeus Cortex-M/Thumb model. RAM size is analysis coverage only.
// @category Sigma
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import java.math.BigInteger;
public class SimagicSeed extends GhidraScript {
 public void run() throws Exception {
  Address base=toAddr(0x08021e00L),v=toAddr(0x08022000L),end=currentProgram.getMemory().getMaxAddress();
  currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),base,end,BigInteger.ONE);
  createLabel(v,"Zeus_VectorTable",true);
  if(!currentProgram.getMemory().contains(toAddr(0x20000000L))){
   var ram=currentProgram.getMemory().createUninitializedBlock("SRAM_model_128KiB",toAddr(0x20000000L),0x20000,false);
   ram.setRead(true);ram.setWrite(true);ram.setExecute(false);
  }
  for(int i=0;i<100;i++){
   Address slot=v.add(i*4);long value=getInt(slot)&0xffffffffL;
   createData(slot,DWordDataType.dataType);
   if(i==0||(value&1)==0||value-1<v.getOffset()||value-1>end.getOffset())continue;
   Address target=toAddr(value&~1L);
   currentProgram.getReferenceManager().addMemoryReference(slot,target,RefType.DATA,SourceType.USER_DEFINED,0);
   disassemble(target);if(getFunctionAt(target)==null)createFunction(target,i==1?"Reset_Handler":null);
   if(i==1)addEntryPoint(target);
  }
 }
}
