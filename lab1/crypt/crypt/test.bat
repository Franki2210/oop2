set PROGRAM="%~1"

rem wrong number arguments
%PROGRAM% crypt input.txt output.txt > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt WrongNumberArguments.txt
if ERRORLEVEL 1 goto err

rem check opening a nonexistent file      
%PROGRAM% crypt fail.txt output.txt 42 > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt FailedToOpenForReading.txt
if ERRORLEVEL 1 goto err

rem check opening an empty file          
%PROGRAM% crypt empty.txt output.txt 42 > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt ErrorWithEmptyFile.txt 
if ERRORLEVEL 1 goto err
                              
rem Operation Validation        
%PROGRAM% bombom input.txt output.txt 42 > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt WrongOperation.txt 
if ERRORLEVEL 1 goto err

rem key not a number        
%PROGRAM% crypt input.txt output.txt hi > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt KeyNotANumber.txt 
if ERRORLEVEL 1 goto err

rem successful test          
%PROGRAM% crypt input.txt %TEMP%\outSuccess.txt 42
if ERRORLEVEL 1 goto err
%PROGRAM% decrypt %TEMP%\outSuccess.txt output.txt 42
if ERRORLEVEL 1 goto err
fc.exe output.txt input.txt 
if ERRORLEVEL 1 goto err



echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1