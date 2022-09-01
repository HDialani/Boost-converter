
cd .

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2020b\bin\win64\gmake"  -B DEPRULES=0 -j5  -f Openloop_voltage_control.mk all) else ("C:\PROGRA~1\MATLAB\R2020b\bin\win64\gmake"  -B DEPRULES=0 -j5  -f Openloop_voltage_control.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1