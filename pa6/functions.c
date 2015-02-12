#include "header.h"
//that displays an initial program welcome message along with the rules of Battleship.
void welcome_screen (void) 
{
	printf("Welcome to battleship game here is some simple rules:\n1. This is a two player game.\n2. Player1 is you and Player2 is the computer.\n3. You know the rest of the rule, let's play!\n");
}

//This function initialize '-' to all the indexes
void initializer (char player[][10], int size)
{
	int row = 0, col = 0;
	char a = '-';
	while (row < size)
	{
		for (; col < size; col++)
		{
			player[col][row] = '-';
		}
		col = 0;
		row++;
	}
}

//Ask the user if they want to manually place the ship or randomly place them and
//check if the input is valid
void random_or_manually (int *temp)
{
	while (*temp != 1 && *temp != 2)
	{
		printf("Please select from the following menu:\n1. Enter positions of ships manually.\n2. Allow the program to randomly select positions of ships.\n>> ");
		scanf ("%d", temp);
		if (*temp != 1 && *temp != 2)
		{
			//system("cls");
			printf(">>>1 and 2 only<<<\n");
		}
	}
}

//This function print out the board when placing the ship, all the ships position are hidden
void printout2 (char player[][10],char computer[][10], int size)
{
	int row = 0, col = 0;
	printf("      Your board\t\t            Computer's board\n");
	printf("  0 1 2 3 4 5 6 7 8 9\t\t\t  0 1 2 3 4 5 6 7 8 9\n");
	while (row < size)
	{
		printf("\n%d ", row);
		for (col = 0; col < size; col++)
		{
				printf("%c ", player[row][col]);
		}
		printf("\t\t\t%d ", row);
		for (col = 0; col < size; col++)
		{
				if (computer[row][col] == 'c' || computer[row][col] == 'b' || computer[row][col] == 'r' || computer[row][col] == 's' || computer[row][col] == 'd')
			{
				printf("- ");
			}
			else
			{
				printf("%c ", computer[row][col]);
			}
		}
		printf("\n");
		row++;
	}
}

//This function print out the board when playing, which mean all the ships are shown
void printout (char input[][10], int size)
{
	int row = 0, col = 0;
	printf("\t0    1    2    3    4    5    6    7    8    9\n\n");
	while (row < size)
	{
		printf("\n%d\t", row);
		for (; col < size; col++)
		{
			printf("%c    ",input[row][col]);
		}
		col = 0;
		printf("\n");
		row++;
	}
	
}

//This function allow player to place the ship manually
void place_manually (char player[][10], int size)
{
	int row = 0, col = 0, ship_kind = 1, temp = 0;
	char direction = '\0';
	while (ship_kind <= 5)
	{
		printout(player, 10);
		//Get input for coordinate, and check if it valid
		do
		{
			printf("Please enter the coordinate(row then col) (Ex: 0 0): ");
			scanf("%d%d", &row, &col);
			if ((row < 10 && col < 10) && (row >= 0 && col >= 0))
			{
				break;
				//system("cls");
			}
			else
				printf ("You entered invalid coordinate, please try again\n");
		}while (1);
		
		//Get input for direction, and check if it valid
		do
		{
			printf("Which direction you want to place? North(n), South(s), West(w), or East(e): ");
			scanf(" %c", &direction);
			if (direction == 'n' ||  direction == 's' ||  direction == 'w' ||  direction == 'e')
			{
				break;
				//system("cls");
				
			}
			else
				printf("\n>>>invalid input, please try again<<<\n");
		}while (1);
		//call the place_ship function
		temp = place_ship (player, direction, row, col, ship_kind);
		if (temp == 0)
		{
			system("cls");
			printf("Can't place ship, either out of battlefield or on top of other ship, please try again\n");
		}
		else
		{
			ship_kind++;
			system("cls");
		}
		
	}
}

//This function determine the size of he ship.
int ship_size (int temp, char *ship)
{
	if (temp == 1) 
	{
		*ship = 'c';
		return 5;}
	else if(temp == 2)
	{
		*ship = 'b';
		return 4;}
	else if(temp == 3 || temp == 4)
	{
		if (temp == 3)
		{
			*ship = 'r';
		}
		else
			*ship = 's';
		return 3;}
	else
		*ship = 'd';
		return 2;

}

