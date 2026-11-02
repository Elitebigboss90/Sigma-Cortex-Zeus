// Evidence-based Cortex/Thumb import setup. No assumption of full physical RAM.
// @category Sigma
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import java.math.BigInteger;

public class SeedCortex extends GhidraScript {
    public void run() throws Exception {
        Address base=toAddr(0x08020000L), end=currentProgram.getMemory().getMaxAddress();
        currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),base,end,BigInteger.ONE);
        createLabel(base,"VectorTable",true);
        // Analyst model covering observed SRAM pointers, not proof of physical size.
        if (!currentProgram.getMemory().contains(toAddr(0x20000000L))) {
            var ram=currentProgram.getMemory().createUninitializedBlock("SRAM_model_64KiB",toAddr(0x20000000L),0x10000,false);
            ram.setRead(true); ram.setWrite(true); ram.setExecute(false);
        }
        for (int i=0;i<102;i++) {
            Address slot=base.add(i*4); long value=getInt(slot)&0xffffffffL;
            createData(slot,DWordDataType.dataType);
            if (i==0 || (value&1)==0 || value-1<base.getOffset() || value-1>end.getOffset()) continue;
            Address target=toAddr(value&~1L);
            currentProgram.getReferenceManager().addMemoryReference(slot,target,RefType.DATA,SourceType.USER_DEFINED,0);
            disassemble(target);
            if (getFunctionAt(target)==null) createFunction(target,i==1?"Reset_Handler":null);
            if(i==1) addEntryPoint(target);
        }
    }
}
