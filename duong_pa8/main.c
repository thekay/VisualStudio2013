#include "header.h"
//Please modify in the initialize zone
int main (void)
{
	//initialize zone
	int n = 0, list[10] = {1,2,3,4,5,6,7,8,9}, target = 9, index = 0, problem4 = 0, problem5 = 0, problem6 = 0, problem7[10] = {10, 11, -20, 4, 21, -11, -50, 10, -20, -70}, answer7 = 0, choice = 0,
		bonus[5][5] =	{-5, 6, 0, 2, 2,
					      2, 2, 2, 9, 3,	
						  3, 3, 2, 1, -8,
						  7, -2, 6, 0, 4,
						  2, 1, 2, 1, 2}, bonus1[10] = {0}, *otherptr = NULL, most_occur = 0, appear_times = 0, temp = 0;
	char string1 [10] = "Akatsuki", blank_string1[10] = {'\0'}, string3[5][10]= {'\0'}, string4[20] = "race car", string6[100] = "Merry Christmas and Happy New Year!", number6 = '\0';
	Occurrences *first = NULL;
	first = (Occurrences *) malloc (sizeof(Occurrences));
	otherptr = bonus1;
	
	while (choice != -1)
	{
		printf("What problem you want to test? (-1 to exit)\n1. Problem 1, copy string\n2. Problem 2, binary search\n3. Problem 3, bubble sort\n4. Problem 4, is_palindrome\n5. Problem 5, sum primes\n6. Problem 6, maximum occurrences\n7. Problem 7, smallest sum sequence\n8. Bonus assignment\n9. Clear screen\n>>");
		scanf("%d", &choice);
		if (choice == -1)
		{
			break;
		}
		if (choice == 1)
		{
			//Problem 1
			//Modify string1 for difference result
			my_str_n_cat(string1, blank_string1, (strlen(string1) - 1));
			printf("%s\n",blank_string1); 
		}

		else if (choice == 2)
		{
			//Problem 2
			//Modify target for difference result
			index = binary_search(list, 8, target); //pre-condition: n = length - 1
			printf("index of target: %d\n", index);
		}

		else if (choice == 3)
		{
			//Problem 3
			//Modify strings down here for difference result
			strcpy(string3[0], "Lion");
			strcpy(string3[1], "Centaur");
			strcpy(string3[2], "Cat");
			strcpy(string3[3], "Elk");
			strcpy(string3[4], "Dog");
			bubble_sort(string3, 4); //pre-condition: length = length - 1
			printf("%s\n%s\n%s\n%s\n%s\n", string3[0], string3[1], string3[2], string3[3], string3[4]);
		}

		else if (choice == 4)
		{
			//Problem 4
			//Modify string4 for difference result
			problem4 = is_palindrome(string4, (strlen(string4) - 1), 0); //always pass 0 in as the index
			if (problem4 == 1)
			{
				printf("The word \"%s\" is palindrome\n", string4);
			}
			else
			{
				printf("The word \"%s\" is not palindrome\n", string4);
			}

		}

		else if (choice == 5)
		{
			//Problem 5
			//For this problem I need an additional function call is_prime(n) to check if the number is prime
			problem5 = sum_primes(20); //Modify number 20 for difference result
			printf("%d\n", problem5);
		}

		else if (choice == 6)
		{
			//Problem 6
			//Because I don't know for sure how many different characters are there in the string.
			//I will use the linkedlist to solve this problem.
			//Weaknesses: If there are two or more character have the same occurrences, the program will only display the first character ex: string6[10] = "ttcc", most_occur = 2, character appear most: 't'
			//initialize everthing to 0 or NULL
			//Modify string6 for difference result
			first->character = '\0';
			first->frequency = 0.0;
			first->next = NULL;
			first->num_occurrences = 0;
			first = maximum_occurrences (string6, &first, &problem6, &number6, strlen(string6));
			//printout stats
			while (first->frequency != 0.0)
			{
				printf("Character %c, time occur %d, and Frequently %lf\n", first->character, first->num_occurrences, first->frequency);
				first = first->next;
			}
			printf("\'%c\' is the character that occur most, and it occurs %d times\n", number6, problem6);
		}

		else if (choice == 7)
		{
			//Problem 7
			//Modify problem7 for difference result
			answer7 = smallest_sum_sequence(problem7,(sizeof(problem7) / sizeof(problem7[0])));
			printf("Smallest sum sequence is: %d\n", answer7);
		}
		else if (choice == 8)
		{
			// For this assignment, modify bonus for changes
			max_consecutive_integers(bonus, 0, 0, &most_occur, &otherptr, 5, &appear_times);
			//printf("%d\n", &(bonus[0][3]));
			printf("Address of the first element of the most consecutive integer is: %d\nAnd the sequence is: ", most_occur);
	
			while(temp < appear_times)
			{
				printf("%d ", bonus1[temp]);
				temp++;
			}
			printf("\n");
		}

		else if (choice == 9)
		{
			system("cls");
		}
		else
		{
			printf("Unrecognized input, system closed!\n");
			choice = -1;
		}

	}	

	
	return 0;
}