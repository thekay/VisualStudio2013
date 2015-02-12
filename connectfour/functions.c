#include "header.h"
int input (Cell idk)
{
	while (1)
	{
		printf("Please enter the colume number: ");
		scanf (" %d", &idk.col);
		if (idk.col >= 0 && idk.col <= 6)
		{
			return idk.col;
		}
	}
}
void initializer (char board[][maxcol])
{
	int counter = 0, index = 0;
	char symbol = '-';
	for (counter = 0; counter < maxrow; counter++)
	{
		for (index = 0; index < maxcol; index++)
		{
			board[counter][index] = symbol;
		}
	}
}

void print (char board[][maxcol])
{
	int counter = 0, index = 0;
	char symbol = '-';
	printf("0  1  2  3  4  5  6\n\n");
	for (counter = 0; counter < maxrow; counter++)
	{
		for (index = 0; index < maxcol; index++)
		{
			printf("%c  ", board[counter][index]);
		}
		printf("\n\n");
	}
	printf("\n");
}

int check (char board[][maxcol], Cell idk, int *row_update)
{
	char temp = '\0';
	idk.row = 5;
	while (idk.row >= 0)// go through the 
	{
		temp = board[idk.row][idk.col];
		if (temp == 'Y' || temp == 'R');
		else 
		{
			place (board, idk.row, idk.col, idk.token);
			*row_update = idk.row;
			return 1;
		}
		idk.row--;
	}
	return 0;
	
}

void place (char board[][maxcol], int row, int col, int symbol)
{
	if (symbol == YELLOW)
	{
		board[row][col] = 'Y';
	}
	else
	{
		board[row][col] = 'R';
	}
}

int check_if_win (char board[][maxcol], int row, int col, char symbol, int *plays)
{
	char temp1 = board[row][col];
	int temp = 0, counter = 0, index = 0;
	*plays += 1;
	//check horizontal
	for (; counter <= 5 ;counter++)
	{
		for (index = 0; index <= 6; index++)
		{
			if (board[counter][index] == symbol)
			{
				temp++;
			}
			else
				temp = 0;
			if (temp == 4)
				return 1;
		}
		temp = 0;
	}
	//check vertical
	for (index = 0; index <= 6; index++)
	{
		for (counter = 0; counter <= 5 ;counter++)
		{
			if (board[counter][index] == symbol)
			{
				temp++;
			}
			else
				temp = 0;
			if (temp == 4)
				return 1;
		}
		temp = 0;
	}
	//other check
	temp = 0;
	counter = row;
	index = col;
	while (counter <= 5 && index >= 0)
	{
		if (board[counter][index] == symbol)
		{
			temp++;
		}
		else
			break;
		counter++;
		index--;
	}
	counter = row - 1;
	index = col + 1;
	while (counter >= 0 && index <= 6)
	{
		if (board[counter][index] == symbol)
		{
			temp++;
		}
		else
			break;
		counter--;
		index++;
	}
	if (temp ==4)
		return 1;

	//other check
	temp = 0;
	counter = row;
	index = col;
	while (counter <= 5 && index <= 6)
	{
		if (board[counter][index] == symbol)
		{
			temp++;
		}
		else
			break;
		counter++;
		index++;
	}
	counter = row - 1;
	index = col - 1;
	while (counter >= 0 && index >= 0)
	{
		if (board[counter][index] == symbol)
		{
			temp++;
		}
		else
			break;
		counter--;
		index--;
	}
	if (temp ==4)
		return 1;
	return 0;
}