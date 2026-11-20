// @category CubeBaby
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;
public class ExportMidi extends GhidraScript {
 public void run() throws Exception {
  File out = new File(getScriptArgs()[0]); out.mkdirs();
  DecompInterface d = new DecompInterface(); d.openProgram(currentProgram);
  Set<Function> selected = new LinkedHashSet<>();
  PrintWriter ix = new PrintWriter(new File(out,"index.txt"));
  DataIterator it = currentProgram.getListing().getDefinedData(true);
  while(it.hasNext()) {
   Data data=it.next(); Object val=data.getValue();
   if(!(val instanceof String)) continue;
   String s=(String)val;
   if(s.matches("(?is).*(CubeBaby|Cube Baby|RtMidi|sysex|IREdit|connect.*device|device.*connect).*") && s.length()<700) {
    ix.println(data.getAddress()+" "+s);
    for(Reference r:getReferencesTo(data.getAddress())) {
     Function f=getFunctionContaining(r.getFromAddress());
     ix.println("  ref "+r.getFromAddress()+" fn "+f);
     if(f!=null) selected.add(f);
    }
   }
  }
  // Include immediate callers and callees; protocol-specific traversal is separate.
  for(int depth=0;depth<1;depth++) {
   Set<Function> next=new LinkedHashSet<>(selected);
   for(Function f:selected) { next.addAll(f.getCallingFunctions(monitor)); next.addAll(f.getCalledFunctions(monitor)); }
   selected=next;
  }
  for(Function f:selected) {
   if(f.isExternal()||f.isThunk()) continue;
   ix.println("EXPORT "+f.getEntryPoint()+" "+f.getName()); ix.flush();
   DecompileResults res=d.decompileFunction(f,15,monitor);
   if(res.decompileCompleted()) {
    PrintWriter w=new PrintWriter(new File(out,f.getEntryPoint()+".c"));
    w.println(res.getDecompiledFunction().getC()); w.close();
   }
  }
  ix.close();d.dispose();
 }
}
