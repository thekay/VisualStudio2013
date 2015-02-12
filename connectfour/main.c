#include "header.h"
//test
//I look up at coolmath game and red always go first
//I assume that is right :D
// Row = 6, col = 7
int main (void)
{
	Cell idk;
	char board[6][7];
	int placed = 0, win_yet = 0, filled = 0, who_turn = 0, plays = 0;
	idk.row = 5;
	initializer (board);

	while(win_yet != 1)
	{
		//red go first
		if (who_turn == 0)
		{
			placed = 0;
			while (placed != 1)
				{
				print (board);
				idk.token = RED;
				//ask for input, restriction input have to 0 or more than and less than 6
				idk.col = input (idk);
				system("cls");
				//check if the row the user input is able to place
				filled = check (board, idk, &idk.row);
				if (filled == 0)
				{
					printf("Colume is full, choose others\n");
					placed = 0;
				}
				else
				{
					placed = 1;
					who_turn = 1;
				}
				//check if win or draw
				win_yet = check_if_win (board, idk.row, idk.col, 'R', &plays);
				
			}
		}
		else
		{
			placed = 0;
			while (placed != 1)
			{
				print (board);
				idk.token = YELLOW;
				//ask for input, restriction input have to 0 or more than and less than 6
				idk.col = input (idk);
				system("cls");
				//check if the row the user input is able to place
				filled = check (board, idk, &idk.row);
				if (filled == 0)
				{
					printf("Colume is full, choose others\n");
					placed = 0;
				}
				else
				{
					placed = 1;
					who_turn = 0;
				}
				//check if win or draw
				win_yet = check_if_win (board, idk.row, idk.col, 'Y',&plays);
				
			}
			if (plays == 42)
			{
				printf("Draw, game overed!\n");
				return 0;
			}
		}
	}
	if (who_turn == 0)
	{
		printf("Yellow token win\n");
	}
	else
	{
		printf("Red token win\n");
	}
	return 0;
}