Name "Price"
Caption "���������� Price"
CRCCheck on
;SetCompressor bzip2
InstallColors 000000 FFEBCD
XPStyle on
UninstallText "���������� Price"
ShowInstDetails show
CompletedText "���������!"
OutFile "price_uninst.exe"
;InstallDir $PROGRAMFILES\price

Section ""
MessageBox MB_YESNO "�������� Price?" IDNO NODelete
Delete $PROGRAMFILES\price\*.*
RMDir /r $PROGRAMFILES\price
Delete $SMPROGRAMS\Price\*.*
RMDir $SMPROGRAMS\Price
NoDelete:
SectionEnd
