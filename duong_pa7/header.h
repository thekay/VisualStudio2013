#define _CRT_SECURE_NO_WARNINGS
#ifndef header
#define header
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct Ratio
{
	int correct;
	int incorrect;
}ratio;
typedef struct Info
{
	ratio lvl1;
	ratio lvl2;
	ratio lvl3;
	ratio lvl4;
	ratio lvl5;
	char initial[4];
	int choice;
	int level;
	
}info;
void user_interface (info *ptr, FILE *save);
int input_and_check (void);
void load_previous_progress (FILE *save, info *ptr);
void save_progress (FILE *save, info *ptr); //for record with user friendly note
void savefile (FILE *save, info *ptr); // for save file
void difficulty_print (void);
void math (info *ptr);
int level1 (int num1, int num2, int num3, int cases, info *ptr);
int level2 (int num1, int num2, info *ptr);
int level3 (int num1, int num2, info *ptr);
int level4 (int num1, int num2, int num3, int cases, info *ptr);
int level5 (int num1, int num2, int num3, int num4, int cases, info *ptr);
void initializer (info *ptr);
void generate_random (int *num1, int *num2, int *num3, int *num4, int *cases, int level, info *ptr);
#endif