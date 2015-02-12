#include "CSmtp.h"
#include <iostream>

void printInstructions()
{
	cout << "Invalid command line args. " << endl << "Usage: CSmtp.exe <subject> <recipient> <message> <optional:attachment_path>" << endl;
}

//Args <subject> <recipient> <message> (Max length 10000 chars)
int main(int argc, char *argv[])
{
	if (argc < 4)
	{ //numArguments check
		printInstructions();
		return 1;
	}

	if (sizeof(argv[1]) > 10000 || sizeof(argv[2]) > 10000 || sizeof(argv[3]) > 10000)
	{ //max argument length check
		printInstructions();
		return 1;
	}

	FILE *infile = NULL;00*0*1604988*
		00*0*1604988*

	char temp[10000] = { '\0' }, *recipient, *subject, *message1;
	//Read in information
	infile = fopen("information.txt", "r");

	//Subject
	//fgets(temp, 100, infile);
	subject = (char *)malloc(sizeof(char)*(strlen(argv[1]) + 1));
	strcpy(subject, argv[1]);
	//clearString(temp, strlen(temp));
	//subject[strlen(subject) - 1] = '\0';

	//Recipient
	//fgets(temp, 100, infile);
	recipient = (char *)malloc(sizeof(char)*(strlen(argv[2]) + 1));
	strcpy(recipient, argv[2]);
	//clearString(temp, strlen(temp));
	//recipient[strlen(recipient) - 1] = '\0';

	//Message
	//fgets(temp, 100, infile);
	message1 = (char *)malloc(sizeof(char)*(strlen(argv[3]) + 1));
	strcpy(message1, argv[3]);
	//clearString(temp, strlen(temp));
	//message1[strlen(message1) - 1] = '\0';

	bool bError = false;

	try
	{
		CSmtp mail;

#define test_gmail_tls

#if defined(test_gmail_tls)
		mail.SetSMTPServer("smtp.gmail.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_gmail_ssl)
		mail.SetSMTPServer("smtp.gmail.com",465);
		mail.SetSecurityType(USE_SSL);
#elif defined(test_hotmail_TLS)
		mail.SetSMTPServer("smtp.live.com",25);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_aol_tls)
		mail.SetSMTPServer("smtp.aol.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_yahoo_ssl)
		mail.SetSMTPServer("plus.smtp.mail.yahoo.com",465);
		mail.SetSecurityType(USE_SSL);
#endif

		mail.SetLogin("teamsmartdoor@gmail.com");
		mail.SetPassword("teamsmartdoor123");
  		mail.SetSenderName("User");
  		mail.SetSenderMail("teamsmartdoor@gmail.com");
  		mail.SetReplyTo("teamsmartdoor@gmail.com");
  		mail.SetSubject(subject);
  		mail.AddRecipient(recipient);
  		mail.SetXPriority(XPRIORITY_NORMAL);
  		mail.SetXMailer("The Bat! (v3.02) Professional");
  		mail.AddMsgLine(" ");
		mail.AddMsgLine(message1);
		mail.AddMsgLine(" ");
		mail.AddMsgLine("Take care!");
		mail.AddMsgLine("");
		mail.AddMsgLine("Regards");
		mail.ModMsgLine(5,"regards");
		mail.DelMsgLine(2);
		mail.AddMsgLine("Team Smart Door");

		if (sizeof(argv[4]) != 0)
		{
			mail.AddAttachment(argv[4]);
		}
  		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
	}
	catch(ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if(!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}
