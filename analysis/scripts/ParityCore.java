// @category CubeBaby
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class ParityCore extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]);out.mkdirs();
  String[] seeds={"0049eb40","0049eb90","0049ebe0","0049ec30","0049ec50","0049ed60","0049eea0","0049efd0","0049f070","0049f520","0049f590","0049f8d0","004a0120","004a02e0","005066c0","005079c0","0050a570","0050a5c0","0050a5f0","0050a660","0050a930","0050a9c0","0050aff0","0050b160","0050b180","0050b260","0050b290"};
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
