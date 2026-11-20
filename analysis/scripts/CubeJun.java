// @category CubeBaby
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class CubeJun extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]);out.mkdirs();
  String[] seeds={"0049dee0","0049e0f0","0049e1f0","0049e220","0049e350","0049e630","0049e710","0049e910","0049e970","0049eb40","0049eb90","0049ebe0","0049ec30","0049ec50","0049efd0","0049f520","0049f590"};
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
