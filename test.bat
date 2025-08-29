@echo off
rem ************************************
rem * edit the below lines to          *
rem * corrisponds to your environment  *
rem ************************************

rem ************************************
rem * path to Python use python if     *
rem * python is in your environment    *
rem * variable                         *
rem ************************************
SET PYTHON_PATH=python

rem ************************************
rem * name of the uart send script     *
rem * without the .py extension        *
rem ************************************
SET SEND_UART_SCRIPT=send_uart

rem ************************************
rem * com port to use when sending the *
rem * hyperscan executable             *
rem ************************************
SET COM_PORT=com3

rem ************************************
rem * the path to the hyperscan        *
rem * executable to send               *
rem ************************************
SET HYPERSCAN_EXE_PATH=Debug/Hyper.exe

rem ************************************
rem * WARNING! WARNING! WARNING!       *
rem * DO NOT EDIT BELOW THIS LINE      *
rem *                                  *
rem * if the script isn't working,     *
rem * most likely one of the settings  *
rem * above are incorrect              *
rem ************************************
echo on
%PYTHON_PATH% -m %SEND_UART_SCRIPT% %COM_PORT% %HYPERSCAN_EXE_PATH%