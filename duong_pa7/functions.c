#include "header.h"

void user_interface (info *ptr, FILE *save)
{

	while (ptr->choice != 6)
	{
		int temp = 0;
		printf("What you want to do?\n");
		printf("1. Learn about how to use the program\n");
		printf("2. Enter your initials (3 individual characters)\n");
		printf("3. Difficulty selection\n");
		printf("4. Start a new sequence of problems\n");
		printf("5. Load previous process (All current progress will be lost)\n");
		printf("6. Save and quit\n");
		ptr->choice = input_and_check ();
		system("cls"); 
		if (ptr->choice == 1)
		{
			printf("The menu will open everytime you finished a level. Choose 4 to practice \nanother problem as the same level but different numbers, or choose 3 to select \nother levels. If you wish to save and quit, choose 6. And choose 5 to load \nprevious progress\n\n");
		}
		else if (ptr->choice == 2)
		{
			printf("Enter your initials (3 individual characters only): ");
			scanf("%s", &(ptr->initial));
		}
		else if (ptr->choice == 3)
		{
			//choose the difficulty level
			difficulty_print();
			printf("Please choose your level of difficulty (number from 1 to 5): ");
			scanf("%d",&(ptr->level));
			math(ptr);
		}
		else if (ptr->choice == 4)
		{
			//redo the last level
			if ( ptr->level != 0 && ptr->level <= 5)
				math(ptr);
			else
				printf("It appears that you never save the game before, that's why I don't know your \nprevious level.\n");
		}
		else if (ptr->choice == 5)
		{
			load_previous_progress (save, ptr);
			//printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%s\n",ptr->lvl1.correct, ptr->lvl1.incorrect, ptr->lvl2.correct, ptr->lvl2.incorrect, ptr->lvl3.correct, ptr->lvl3.incorrect, ptr->lvl4.correct, ptr->lvl4.incorrect, ptr->lvl5.correct, ptr->lvl5.incorrect, ptr->initial);

		}
		else
		{
			//save the game and quit
			fclose (save);
			save = fopen ("save.dat", "w");
			savefile (save, ptr);
		}
	}
	

}

int input_and_check (void)
{
	int input = 0;
	while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)
	{
		scanf("%d", &input);
		if (input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6)
		{
			return input;
		}
		else
		{
			printf("Invalid input, please try again\n");
		}
	}
	return 0;
}

void load_previous_progress (FILE *save, info *ptr)
{
	fscanf(save, "%d", &(ptr->lvl1.correct));
	fscanf(save, "%d", &(ptr->lvl1.incorrect));
	fscanf(save, "%d", &(ptr->lvl2.correct));
	fscanf(save, "%d", &(ptr->lvl2.incorrect));
	fscanf(save, "%d", &(ptr->lvl3.correct));
	fscanf(save, "%d", &(ptr->lvl3.incorrect));
	fscanf(save, "%d", &(ptr->lvl4.correct));
	fscanf(save, "%d", &(ptr->lvl4.incorrect));
	fscanf(save, "%d", &(ptr->lvl5.correct));
	fscanf(save, "%d", &(ptr->lvl5.incorrect));
	fscanf(save, "%d", &(ptr->level));
	fscanf(save, "%s", &(ptr->initial));

}

void save_progress (FILE *save, info *ptr)
{
	fprintf(save, "%d\t//Level 1 # of correct answer\n", (ptr->lvl1.correct));
	fprintf(save, "%d\t//Level 1 # of incorrect answer\n", (ptr->lvl1.incorrect));
	fprintf(save, "%d\t//Level 2 # of correct answer\n", (ptr->lvl2.correct));
	fprintf(save, "%d\t//Level 2 # of incorrect answer\n", (ptr->lvl2.incorrect));
	fprintf(save, "%d\t//Level 3 # of correct answer\n", (ptr->lvl3.correct));
	fprintf(save, "%d\t//Level 3 # of incorrect answer\n", (ptr->lvl3.incorrect));
	fprintf(save, "%d\t//Level 4 # of correct answer\n", (ptr->lvl4.correct));
	fprintf(save, "%d\t//Level 4 # of incorrect answer\n", (ptr->lvl4.incorrect));
	fprintf(save, "%d\t//Level 5 # of correct answer\n", (ptr->lvl5.correct));
	fprintf(save, "%d\t//Level 5 # of incorrect answer\n", (ptr->lvl5.incorrect));
	fprintf(save, "%d\t //Current level\n", ptr->level);
	fprintf(save, "%s\t//Initial of the user\n", (ptr->initial));
	
}
void savefile (FILE *save, info *ptr)
{
	fprintf(save, "%d\n", (ptr->lvl1.correct));
	fprintf(save, "%d\n", (ptr->lvl1.incorrect));
	fprintf(save, "%d\n", (ptr->lvl2.correct));
	fprintf(save, "%d\n", (ptr->lvl2.incorrect));
	fprintf(save, "%d\n", (ptr->lvl3.correct));
	fprintf(save, "%d\n", (ptr->lvl3.incorrect));
	fprintf(save, "%d\n", (ptr->lvl4.correct));
	fprintf(save, "%d\n", (ptr->lvl4.incorrect));
	fprintf(save, "%d\n", (ptr->lvl5.correct));
	fprintf(save, "%d\n", (ptr->lvl5.incorrect));
	fprintf(save, "%d\n", ptr->level);
	fprintf(save, "%s\n", (ptr->initial));
}

