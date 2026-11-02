// Seed Thumb code pointers from verified C++ USB-driver vtable regions only.
// @category Sigma
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.*;
public class SeedVtables extends GhidraScript {
    public void run() throws Exception {
        long[][] ranges={{0x08046640L,0x08046850L},{0x080469f4L,0x08046b00L}};
        for(long[] range:ranges) for(long p=range[0];p<range[1];p+=4) {
            var slot=toAddr(p);long v=getInt(slot)&0xffffffffL;
            if((v&1)==0 || v<0x08020199L || v>=0x08046000L)continue;
            var target=toAddr(v&~1L);
            currentProgram.getReferenceManager().addMemoryReference(slot,target,RefType.DATA,SourceType.USER_DEFINED,0);
            disassemble(target);if(getFunctionAt(target)==null)createFunction(target,null);
        }
    }
}
