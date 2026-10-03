@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release