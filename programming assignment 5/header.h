#define _CRT_SECURE_NO_WARNINGS
#ifndef pa5_h
#define pa5_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void read (FILE *infile,char *original, char *arr, int *counter);
void assign (char *input, char *N_sequence, char *S_sequence, int start_point, int end_point);
void display_sequence ( char *original, int counter);
void print (char *input, int size);
void identifier (FILE *output, char *N_sequence, char *S_sequence, int number_of_sequence, int sub_difference);
void generator (char DNA_holder[4], char random_paired[15][15], int size);
void write_randomed_sequence (FILE *output, char random_paired[15][15], int size);
#endif 