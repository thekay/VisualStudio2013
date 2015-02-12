#include "TeamSmartDoor.h"

int main(void)
{
	//Declare
	FILE *outfile = NULL, *infile = NULL, *log = NULL;
	IDList *pStart = NULL;
	Boolean isMatch;
	int IDInput = 0, choice = 0;
	char temp[50] = { '\0' };

	//Initialize
	isMatch = FALSE;
	outfile = fopen("authorizedList.dat", "w");
	infile = fopen("list.dat", "r");
	log = fopen("log.dat", "w");
	//printf("Welcome, hit enter to continue\n");
	//Add cards
	while (choice != 1 || choice != 2)
	{
		printf("Get authorize list by\n1. Manually\n2. Import from a file\n>>");
		scanf("%d", &choice);
		if (choice == 1)
		{
			inputManually(infile, outfile, &pStart);
			break;
		}
		else if (choice == 2)
		{
			importAuthorizedList(infile, outfile, &pStart);
			break;
		}
		else
			printf("Unrecognized input,t ry again\n");
	}
	//Output Authorized list


	//Check card, loop until 'q' encounter
	while (1) //isMatch determine if access granted or not
	{
		//Get input as a string
		printf("Scan card(q to exit): ");
		gets(temp);
		if (temp[0] == 'q')
			break;
		scanIDButton(&IDInput, temp);
		if (searchID(pStart, IDInput))
		{
			isMatch = TRUE;
			fprintf(log, "ID: %d authorized\n", IDInput);
		
		}
		else
		{
			printf("Unauthorized\n\n");
			fprintf(log, "ID: %d un-authorized\n", IDInput);
		}

		
		doorLock(isMatch);

	}
	printf("Goodbye!\n");

	fclose(outfile);
	fclose(infile);
	fclose(log);


	//This is not our work, this is open source from David Johns and John Tang - SMTP Client with SSL/TLS
	//sendEmail();
	(void)system("C:\\Users\\long\\Desktop\\Hackathon\\SmartDoor\\sendmail\\Debug\\CSmtp.exe \"subject2\" \"shane.wilhelm@mailinator.com\" \"message\"");
	return 0;
}