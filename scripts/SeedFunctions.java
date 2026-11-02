// Seed already byte-validated Thumb function entry points from data tables.
// @category Sigma
import ghidra.app.script.GhidraScript;
public class SeedFunctions extends GhidraScript {
    public void run() throws Exception {
        for(String arg:getScriptArgs()) {
            var a=toAddr(Long.decode(arg));
            disassemble(a);
            if(getFunctionAt(a)==null)createFunction(a,null);
        }
    }
}
