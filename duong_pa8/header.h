#define _CRT_SECURE_NO_WARNINGS
#ifndef header
#define header
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct occurrences
{
	char character;
	int num_occurrences;
	double frequency;
	struct occurrences *next;
} Occurrences;
void my_str_n_cat(char source[], char destination[], int n);
int binary_search (int list[], int n, int target);
void bubble_sort (char source[][10], int length);
int is_palindrome (char source[], int length, int index);
int sum_primes (unsigned int n);
int is_prime (int n);
Occurrences *maximum_occurrences (char source[], Occurrences **info, int *most_occur, char *character, int length);
int smallest_sum_sequence (int arr[], int length);
//Bonus assignment
void max_consecutive_integers (int arr[][5], int row, int col, int *ptr, int **consecutive, int size, int *appear_times);

#endif