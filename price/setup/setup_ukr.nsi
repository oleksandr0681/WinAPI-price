Name "Price"
;��� ������������
Caption "������������ Price"
CRCCheck on
;���� �� �������� �������� CRC. ���� ��� ����������� 
;���-�� �������, � ��������� ����������� ��������� ������, 
;�� ��������� �������� CRC ����������� ������� ������������, 
;��� ���� ������������ ���������, � ������ ���� �� � ���, 
;� ������ ��� ����������. �� ��������� �������� CRC ���������.
XPStyle on
;��������� ���������� Windows X
InstallColors 000000 FFEBCD
;����� ��������������� ����, ������� ������������, 
;��������, ����� ���� ������� ������ � ���� �����������.
ShowInstDetails show
;���� �������� show, �� ����� ��������� ������ ����� 
;�������� ����������, ���� � ��� �����������.
CompletedText "��������!"
;�����, ������� ������� ������������, ��� ����������� 
;���������. 
OutFile "price_setup.exe"
;������ ��� �����, � ������� NSIS ������� ������������ �����������.
InstallDir $PROGRAMFILES\price
;������ ����������, ���� �� ��������� ����� ���������� ��� 
;�������. ������ $PROGRAMFILES ��������� �� ����� Program Files.
UninstallText "���������� Price"

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\Price" "Install_Dir"

;Page license
;�������� � ���������.

;UninstPage uninstConfirm
;UninstPage instfiles

LoadLanguageFile "${NSISDIR}\Contrib\Language files\Ukrainian.nlf"
;����������� ������������, ��������� ����������� �����.

LicenseText "˳�������� ������" "����������"
;�� ��������������� �������� ������ ������� ��� ������� �������� � 
;������� �� ������, ����� �� �������, ������������ ���������� � ���������.
LicenseData "d:\Shurik\Program\Turbo_Cpp_10_0\project\WinAPI\price\setup\license.txt"
;��� ����� � ���������.

DirText "������� �����."
ComponentText "������� ���������� ��� ������������."

Section "����� ��������"
SetOutPath $INSTDIR
;������������� ����, ���� ����� ����������� �����.
;������ $INSTDIR � ��� ����, ������� ������ ������������.
File /r "d:\Shurik\Program\Turbo_Cpp_10_0\project\WinAPI\price\Release_Build\*.*"
;��������� File ������ ��� ����� ������ �� ��������� ���� ���������� 
;� �����������, � �������� /r ����� ��� ������������ ������� �� ���� 
;�������������� ���� �����. ����� ������� ����������� ��� ��������� 
;����� ������ ��������.
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\Price "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "DisplayName" "Price"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
SectionEnd

Section "������ � ���� ����"
CreateDirectory "$SMPROGRAMS\Price"
CreateShortCut "$SMPROGRAMS\Price\Price.lnk" "$INSTDIR\price.exe"
SectionEnd

Section "������ �� �������� ����"
CreateShortCut "$DESKTOP\Price.lnk" "$INSTDIR\price.exe"
SectionEnd

Section "Uninstall"
;MessageBox MB_YESNO "�������� Price?" IDNO NoDelete
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price"
  DeleteRegKey HKLM SOFTWARE\Price
Delete $INSTDIR\*.*
;������� ��� �� ����� ������ ��������.
RMDir /r $INSTDIR
;������� ��� ������ ���������� ����� ���������.
Delete $SMPROGRAMS\Price\*.*
RMDir $SMPROGRAMS\Price
;������ ������ � ����� ��������� � ���� ���� > ���������.
Delete $DESKTOP\Price.lnk
;������� ����� �� ��������.
;NoDelete:
SectionEnd
