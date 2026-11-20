#ifndef AppVersion
  #define AppVersion "0.1.0"
#endif
[Setup]
AppId={{6EF0D5C2-785D-40B8-B427-3654DD164E2E}
AppName=CubeBabyMOD
AppVersion={#AppVersion}
AppPublisher=CubeBabyMOD
DefaultDirName={localappdata}\Programs\CubeBabyMOD
DefaultGroupName=CubeBabyMOD
PrivilegesRequired=lowest
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible
MinVersion=10.0
OutputDir={#OutputDir}
OutputBaseFilename=CubeBabyMOD-{#AppVersion}-windows-x64-setup
SetupIconFile={#IconFile}
UninstallDisplayIcon={app}\CubeBabyMOD.exe
Compression=lzma2
SolidCompression=yes
WizardStyle=modern
CloseApplications=yes
RestartApplications=no

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Buat pintasan di desktop"; Flags: unchecked

[Files]
Source: "{#BundleDir}\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\CubeBabyMOD"; Filename: "{app}\CubeBabyMOD.exe"
Name: "{group}\Hapus CubeBabyMOD"; Filename: "{uninstallexe}"
Name: "{autodesktop}\CubeBabyMOD"; Filename: "{app}\CubeBabyMOD.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\CubeBabyMOD.exe"; Description: "Buka CubeBabyMOD"; Flags: nowait postinstall skipifsilent
