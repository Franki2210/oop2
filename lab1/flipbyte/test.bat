set PROGRAM="%~1"

rem �������� ����������� ���������� �����
%PROGRAM% 6 > %TEMP%\output
fc.exe %TEMP%\output trueResult.txt
if ERRORLEVEL 1 goto err

rem �������� �� ����� �� ��������� 0..255
%PROGRAM% 266 > %TEMP%\output
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output beyond.txt
if ERRORLEVEL 1 goto err

rem �������� � ����
%PROGRAM% 0 > %TEMP%\output
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output trueResultZero.txt
if ERRORLEVEL 1 goto err

rem �������� �� ����� �� ������� 0..255
%PROGRAM% 255
if ERRORLEVEL 1 goto err

rem �������� �� �������� ������
%PROGRAM% aa
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1