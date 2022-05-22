@echo off
for /l %%i in (1, 1, 100) do (
	gentest.exe %%i
	sol1.exe
	sol2.exe
	fc sol1.out sol2.out
	if errorlevel 1 goto :eof
	echo Test %%i correct
)
