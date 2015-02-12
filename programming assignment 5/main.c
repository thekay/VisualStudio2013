#include "header.h"

int main (void)
{
	int		counter = 0,  N_pointer = 0, tracker = 0, tracker2 = 0, 
			number_of_sequence = 0, sub_sequence = 0, start_point = 0, x = 1, temp = 1, main_difference = 15, sub_difference = 0, runner = 1, sub_runner = 1;
	FILE *infile = NULL, *output = NULL;
	char	N_sequence[1000] = {'\0'}, S_sequence[1000] = {'\0'}, input[1000] = {'\0'}, original[1000] = {'\0'},
			DNA_holder[4] = {'A','T','G','C'}, random_paired[15][15]; 
	srand ((unsigned) time (NULL));
	infile = fopen ("sequences.txt", "r");
	output = fopen ("mutations.txt", "w");
	//Read the N_sequence, then the S_sequence
	read (infile, original, input, &counter);
	
	//Assign the sequence into 2 arrays, the first one contain Normal sequence, the second one contain sample sequence
	start_point = (counter/2) +2;
	assign (input, N_sequence, S_sequence, start_point, counter);

	//Calculate things (number of sequence(s), is there any sunsequence, if so how many DNAs pair in it)
	number_of_sequence = (counter / 2) /30; //This indicate how many sequence with 30 DNAs
	sub_sequence = (counter - ((number_of_sequence *30) *2)) / 2;//There are 1 full sequence and a sub_sequence with 14 DNAs in it
	printf("There are %d DNAs inputted.\nWhich make up %d whole sequence (contain 2x15 DNAs).\nAnd a subsequence with %d pairs of DNAs (total of %d DNAS)\n\n", counter, number_of_sequence, sub_sequence/2, sub_sequence);
	
	//Display the original input
	display_sequence ( original, counter*2);// Print out the original input
	//identify flipped, mismatched pairs, and write it to mutations.txt
	identifier (output, N_sequence, S_sequence, number_of_sequence, sub_sequence/2);
	printf("\nIdentified, check \"mutations.txt\" for result\n");

	//Extra credits
	//generate random DNAs
	generator (DNA_holder, random_paired, 15);
	//Write it to sequences.txt
	fprintf(output,"\n\nRandom paired:\n");
	write_randomed_sequence (output, random_paired, 15);
	fclose(infile);
	fclose (output);
	return 0;
}