//This function check if the ship is placable
int place_ship (char player[][10], char direction, int row, int col, int ship_kind)
{
	int size = 0, counter = 0, condition = 1; // condition 1 for true and 0 for wrong
	char temp = '\0', ship = '\0';
	if (direction == 'n')
	{
		size = ship_size (ship_kind, &ship);
		if ((row - (size - 1)) < 0)
		{
			return 0;
		}
		else
		{
			for (counter = 0 ;counter < size; counter++)
			{
				temp = player[row - counter][col];
				if (temp != '-')
				{
					return 0;
				}
			}
			for (counter = 0 ;counter < size; counter++)
					{
						player[row - counter][col] = ship;
					}
				return 1;
			
		}
	}
	else if(direction == 's')
	{
		size = ship_size (ship_kind, &ship);
		if ((row + (size -1)) >= 10)
		{
			return 0;
		}
		else
		{
			for (counter = 0 ;counter < size; counter++)
			{
				temp = player[row + counter][col];
				if (temp != '-')
				{
					return 0;
				}
				
			}
			for (counter = 0 ;counter < size; counter++)
				{
					player[row + counter][col] = ship;
				}
			return 1;
			
		}
	}
	else if(direction == 'w')
	{
		size = ship_size (ship_kind, &ship);
		if ((col - (size - 1)) < 0)
		{
			return 0;
		}
		else
		{
			for (counter = 0 ;counter < size; counter++)
			{
				temp = player[row][col - counter];
				if (temp != '-')
				{
					return 0;
				}
					
			}
			for (counter = 0 ;counter < size; counter++)
				{
					player[row][col - counter] = ship;
				}
			return 1;
			
		}
	}
	else
	{
		size = ship_size (ship_kind, &ship);
		if ((col + (size-1)) >= 10)
		{
			return 0;
		}
		else
		{
			for (counter = 0 ;counter < size; counter++)
			{
				temp = player[row][col + counter];
				if (temp != '-')
				{
					return 0;
				}
			}
			for (counter = 0 ;counter < size; counter++)
				{
					player[row][col + counter] = ship;
				}
			return 1;
			
		}
	}
	return 0;

}

//This function place the ships randomly
void place_randomly (char player[][10], int size)
{
	int row = 0, col = 0, ship_kind = 1, temp = 0;
	char direction = '\0', direction_list [4] = {'n', 's', 'w', 'e'};
	while (ship_kind <= 5)
	{
		//Get input for coordinate, and check if it valid
		row = rand () % 10;
		col = rand () % 10;
		
		//Get input for direction, and check if it valid
		temp = rand () % 5;
		direction = direction_list[temp];
		//call the place_ship function, 2 posible returns, 1 if the ship places. 0 if the ship can't be place because out of boudary or on top of other ships
		temp = place_ship (player, direction, row, col, ship_kind);
		if (temp == 0)
		{
			printf("Can't place ship, either out of battlefield or on top of other ship, please try again\n");
		}
		else
		{
			ship_kind++;
			system("cls");
		}
		
	}
}

// This is where all the actions take place
int lobby (char player[][10], char computer[][10], int size, int who_turn, FILE *logfile, int *player_hits, int *player_misses, int *computer_hits, int *computer_misses)
{
	int row = 0, col = 0, int_temp = 0, hit_or_miss = 2;
	struct ships ship = {0};
	while(1) //infinite loop, there is a break point in the loop
	{
		if (who_turn == 0)
		{
			//Player turn
			while (hit_or_miss != 0)
			{
				printout2(player, computer, 10);
				player_input (&row, &col);
				system("cls");
				hit_or_miss = check_if_hit (logfile, computer, 10, row, col, 1, &ship.c_c, &ship.c_b, &ship.c_r, &ship.c_s, &ship.c_d);
				if (hit_or_miss == 1)
				{
					printout2(player, computer, 10);
					system("cls");
					printf("You shot at (%d, %d), it's a hit\n", row, col);
					*player_hits += 1;
				}
				else
				{
					//printout2(player, computer, 10);
					printf("You shot at (%d, %d), it's a miss\n", row, col);
					who_turn = 1;
					*player_misses += 1;
				}
				int_temp = check_if_win (computer, 10);
				if (int_temp == 1)
				{
					return 0;
				}

			}
				
		}
		
		else
		{
			//Computer turn
			while (hit_or_miss != 0)
			{
				//generate random coordinate
				row = rand() % 10;
				col = rand() % 10;
				//check if the shot hit or miss
				hit_or_miss = check_if_hit (logfile, player, 10, row, col, 0, &ship.p_c, &ship.p_b, &ship.p_r, &ship.p_s, &ship.p_d);
				//check if the shot sunk a ship
				if (hit_or_miss == 1)
				{
					printf("computer shot at (%d, %d), it's a hit\n", row, col);
					*computer_hits += 1;
				}
				else
				{
					printf("Computer shot at (%d, %d), it's a miss\n", row, col);
					who_turn = 0;
					*computer_misses += 1;
				}
				int_temp = check_if_win (player, 10);
				if (int_temp == 1)
				{
					return 1;
				}
			}
		}
		//printout2(player, computer, 10);
		hit_or_miss = 2;
		//printf("Hit enter to continue");
		
	}
	
	return -1;
}

