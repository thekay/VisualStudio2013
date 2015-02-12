#include "TeamSmartDoor.h"

//this function will call stringEliminate function
//These 2 function job: Change weird string input to int id
void scanIDButton(int *output, char *input)
{
	int ID = 0;
	//Eliminate any start, and eleminate 0's
	StringEliminate(input, &ID);
	*output = ID;

}

void StringEliminate(char *input, int *output)
{
	char temp[13] = { '\0' };
	int counter = 0, index  = 0;
	//First go through the string and eliminate the *'s
	while (input[counter] != '\0')
	{
		if (input[counter] == '*')
		{
			input[counter] = '-';
		}
		else
			counter++;
		
	}
	
	//clean up the string
	counter = 0;
	index = 0;
	while (input[counter] != '\0')
	{
		if (input[counter] != '-')
		{
			temp[index++] = input[counter];
		}
		counter++;
	}

	//eliminate all the front 0's
	counter = 0;
	index = 0;
	//First clear input
	input[strlen(temp)] = '\0';

	//Eliminate the front 0's
	while (temp[counter] == '0')
	{
		counter++;
	}

	//Copy cleaned string to input
	index = 0;
	while (temp[counter] != '\0')
	{
		input[index++] = temp[counter++];
	}
	input[index] = '\0';
	counter = index - 1
		;

	//Change from string to int
	*output = 0;
	for (index = 0;(unsigned int) index < strlen(input); index++)
	{
		*output = (*output) + ((((int)input[index]) - 48) * (int) pow(10, counter) );
		counter--;
	}

	//2050009

}

//Linked list, store arthorized ID
void AddID(IDList **pStart, int IDNumber, char *name)
{
	IDList *pMem = NULL;
	int temp = 0;


	pMem = makeNode(IDNumber, name);

	//Insert into the list, using insert at front
	if (*pStart == NULL)
	{
		*pStart = pMem;
	}
	else
	{
		pMem->pNext = *pStart;
		*pStart = pMem;

	}
}
//This function create a storage for AddID to store informations
IDList *makeNode(int IDNumber, char *name)
{
	IDList *temp = NULL;
	//int IDNumber = 0;
	//char name[50] = { '\0' };
	
	//Allocate memory
	temp = (IDList *)malloc(sizeof(IDList));
	temp->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(temp->name, name);
	temp->idNumber = IDNumber;
	temp->pNext = NULL;
	return temp;

}

//This function search in the linkedlist to see if the input ID is there or not and return 1 if found, otherwise, 0
int searchID(IDList *pStart, int IDNumber)
{
	while (pStart != NULL)
	{
		if (pStart->idNumber == IDNumber)
		{
			printf("%s, Authorized\n\n", pStart->name);
			return 1;
		}
		pStart = pStart->pNext;

	}
	
	return FALSE;
}

//Just clear a string for re-use
void clearString(char *string, int length)
{
	int counter = 0;
	while (counter < length)
	{
		string[counter++] = '\0';
	}
}

//You guys are doing this
void doorLock(Boolean isAuthorized)
{
	if (isAuthorized == TRUE) // Access granted
	{
		//if door open continue
		//else open door
	}
	else
	{
		//if door open, lock it
		//else continue
	}
}

//Output Authorized IDs to a file
void exportAuthorizedList(FILE *outfile, char *name, int IDNumber)
{
	fprintf(outfile, "%s\n%d\n\n", name, IDNumber);
}

//Pre-condition appropriate format
//Read authorized IDs and names from a file 
void importAuthorizedList(FILE *infile, FILE *outfile, IDList **pStart)
{
	char temp[50] = { '\0' };
	int IDInput = 0, temp1 = 0;
	
	//Get name
	while (!feof(infile))
	{
		fgets(temp, 50, infile);
		temp1 = strlen(temp) - 1;
		temp[temp1] = '\0';

		//Get ID#
		fscanf(infile, "%d", &IDInput);


		//Insert to linkedlist
		AddID(pStart, IDInput, temp);

		//Output to a file
		exportAuthorizedList(outfile, temp, IDInput);

		//Clear out the 2 newline
		fgets(temp, 1, infile);
		fgets(temp, 2, infile);
		fgets(temp, 3, infile);
		//Clear string in case the next value shorter than the previous
		clearString(temp, strlen(temp));
		//clearString(name, strlen(name));
	}
	getchar();
}

//This function allow we to input name and ID manually
void inputManually(FILE *infile, FILE *outfile, IDList **pStart)
{
	char name[50] = { '\0' }, temp[50] = { '\0' };
	int IDInput = 0;
	getchar();
	do
	{
		//Get name
		
		printf("Enter your name (enter q to quit): ");
		//getchar();
		gets(name);
		if (name[0] == 'q')
			break;

		//Get ID#
		printf("ID number: ");
		gets(temp);
		//Change ID number from string to int
		scanIDButton(&IDInput, temp);

		//Insert to linkedlist
		AddID(pStart, IDInput, name);

		//Output to a file
		exportAuthorizedList(outfile, name, IDInput);

		//Clear string in case the next value shorter than the previous
		clearString(temp, strlen(temp));
		clearString(name, strlen(name));
		printf("\n");

	} while (1);
}

//This one is no use, disgard it
void sendEmail(void)
{
	FILE *output = NULL;
	int choice = 0;
	char temp[100] = { '\0' };
	output = fopen("information.txt", "w");
	printf("Choose a option\n1. Send default message\n2. Custom message\n>>");
	scanf("%d", &choice);
	if (choice == 1)
	{
		fprintf(output, "Warning message\nthuanduongpawtucket@gmail.com\nSomeone approaching your door, becareful\n");
	}
	else if (choice == 2)
	{
		getchar();
		printf("Subject: ");
		gets(temp);
		fprintf(output, "%s\n", temp);
		clearString(temp, strlen(temp));

		printf("Email: ");
		gets(temp);
		fprintf(output, "%s\n", temp);
		clearString(temp, strlen(temp));

		printf("Message: ");
		gets(temp);
		fprintf(output, "%s\n", temp);
		clearString(temp, strlen(temp));
	}
	else
		printf("unrecognized input\n");
	fclose(output);
}