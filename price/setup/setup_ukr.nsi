Name "Price"
;имя инсталлятора
Caption "Встановлення Price"
CRCCheck on
;Этим мы включаем проверку CRC. Если ваш инсталлятор 
;кто-то скачает, и скачанный дистрибутив получится «битый», 
;то благодаря проверке CRC инсталлятор сообщит пользователю, 
;что файл дистрибутива поврежден, и кривые руки не у вас, 
;а просто так получилось. По умолчанию проверка CRC выключена.
XPStyle on
;поддержка интерфейса Windows X
InstallColors 000000 FFEBCD
;Цвета информационного окна, которое отображается, 
;например, когда надо вывести детали о ходе инсталляции.
ShowInstDetails show
;Если включено show, то после установки файлов будет 
;выведена информация, куда и что скопировано.
CompletedText "Виконано!"
;Текст, который сообщит пользователю, что инсталляция 
;выполнена. 
OutFile "price_setup.exe"
;Задает имя файла, в который NSIS запишет получившийся дистрибутив.
InstallDir $PROGRAMFILES\price
;Задает директорию, куда по умолчанию будет установлен ваш 
;продукт. Макрос $PROGRAMFILES указывает на папку Program Files.
UninstallText "Прибирання Price"

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\Price" "Install_Dir"

;Page license
;Страница с лицензией.

;UninstPage uninstConfirm
;UninstPage instfiles

LoadLanguageFile "${NSISDIR}\Contrib\Language files\Ukrainian.nlf"
;Локализация инсталлятора, поддержка украинского языка.

LicenseText "Ліцензійний договір" "Погоджуюсь"
;На соответствующей странице задает надпись над текстом лицензии и 
;надпись на кнопке, нажав на которую, пользователь согласится с лицензией.
LicenseData "d:\Shurik\Program\Turbo_Cpp_10_0\project\WinAPI\price\setup\license.txt"
;имя файла с лицензией.

DirText "Виберіть папку."
ComponentText "Виберіть компоненти для встановлення."

Section "Файли програми"
SetOutPath $INSTDIR
;Устанавливает путь, куда будут скопированы файлы.
;Макрос $INSTDIR — это путь, который выбрал пользователь.
File /r "d:\Shurik\Program\Turbo_Cpp_10_0\project\WinAPI\price\Release_Build\*.*"
;директива File служит для сбора файлов из указанной вами директории 
;в дистрибутив, а параметр /r нужен для рекурсивного прохода по всем 
;субдиректориям этой папки. Таким образом сохраняется вся структура 
;папок вашего продукта.
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\Price "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "DisplayName" "Price"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
SectionEnd

Section "Ярлики в меню Пуск"
CreateDirectory "$SMPROGRAMS\Price"
CreateShortCut "$SMPROGRAMS\Price\Price.lnk" "$INSTDIR\price.exe"
SectionEnd

Section "Ярлики на робочому столі"
CreateShortCut "$DESKTOP\Price.lnk" "$INSTDIR\price.exe"
SectionEnd

Section "Uninstall"
;MessageBox MB_YESNO "Прибрати Price?" IDNO NoDelete
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Price"
  DeleteRegKey HKLM SOFTWARE\Price
Delete $INSTDIR\*.*
;Удаляем все из папки вашего продукта.
RMDir /r $INSTDIR
;Удаляем уже пустую директорию вашей программы.
Delete $SMPROGRAMS\Price\*.*
RMDir $SMPROGRAMS\Price
;Чистим записи о нашей программе в меню Пуск > Программы.
Delete $DESKTOP\Price.lnk
;Удаляем ярлык на десктопе.
;NoDelete:
SectionEnd
