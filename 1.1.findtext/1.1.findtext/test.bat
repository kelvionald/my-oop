set PROGRAM="%~1"

rem ��� ������� ��� ����������
%PROGRAM% > nul && goto err
echo Test 1 passed

rem ��� ������� � 1 ����������
%PROGRAM% "test-data/Input.txt" > nul && goto err
echo Test 2 passed

rem ��� ������ notSet ��� 0
%PROGRAM% "test-data/Input.txt" "notSet" && goto err
echo Test 3 passed

rem ��� ������ line ������� 2 ������ ����������
%PROGRAM% "test-data/Input.txt" "text" > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputSearchText.txt" > nul || goto err
echo Test 4 passed

rem ��� ������ line ������� 1 ������ ����������
%PROGRAM% "test-data/Input.txt" "line" > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputSearchLine.txt" > nul || goto err
echo Test 5 passed

rem ��� ������ Some ������� 1 ������ ����������
%PROGRAM% "test-data/Input.txt" "Some" > "%TEMP%\Output.txt" || goto err
fc.exe "%TEMP%\Output.txt" "test-data/OutputSearchSome.txt" > nul || goto err
echo Test 6 passed

rem ��� ������� �� �� ������������ �����
%PROGRAM% "test-data/MissingFile.txt" "Some" > "%TEMP%\Output.txt" && goto err
echo Test 7 passed

echo OK
exit 0

:err
echo Program testing failed
exit 1