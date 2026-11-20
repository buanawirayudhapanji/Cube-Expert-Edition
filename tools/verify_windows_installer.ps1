$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$installer = Get-ChildItem "$root\dist\CubeBabyMOD-*-windows-x64-setup.exe" | Select-Object -First 1
if (-not $installer) { throw 'Installer Windows tidak ditemukan.' }
$installDir = Join-Path $env:RUNNER_TEMP 'CubeBabyMOD-installed-test'
$process = Start-Process -FilePath $installer.FullName -ArgumentList @('/VERYSILENT', '/SUPPRESSMSGBOXES', '/NORESTART', "/DIR=`"$installDir`"") -PassThru -Wait
if ($process.ExitCode -ne 0) { throw "Setup gagal: $($process.ExitCode)" }
$check = "$root\dist\windows-installed-check.json"
$process = Start-Process -FilePath "$installDir\CubeBabyMOD.exe" -ArgumentList @('--self-test', "`"$check`"") -PassThru -Wait
if ($process.ExitCode -ne 0 -or -not (Test-Path $check)) { throw 'Smoke test aplikasi terpasang gagal.' }
$result = Get-Content $check -Raw | ConvertFrom-Json
if (-not $result.ok -or -not $result.frozen) { throw 'Isi hasil smoke test tidak valid.' }
$process = Start-Process -FilePath "$installDir\unins000.exe" -ArgumentList @('/VERYSILENT', '/SUPPRESSMSGBOXES', '/NORESTART') -PassThru -Wait
if ($process.ExitCode -ne 0) { throw 'Uninstall uji gagal.' }
