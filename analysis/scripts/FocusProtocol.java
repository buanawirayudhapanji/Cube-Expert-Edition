// @category CubeBaby
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;
public class FocusProtocol extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]);out.mkdirs();
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
  Set<Function> selected=new LinkedHashSet<>();
  for(String addr:new String[]{"005080d4","00508180","005068b0","0050fe40","00486980","004867e0","00486810","00487560","00488eb0","00518a60"}) {
   Function f=getFunctionContaining(toAddr(addr));if(f!=null)selected.add(f);
  }
  for(int i=0;i<2;i++) {
   Set<Function> next=new LinkedHashSet<>(selected);
   for(Function f:selected) next.addAll(f.getCallingFunctions(monitor));
   selected=next;
  }
  PrintWriter ix=new PrintWriter(new File(out,"index.txt"));
  for(Function f:selected) {
   ix.println(f.getEntryPoint()+" "+f.getName());
   ix.println("  Calls: "+f.getCalledFunctions(monitor));ix.flush();
   DecompileResults res=d.decompileFunction(f,15,monitor);
   if(res.decompileCompleted()) {
    PrintWriter w=new PrintWriter(new File(out,f.getEntryPoint()+".c"));
    w.println(res.getDecompiledFunction().getC());w.close();
   }
  }
  ix.close();d.dispose();
 }
}
