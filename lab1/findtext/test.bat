set PROGRAM="%~1"

rem проверяем поиск в пустом файле
%PROGRAM% empty.txt "you"
if NOT ERRORLEVEL 1 goto err

rem проверяем поиск в одной строке
%PROGRAM% oneline.txt "you" > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt trueResultOneLine.txt
if ERRORLEVEL 1 goto err

rem проверяем поиск в обычном тексте с множеством строк
%PROGRAM% multiline.txt "you" > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt trueResultMultiline.txt
if ERRORLEVEL 1 goto err

rem ожидаем ненулевой код ошибки при поиске в несуществующем файле
%PROGRAM% non-existing-file-name.txt "you" > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt failedOpenText.txt
if ERRORLEVEL 1 goto err

rem проверяем поиск несуществующей строки в файле
%PROGRAM% multiline.txt "hi" > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt notFoundText.txt
if ERRORLEVEL 1 goto err

rem проверка с пустой искомой строкой
%PROGRAM% multiline.txt "" > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt emptyNeedle.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1