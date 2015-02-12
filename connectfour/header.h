#define _CRT_SECURE_NO_WARNINGS

#ifndef header
#define header
#define maxrow 6
#define maxcol 7
#include <stdio.h>
#include <stdlib.h>

typedef enum color
{
	YELLOW, RED
}Color;
typedef enum boolean
{
	FALSE, TRUE
}Boolean;
typedef struct cell
{
	int row;
	int col;
	Color token;
	Boolean filled;
}Cell;

void print (char board[][maxcol]);
void initializer (char board[][maxcol]);
int check (char board[][maxcol], Cell idk, int *row_update);
void place (char board[][maxcol], int row, int col, int symbol);
int input (Cell idk);
int check_if_win (char board[][maxcol], int row, int col, char symbol, int *plays);
#endif