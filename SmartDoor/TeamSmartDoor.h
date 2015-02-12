#define _CRT_SECURE_NO_WARNINGS
#ifndef TeamSmartDoor
#define TeamSmartDoor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
//True or False value
typedef enum boolean
{
	FALSE, TRUE
}Boolean;
typedef struct idlist
{
	int idNumber;
	char *name;
	struct idlist *pNext;

}IDList;
void scanIDButton(int *output, char *input);
void StringEliminate(char *input, int *output);
void AddID(IDList **pStart, int IDNumber, char *name);
IDList *makeNode(int IDNumber, char *name);
int searchID(IDList *pStart, int IDNumber);
void clearString(char *string, int length);
void doorLock(Boolean isAuthorized);
void exportAuthorizedList(FILE *outfile, char *name, int IDNumber);
void inputManually(FILE *infile, FILE *outfile, IDList **pStart);
void importAuthorizedList(FILE *infile, FILE *outfile, IDList **pStart);
int sendmail(const char *to, const char *from, const char *subject, const char *message);
void sendEmail(void);
#endif 