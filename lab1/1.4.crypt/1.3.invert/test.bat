set PROGRAM="%~1"

rem ��� ����������
%PROGRAM% > nul && goto err
echo Test 1 passed

rem �������������� ����
%PROGRAM% crypt "test-data/NoExist.txt" "%TEMP%\Output.txt" 1 > nul && goto err
echo Test 2 passed

rem ������������� ����
%PROGRAM% crypt "test-data/NoExist.txt" "%TEMP%\Output.txt" -1 > nul && goto err
echo Test 3 passed

rem ������� ������� ����
%PROGRAM% crypt "test-data/NoExist.txt" "%TEMP%\Output.txt" 256 > nul && goto err
echo Test 4 passed

rem ������ ����
%PROGRAM% crypt "test-data/Empty.txt" "%TEMP%\Output.txt" 1 || goto err
rem fc.exe "%TEMP%\Output.txt" "test-data/Empty.txt" > nul || goto err
echo Test 5 passed

rem ���������� ������� � ������ 10
%PROGRAM% crypt "test-data/Input3.txt" "%TEMP%\Output.txt" 10 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/Output3-10.txt" > nul || goto err
echo Test 6 passed

rem ���������� ������� � ������ 11
%PROGRAM% crypt "test-data/Input3.txt" "%TEMP%\Output.txt" 11 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/Output3-11.txt" > nul || goto err
echo Test 7 passed

rem ������������ ������� � ������ 10
%PROGRAM% decrypt "test-data/Output3-10.txt" "%TEMP%\Output.txt" 10 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/Input3.txt" > nul || goto err
echo Test 8 passed

rem ���������� ������ � ������ 33
%PROGRAM% crypt "test-data/InputText.txt" "%TEMP%\Output.txt" 33 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputText.txt" > nul || goto err
echo Test 9 passed

rem ������������ ������ � ������ 33
%PROGRAM% decrypt "test-data/OutputText.txt" "%TEMP%\Output.txt" 33 || goto err
fc.exe "%TEMP%\Output.txt" "test-data/InputText.txt" > nul || goto err
echo Test 10 passed

rem ������������ �����
%PROGRAM% noncrypt "" "" 1 > nul && goto err
echo Test 11 passed

rem ������ ��� �������� �����
%PROGRAM% crypt "" "" 1 > nul && goto err
echo Test 12 passed

rem ������ ��� ��������� �����
%PROGRAM% crypt "1" "" 1 > nul && goto err
echo Test 13 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1