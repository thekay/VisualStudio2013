#define _CRT_SECURE_NO_WARNINGS
#ifndef pa6
#define pa6
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void welcome_screen (void);
void printout (char input[10][10], int size);
void printout2 (char player[][10],char computer[][10], int size);
void initializer (char player[][10], int size);
void random_or_manually (int *temp);
void place_manually (char player[][10], int size);
int ship_size (int temp, char *ship);
int place_ship (char player[][10], char direction, int row, int col, int ship_kind);
void place_randomly (char player[][10], int size);
int play_table (char player[][10], char computer[][10], int size, int who_turn, int *row, int *col);
int check_if_hit (FILE *logfile, char board[][10], int size, int row, int col, int who_board, int *c, int *b, int *r, int *s, int *d);
int lobby (char player[][10], char computer[][10], int size, int who_turn, FILE *logfile, int *player_hits, int *player_misses, int *computer_hits, int *computer_misses);
void hit_miss (int value, int row, int col);
void player_input (int *row, int *col);
void check_ship (FILE *logfile, int who_board, int *c, int *b, int *r, int *s, int *d);
int check_if_win (char board[][10], int size);

typedef struct stats
{
	int shots; //player total shots
	int hits;
	int misses;
	double hits_percentage;
	double misses_percentage;
} Stats;

struct ships
{
	int p_c;
	int p_b;
	int p_r;
	int p_s;
	int p_d;
	int c_c;
	int c_b;
	int c_r;
	int c_s;
	int c_d;

};
#endif