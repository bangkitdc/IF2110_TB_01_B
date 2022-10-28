@echo off
if "%~1" == "clean" (
    goto CLEAN
) else (
    goto MAIN
)

:CLEAN
echo:
echo Deleting old compiled files . . .
echo:
@rd /s /q build
echo Done!
goto END

:MAIN
echo:
echo Building Makefile . . .
echo:
@cmake.exe -G "MinGW Makefiles" -H. -B./build
echo:
echo Running Make . . .
echo:
cd build
@mingw32-make
goto RUN

:RUN
pause
echo:
echo Running Program...
echo:
cd bin
@main.exe
cd ../..

:END
