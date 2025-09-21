@echo off
g++ -std=c++11 -o atm_system.exe main.cpp src/*.cpp
if %ERRORLEVEL% == 0 (
    echo Build successful!
    atm_system.exe
) else (
    echo Build failed!
    pause
)