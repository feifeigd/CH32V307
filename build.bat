@echo off

cmake -H. -B_builds  -G "NMake Makefiles" .
if %errorlevel% NEQ 0 goto error

cmake --build _builds --config Release -j 8
if %errorlevel% NEQ 0 goto error

cmake --build _builds --config Debug -j 8
if %errorlevel% NEQ 0 goto error


:: test
::pushd _builds && ctest -C Debug -VV
ctest  --test-dir _builds -C Debug -VV 
if %errorlevel% NEQ 0 goto error
::popd

:: install
cmake --install _builds
if %errorlevel% NEQ 0 goto error

:: 打开 sln
:: cmake --open _builds

goto :EOF

:error
pause
