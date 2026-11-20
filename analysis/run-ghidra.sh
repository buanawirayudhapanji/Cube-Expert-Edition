#!/usr/bin/env bash
set -euo pipefail
project_root="$(cd "$(dirname "$0")/.." && pwd)"
analysis_dir="$(mktemp -d /tmp/cubebaby-ghidra.XXXXXX)"
mkdir -p "$analysis_dir/input" "$analysis_dir/projects" "$analysis_dir/preferences" "$analysis_dir/output"
cp "$project_root/CubeSuite/CubeSuite.exe" "$analysis_dir/input/"
if [[ "${1:-}" == "--full" ]]; then
  script_args=(-postScript FocusProtocol.java "$analysis_dir/output/protocol"
               -postScript ExportMidi.java "$analysis_dir/output/context")
else
  script_args=(-noanalysis -postScript QuickProtocol.java "$analysis_dir/output/protocol")
fi
# Isolate input to avoid looking for dependent DLLs; keep user configuration untouched.
JAVA_TOOL_OPTIONS="${JAVA_TOOL_OPTIONS:-} -Duser.home=$analysis_dir/preferences" \
/opt/ghidra/support/analyzeHeadless "$analysis_dir/projects" CubeSuite \
  -import "$analysis_dir/input/CubeSuite.exe" \
  -loader-loadLibraries false -librarySearchPaths "$analysis_dir/input" \
  -scriptPath "$project_root/analysis/scripts" \
  "${script_args[@]}" \
  -postScript ReadSettings.java "$analysis_dir/output/settings" \
  -postScript Cube20230.java "$analysis_dir/output/model20230" \
  -postScript CubeJun.java "$analysis_dir/output/modeljun" \
  -postScript WriteIR.java "$analysis_dir/output/write" -max-cpu 4
printf 'Hasil analisis: %s\n' "$analysis_dir"