void difficulty_print (void)
{
	printf("Level 1 - Easy: Includes addition and subtraction problems, with positive single digit\nLevel 2 - Fair: Includes multiplication problems, with positive single digit\nLevel 3 - Intermediate: Includes division problems, with positive single digit\nLevel 4 - Hard: Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative single digit\nLevel 5 - Impossible: Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative two and three digit\n");
}

void math (info *ptr)
{
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, cases = 0, correct = 0;
	if (ptr->level == 1)
	{
		for (correct = 0; correct != 10; )
		{
			system("cls");
			generate_random(&num1, &num2, &num3, &num4, &cases, ptr->level, ptr); 
			correct += level1(num1, num2, num3, cases, ptr);
		}
		system("cls");
		printf("You have finished level 1, what you want to do next?\n");
	}
	else if (ptr->level == 2)
	{
		for (correct = 0; correct != 10; )
		{
			system("cls");
			generate_random(&num1, &num2, &num3, &num4, &cases, ptr->level,ptr); 
			correct += level2(num1, num2, ptr);
		}
		system("cls");
		printf("You have finished level 2, what you want to do next?\n");
	
	}
	else if (ptr->level == 3)
	{
		for (correct = 0; correct != 10; )
		{
			system("cls");
			generate_random(&num1, &num2, &num3, &num4, &cases, ptr->level,ptr); 
			correct += level3(num1, num2, ptr);
		}
		system("cls");
		printf("You have finished level 3, what you want to do next?\n");
	}
	else if (ptr->level == 4)
	{
		for (correct = 0; correct != 10; )
		{
			system("cls");
			generate_random(&num1, &num2, &num3, &num4, &cases, ptr->level,ptr); 
			correct += level4(num1, num2, num3, cases, ptr);
		}
		system("cls");
		printf("You have finished level 5, what you want to do next?\n");
	}
	else if (ptr->level == 5)
	{
		
		for (correct = 0; correct != 10; )
		{
			system("cls");
			generate_random(&num1, &num2, &num3, &num4, &cases, ptr->level,ptr); 
			correct += level5 (num1, num2, num3, num4, cases, ptr);
		}
		system("cls");
		printf("You have finished level 5, what you want to do next?\n");
	}
	else
		printf("Invalid input, make sure you enter the correct level from 1 to 5\n");
	return;
}

