set PROGRAM="%~1"

rem �������� ����������� ������������ ������
%PROGRAM% matrix1.txt matrix2.txt > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt trueResult.txt
if ERRORLEVEL 1 goto err

rem �������� � ������ ������
%PROGRAM% emptyFile.txt matrix2.txt %TEMP%\resultMatrix.txt
if NOT ERRORLEVEL 1 goto err

rem �������� �� ������������ ���-�� ����������
%PROGRAM% matrix1.txt
if NOT ERRORLEVEL 1 goto err

rem �������� � ������� ��������� ��������
%PROGRAM% matrix1.txt invalidMatrix1.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt invalidMatrix2.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1