; -- CodeClasses.iss --
;
; This script shows how to use the WizardForm object and the various VCL classes.

[Code]

function GetNumber(var temp: String): Integer;
var
  part: String;
  pos1: Integer;
begin
  if Length(temp) = 0 then
  begin
    Result := -1;
    Exit;
  end;
    pos1 := Pos('.', temp);
    if (pos1 = 0) then
    begin
      Result := StrToInt(temp);
    temp := '';
    end
    else
    begin
    part := Copy(temp, 1, pos1 - 1);
      temp := Copy(temp, pos1 + 1, Length(temp));
      Result := StrToInt(part);
    end;
end;
 
function CompareInner(var temp1, temp2: String): Integer;
var
  num1, num2: Integer;
begin
    num1 := GetNumber(temp1);
  num2 := GetNumber(temp2);
  if (num1 = -1) or (num2 = -1) then
  begin
    Result := 0;
    Exit;
  end;
      if (num1 > num2) then
      begin
        Result := 1;
      end
      else if (num1 < num2) then
      begin
        Result := -1;
      end
      else
      begin
        Result := CompareInner(temp1, temp2);
      end;
end;
 
function CompareVersion(str1, str2: String): Integer;
var
  temp1, temp2: String;
begin
    temp1 := str1;
    temp2 := str2;
    Result := CompareInner(temp1, temp2);
end;

function InitializeSetup(): Boolean;
var
  oldVersion: String;
  uninstaller: String;
  ErrorCode: Integer;
begin
  if RegKeyExists(HKEY_LOCAL_MACHINE,
    'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\2E932F68-C276-487A-BB81-8FC1863AC211') then
  begin
    RegQueryStringValue(HKEY_LOCAL_MACHINE,
      'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\2E932F68-C276-487A-BB81-8FC1863AC211',
      'DisplayVersion', oldVersion);
    if (CompareVersion(oldVersion, '2.0.0.0001') < 0) then
    begin
      if MsgBox('Version ' + oldVersion + ' 已经安装，继续使用？',
        mbConfirmation, MB_YESNO) = IDYES then
      begin
        Result := False;
      end
      else
      begin
          RegQueryStringValue(HKEY_LOCAL_MACHINE,
            'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\2E932F68-C276-487A-BB81-8FC1863AC211',
            'UninstallString', uninstaller);
          ShellExec('runas', uninstaller, '/SILENT', '', SW_HIDE, ewWaitUntilTerminated, ErrorCode);
          Result := True;
      end;
    end
    else
    begin
      MsgBox('Version ' + oldVersion + ' 已经安装.',
        mbInformation, MB_OK);
      Result := False;
    end;
  end
  else
  begin
    Result := True;
  end;
end;

