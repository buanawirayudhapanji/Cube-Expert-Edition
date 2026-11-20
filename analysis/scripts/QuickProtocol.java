// @category CubeBaby
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class QuickProtocol extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]);out.mkdirs();
  String[] seeds={"00486980","004867e0","00486810","00486ad0","00486af0","005068b0","00507930","00507de0","00507aa0","00508180","00508080","00507680","00507700","00507770","005077d0","00507850","005078d0","00507970","0050fe40"};
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
