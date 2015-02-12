#include "header.h"
/*
-	I am able to code the save and load progress. (extra credit)
	
-	The problem of a level become harder when the user answer right 5 times in that level.
	To make it harder, I double the number.

-	Statistic can be seen at record.dat
-	Con: I can't figure how to truly random the mathematical operators.
	//test	 

*/
int main (void)
{
	int temp = 0, counter = 0;
	FILE *save = NULL, *record = NULL;
	info player, *ptr;
	save = fopen("save.dat", "r");
	record = fopen ("record.dat", "w");
	ptr = &player;
	initializer(ptr);
	srand((signed int) time(NULL));

	while (temp != 1 && temp != 2)
	{
		printf("What do you want to do?\n1. Load previous progress\n2. Start new game\n>> ");
		scanf("%d", &temp);
		if (temp == 1)
		{
			load_previous_progress(save, ptr);
		}
		else if ( temp == 2)
		{
			initializer(ptr);
		}
		else
			printf("invalid input please try again");
	}
	system("cls");

	user_interface (ptr, save);
	save_progress(record, ptr);
	fclose (record);
	fclose (save);
	return 0;
}