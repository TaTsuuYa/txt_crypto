@echo off

REM Define variables
set "SCRIPT_DIR=%~dp0"
set "PROGRAM_NAME=crytxt.exe"
set "INSTALL_DIR=C:\Program Files\YourProgram"
set "SOURCE_DIR=%SCRIPT_DIR%..\src"

REM Change to the source directory
cd /d "%SOURCE_DIR%"

REM Compile the program
echo Compiling...
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o "%PROGRAM_NAME%"

REM Check if compilation was successful
if %ERRORLEVEL% equ 0 (
    echo Compilation successful.
    REM Copy the executable to the installation directory
    move /Y "%PROGRAM_NAME%" "%INSTALL_DIR%"
    echo Installation completed.
    REM Delete the source directory
    set /p "answer=Do you want to delete the source directory? (Y/N): "
    if /I "%answer%"=="Y" (
        cd /d "%SCRIPT_DIR%.."
        rd /S /Q "%CD%"
        echo Source directory deleted.
    ) else (
        echo Source directory not deleted.
    )
) else (
    echo Compilation failed. Installation aborted.
)

pause

