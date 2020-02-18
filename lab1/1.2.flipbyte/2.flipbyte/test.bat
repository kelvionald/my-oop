set PROGRAM="%~1"

rem ��� ����������
%PROGRAM% > nul && goto err
echo Test 1 passed

rem ����� ������ ��� 1 ����
%PROGRAM% 1234 > nul && goto err
echo Test 2 passed

rem �� �����
%PROGRAM% abcd > nul && goto err
echo Test 3 passed

rem ��������� ����� 1 �����
%PROGRAM% 256 > nul && goto err
echo Test 4 passed

rem ����� 6 �� �������
%PROGRAM% 6 > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputForSix.txt" > nul || goto err
echo Test 5 passed

rem ����� 0
%PROGRAM% 0 > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputForZero.txt" > nul || goto err
echo Test 6 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1