// @category CubeBaby
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class WriteIR extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]);out.mkdirs();
  String[] seeds={"005066c0","00507cd0","00507d20","00507d60","00507b30","00507680","00507700","00507770","00507850","004a3770","004a4770","0049e220","0049ebe0","0049f590","0049eea0"};
  for(String addr:seeds) {
   Address a=toAddr(addr);disassemble(a);
   if(getFunctionAt(a)==null) createFunction(a,null);
  }
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
  PrintWriter ix=new PrintWriter(new File(out,"index.txt"));
  for(String addr:seeds) {
   Function f=getFunctionAt(toAddr(addr));if(f==null)continue;
   ix.println(addr+" "+f.getName());ix.flush();
   DecompileResults res=d.decompileFunction(f,10,monitor);
   if(res.decompileCompleted()) {
    PrintWriter w=new PrintWriter(new File(out,addr+".c"));
    w.println(res.getDecompiledFunction().getC());w.close();
   }
  }
  ix.close();d.dispose();
 }
}
