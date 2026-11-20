// @category CubeBaby
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class Cube20230 extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]);out.mkdirs();
  String[] seeds={"004a3510","004a3680","004a3770","004a38a0","004a3b40","004a3c20","004a3e10","004a3ed0","004a4070","004a42c0","004a44b0","004a4770","004a4910","004a4cc0"};
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