int level1 (int num1, int num2, int num3, int cases, info *ptr)
{
	int answer = 0;
	if ( cases == 1)
	{
		while (1)
		{
			printf("%d + %d + %d = ", num1, num2, num3);
			scanf("%d", &answer);
			if (answer == (num1+num2+num3))
			{
				(ptr->lvl1.correct) += 1;
				//printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl1.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
	}
		else if ( cases == 2)
		{
			while (1)
		{
			printf("%d + %d - %d = ", num1, num2, num3);
			scanf("%d", &answer);
			if (answer == (num1+num2-num3))
			{
				(ptr->lvl1.correct) += 1;
			//	printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl1.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
		}
		else if ( cases == 3)
		{
			while (1)
		{
			printf("%d - %d + %d = ", num1, num2, num3);
			scanf("%d", &answer);
			if (answer == (num1-num2+num3))
			{
				(ptr->lvl1.correct) += 1;
				//printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl1.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
		}
		else
		{
			while (1)
		{
			printf("%d - %d - %d = ", num1, num2, num3);
			scanf("%d", &answer);
			if (answer == (num1-num2-num3))
			{
				(ptr->lvl1.correct) += 1;
				//printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl1.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
		}
		return -1;
}
int level2 (int num1, int num2, info *ptr)
{
	int answer = 0;

	while (1)
	{
		printf ("%d * %d = ", num1, num2);
		scanf("%d", &answer);
		if (answer == (num1*num2))
		{
			(ptr->lvl2.correct) += 1;
			//printf("The answer is right!\n");
			//printf("%d\n", ptr->lvl2.correct);
			return 1;
		}
		else
			{
				(ptr->lvl2.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
	}
}
int level3 (int num1, int num2, info *ptr)
{
	int answer = 0, remainder = 0;
	char temp = '\0';
	while (1)
	{

		printf ("%d / %d = (answerRremainder - ex: 1R2)", num1, num2);
		scanf("%d%c%d", &answer, &temp, &remainder);
		if ((answer ==(int)(num1/num2)) && (remainder == (num1 % num2)))
		{
			(ptr->lvl3.correct) += 1;
			//printf("The answer is right!\n");
			//printf("%d\n", ptr->lvl3.correct);
			return 1;
		}
		else
			{
				(ptr->lvl3.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
	}
	
}
int level4 (int num1, int num2, int num3, int cases, info *ptr)
{
int answer = 0, remainder = 0;
char temp;
		if ( cases == 1)
		{
		while (1)
		{
			printf("%d + (%d / %d) = (answerRremainder, ex: 3R2)", num1, num2, num3);
			scanf("%d%c%d", &answer, &temp, &remainder);
			if (answer == ((num1*num3 +num2)/ num3) && remainder == ((num1*num3 +num2) % num3))
				{
					(ptr->lvl4.correct) += 1;
					//printf("The answer is right!\n");
					//printf("%d\n", ptr->lvl4.correct);
					return 1;
				}
				else
				{
					(ptr->lvl4.incorrect) += 1;
					printf("Wrong, please try again\n");
				}
			}
		}
		else if ( cases == 2)
		{
				while (1)
				{
					printf("%d * %d - %d = ", num1, num2, num3);
					scanf("%d", &answer);
					if (answer == ((num1*num2)-num3))
					{
						(ptr->lvl4.correct) += 1;
						//printf("The answer is right!\n");
						//printf("%d\n", ptr->lvl4.correct);
						return 1;
					}
					else
					{
						(ptr->lvl4.incorrect) += 1;
						printf("Wrong, please try again\n");
					}
				}
			}
		else if ( cases == 3)
			{
				while (1)
				{
				printf("%d * %d / %d = (answerRremainder, ex: 3R2)", num1, num2, num3);
				scanf("%d%c%d", &answer, &temp, &remainder);
				if (answer == ((num1*num2)/num3) && remainder == ((num1*num2) %num3))
				{
					(ptr->lvl4.correct) += 1;
					//printf("The answer is right!\n");
					//printf("%d\n", ptr->lvl4.correct);
					return 1;
				}
				else
				{
					(ptr->lvl4.incorrect) += 1;
					printf("Wrong, please try again\n");
				}
			}
		}

		else if ( cases == 4)
		{
			while (1)
			{
				printf("%d - %d / %d = (answerRremainder, ex: 3R2)", num1, num2, num3);
				scanf("%d%c%d", &answer, &temp, &remainder);
				if (answer == (((num1*num3)-num2)/num3) && remainder == (((num1*num3)-num2)%num3))
				{
					(ptr->lvl4.correct) += 1;
					//printf("The answer is right!\n");
					//printf("%d\n", ptr->lvl4.correct);
					return 1;
				}
				else
				{
					(ptr->lvl4.incorrect) += 1;
					printf("Wrong, please try again\n");
				}
			}
		}

		else if ( cases == 5)
		{
			while (1)
			{
				printf("%d * %d * %d = ", num1, num2, num3);
				scanf("%d", &answer);
				if (answer == (num1*num2*num3))
				{
					(ptr->lvl4.correct) += 1;
					//printf("The answer is right!\n");
					//printf("%d\n", ptr->lvl4.correct);
					return 1;
				}
				else
				{
					(ptr->lvl4.incorrect) += 1;
					printf("Wrong, please try again\n");
				}
			}
		}

		else if ( cases == 6)
		{
			while (1)
			{
				printf("%d + %d * %d = ", num1, num2, num3);
				scanf("%d", &answer);
				if (answer == (num1+num2*num3))
				{
					(ptr->lvl4.correct) += 1;
					//printf("The answer is right!\n");
					//printf("%d\n", ptr->lvl4.correct);
					return 1;
				}
				else
				{
					(ptr->lvl4.incorrect) += 1;
					printf("Wrong, please try again\n");
				}
			}
		}

		else
		{
			while (1)
		{
			printf("%d / %d / %d = (answerRremainder, ex: 3R2)", num1, num2, num3);
			scanf("%d%c%d", &answer, &temp, &remainder);
			if (answer == (num1/(num2*num3)) && remainder == (num1 % (num2*num3)))
			{
				(ptr->lvl4.correct) += 1;
				//printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl4.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
		}
		return -1;
}
int level5 (int num1, int num2, int num3, int num4, int cases, info *ptr)
{
int answer = 0, remainder = 0;
char temp;
	if ( cases == 1)
	{
		while (1)
		{
			printf("%d + %d + (%d / %d) = (answerRremainder, ex: 3R2)", num1, num2, num3, num4);
			scanf("%d%c%d", &answer, &temp, &remainder);
			if (answer == ((num1*num4 +num2*num4 + num3)/ num4) && remainder == ((num1*num4 +num2*num4 + num3) % num4))
			{
				(ptr->lvl5.correct) += 1;
				printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl5.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
	}
		else if ( cases == 2)
		{
			while (1)
		{
			printf("%d * %d - %d - %d = ", num1, num2, num3, num4);
			scanf("%d", &answer);
			if (answer == ((num1*num2)-num3 - num4))
			{
				(ptr->lvl5.correct) += 1;
				printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl5.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
		}
		else if ( cases == 3)
		{
			while (1)
		{
			printf("%d *%d * %d / %d = (answerRremainder, ex: 3R2)", num1, num2, num3, num4);
			scanf("%d%c%d", &answer, &temp, &remainder);
			if (answer == ((num1*num2*num3)/num4) && remainder == ((num1*num2*num3) %num4))
			{
				(ptr->lvl5.correct) += 1;
				printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl5.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
		}
		else
		{
			while (1)
		{
			printf("%d / %d / %d / %d = (answerRremainder, ex: 3R2)", num1, num2, num3, num4);
			scanf("%d%c%d", &answer, &temp, &remainder);
			if (answer == ((num1/num2) * (num4/num3)) && remainder == ((num1*num4) % (num2*num3)))
			{
				(ptr->lvl5.correct) += 1;
				printf("The answer is right!\n");
				//printf("%d\n", ptr->lvl1.correct);
				return 1;
			}
			else
			{
				(ptr->lvl5.incorrect) += 1;
				printf("Wrong, please try again\n");
			}
		}
		}
		return -1;
}

void initializer (info *ptr)
{
	ptr->lvl1.correct = 0;
	ptr->lvl1.incorrect = 0;
	ptr->lvl2.correct = 0;
	ptr->lvl2.incorrect = 0;
	ptr->lvl3.correct = 0;
	ptr->lvl3.incorrect = 0;
	ptr->lvl4.correct = 0;
	ptr->lvl4.incorrect = 0;
	ptr->lvl5.correct = 0;
	ptr->lvl5.incorrect = 0;
	strcpy(ptr->initial, "N/A");
	ptr->level = 0;

}

void generate_random (int *num1, int *num2, int *num3, int *num4, int *cases, int level, info *ptr)
{
	if (level == 1)
	{
		*num1 = rand() % 10;
		*num2 = rand() % 10;
		*num3 = rand() % 10;
		*cases = (rand() % 5) + 1;
		if (ptr->lvl1.correct >= 5)
		{
			*num1 *= 2;
			*num2 *= 2;
			*num3 *= 2;
		}
	}
	else if (level == 2)
	{
		*num1 = rand() % 10;
		*num2 = rand() % 10;
		*cases = (rand() % 5) + 1;
		if (ptr->lvl2.correct >= 5)
		{
			*num1 *= 2;
			*num2 *= 2;
		}

	}
	else if (level == 3 )
	{
		while (1)
		{
		*num1 = rand() % 10;
		*num2 = rand() % 10;
		*cases = (rand() % 5) + 1;
		if (ptr->lvl3.correct >= 5)
		{
			*num1 *= 2;
			*num2 *= 2;
		}
		if (*num2 != 0)
		{
			break;
		}
		}
	}
	else if (level == 4)
	{
		while (1)
		{
		*num1 = (rand() % 20) - 10;
		*num2 = (rand() % 20) - 10;
		*num3 = (rand() % 20) - 10;
		*cases = (rand() % 7) + 1;
		if (ptr->lvl4.correct >= 5)
		{
			*num1 *= 2;
			*num2 *= 2;
			*num3 *= 2;
		}
		if ((*num1 != -10 && *num1 != 10 && *num1 != 0) && (*num2 != -10 && *num2 != 10 && *num2 !=0) && (*num3 != -10 && *num3 != 10 && *num3 != 0))
		{
			break;
		}

		}

	}
	else
	{
		while (1)
		{
		*num1 = (rand() % 200) - 100;
		*num2 = (rand() % 200) - 100;
		*num3 = (rand() % 2000) - 1000;
		*num4 = (rand() % 2000) - 1000;
		*cases = (rand() % 5) + 1;
		if (ptr->lvl5.correct >= 5)
		{
			*num1 *= 2;
			*num2 *= 2;
			*num3 *= 2;
			*num4 *= 2;
		}
		if ((*num1 != -100 && *num1 != 100 && *num1 != 0) &&
			(*num2 != -100 && *num2 != 100 && *num2 != 0) && 
			(*num3 != -1000 && *num1 != 1000 && *num3 != 0) && 
			(*num4 != -1000 && *num4 != 1000 && *num4 != 0))
		{
			break;
		}
		}
	}
}