//This function check if the fire hit return 1 for hit, and 0 for missed
int check_if_hit (FILE *logfile, char board[][10], int size, int row, int col, int who_board, int *c, int *b, int *r, int *s, int *d)
{
	int hit_or_miss = 0;
	//initialize all the value to 0
		if (board[row][col] == 'c' || board[row][col] == 'b' || board[row][col] == 'r' || board[row][col] == 's' || board[row][col] == 'd' )
		{
			
			if (who_board == 0)//player's board
			{
				if (board[row][col] == 'c')
				{
					*c += 1;
					//fprintf(logfile, "c: %d\n", *c);
				}
				else if(board[row][col] == 'b')
				{
					*b += 1;
					//fprintf(logfile, "b: %d\n", *b);
				}
				else if(board[row][col] == 'r')
				{
					*r += 1;
					//fprintf(logfile, "r: %d\n", *r);
				}
				else if(board[row][col] == 's')
				{
					*s += 1;
					//fprintf(logfile, "s: %d\n", *s);
				}
				else
				{
					*d += 1;
					//fprintf(logfile, "d: %d\n", *d);
				}
				fprintf(logfile, "Computer shot at (%d, %d), it's a hit\n", row, col);
				
				check_ship (logfile, 0, c, b, r, s, d);

			}
			else // computer's board
			{
				if (board[row][col] == 'c')
				{
					*c += 1;
					//fprintf(logfile, "c: %d\n", *c);
					
				}
				else if(board[row][col] == 'b')
				{
					*b += 1;
					//fprintf(logfile, "b: %d\n", *b);
				}
				else if(board[row][col] == 'r')
				{
					*r += 1;
					//fprintf(logfile, "r: %d\n", *r);
				}
				else if(board[row][col] == 's')
				{
					*s += 1;
					//fprintf(logfile, "s: %d\n", *s);
				}
				else
				{
					*d += 1;
					//fprintf(logfile, "d: %d\n", *d);
				}
				fprintf(logfile, "Player shot at (%d, %d), it's a miss\n", row, col);
				check_ship (logfile, 1, c, b, r, s, d);

			}
			board[row][col] = '*';
			return 1;
		}
		else 
		{
			if (who_board == 0)
				{
					fprintf(logfile, "Computer shot at (%d, %d), it's a miss\n", row, col);
				}
				else
				{
					fprintf(logfile, "Player shot at (%d, %d), it's a miss\n", row, col);
				}
			return 0;
		}
			

}

//This function is unsed
void hit_miss (int value, int row, int col)
{
	if (value ==0)
	{
		printf("Coordinate (%d, %d) is a miss\n", row, col);
	}
	else
		printf("Coordinate (%d, %d) is a hit\n", row, col);
}

//This function get input from player
void player_input (int *row, int *col)
{
	do
				{
					printf("Your turn, please enter the coordinate(row then col) (Ex: 0 0): ");
					scanf("%d%d", row, col);
					if ((*row < 10 && *col < 10) && (*row >= 0 && *col >= 0))
					{
						break;
					}
					else
						printf ("You entered invalid coordinate, please try again\n");
					
					
				}while (1);
}

//This function iterate through the board and check if all the ships are sunken, if so win
int check_if_win (char board[][10], int size)
{
	int row = 0, col = 0;
	char a = '-';
	while (row < size)
	{
		for (; col < size; col++)
		{
			a = board[col][row];
			if (a == 'c' || a == 'b' || a == 'r' || a == 's' || a == 'd') //not win yet
			{
				return 0;
			}
		}
		col = 0;
		row++;
	}
	return 1;// for win
}

//This function check if a ship is sunken, if so fprintf(logfile);
void check_ship (FILE *logfile, int who_board, int *c, int *b, int *r, int *s, int *d)
{
	if (who_board == 0)//player's board
	{
		if (*c == 5)
		{
			fprintf(logfile,"Player's carrier has sunken\n");
			*c = 0;
		}
		if (*b == 4)
		{
			fprintf(logfile,"Player's battleship has sunken\n");
			*b = 0;
		}
		if (*r == 3)
		{
			fprintf(logfile,"Player's cruiser has sunken\n");
			*r = 0;
		}
		if (*s == 3)
		{
			fprintf(logfile,"Player's submarine has sunken\n");
			*s = 0;
		}
		if (*d == 2)
		{
			fprintf(logfile,"Player's destroyer has sunken\n");
			*d = 0;
		}

	}
	else //computer's board
	{
		if (*c == 5)
		{
			fprintf(logfile,"Computer's carrier has sunken\n");
			*c = 0;
		}
		if (*b == 4)
		{
			fprintf(logfile,"Computer's battleship has sunken\n");
			*b = 0;
		}
		if (*r == 3)
		{
			fprintf(logfile,"Computer's cruiser has sunken\n");
			*r = 0;
		}
		if (*s == 3)
		{
			fprintf(logfile,"Computer's submarine has sunken\n");
			*s = 0;
		}
		if (*d == 2)
		{
			fprintf(logfile,"Computer's destroyer has sunken\n");
			*d = 0;
		}
	}
}

