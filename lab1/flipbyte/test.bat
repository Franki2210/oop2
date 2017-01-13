set PROGRAM="%~1"

rem проверка правильного введенного числа
%PROGRAM% 6 > %TEMP%\output
fc.exe %TEMP%\output trueResult.txt
if ERRORLEVEL 1 goto err

rem проверка на число за пределами 0..255
%PROGRAM% 266 > %TEMP%\output
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output beyond.txt
if ERRORLEVEL 1 goto err

rem проверка с нулём
%PROGRAM% 0 > %TEMP%\output
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output trueResultZero.txt
if ERRORLEVEL 1 goto err

rem проверка на число на границе 0..255
%PROGRAM% 255
if ERRORLEVEL 1 goto err

rem проверка на неверные данные
%PROGRAM% aa
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1