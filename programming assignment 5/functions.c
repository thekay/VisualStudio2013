#include "header.h"
// Read in all the input into a single array
void read (FILE *infile,char *original, char *arr, int *counter)
{
	int count = 0, x = 0;
	char temp = 'z';
	while (!feof(infile))
	{
		fscanf (infile, "%c", &temp);
		original[x] = temp;// For display original input
		//printf("%c", original[x]);// For display original input
		x++;// For display original input
		if (temp == 'N' || temp == 'S' || temp == 'A' || temp == 'T' || temp == 'G' || temp == 'C')
		{
			arr[count] = temp;
			count++;
			//printf("%c",temp);
			if ( temp == 'A' || temp == 'T' || temp == 'G' || temp == 'C')
			
			{
				*counter += 1;
			}
		}
	}
} 


//This function check which sequence appear first, and assign informations appropriately
void assign (char *input, char *N_sequence, char *S_sequence, int start_point, int end_point)
{
	int x = 1, tracker = 0;
	char temp = '\0';
	if (input[0] == 'N')
	{
		for (x = 1; x <= end_point / 2; x++)
		{
			temp = input[x];
			N_sequence[x] = temp;
			//printf("%c", N_sequence[x]);
		}
		//printf("\n\n");
		x = 1;
		while(x <= end_point / 2 )
		{
			temp = input[start_point];
			S_sequence[x] = temp;
			//printf("%c", S_sequence[x]);
			x++;
		start_point++;
		}
		
	}
	else
	{
		for (x = 1; x <= end_point / 2; x++)
		{
			temp = input[x];
			S_sequence[x] = temp;
			//printf("%c", S_sequence[x]);
		}
		//printf("\n\n");
		x = 1;
		//start_point += 2;
		while(x <= end_point / 2 )
		{
			temp = input[start_point];
			N_sequence[x] = temp;
			//printf("%c", N_sequence[x]);
			x++;
		start_point++;
		}
		
	}
}

//This function print out the original sequences
void display_sequence ( char *original, int counter)
{
	int x = 0; 
	printf("Original sequences\n");
	for (x = 0; original[x] != '\0'; x++)
	{
		printf ("%c", original[x]);
	}
}

//This function print out the information of the inputted array
void print (char *input, int size)
{
	int i;
	for(i = 1; i <= size; i++)
	{
		printf("%c", input[i]);
	}
}

//This function identifies flipped and mismatched.
void identifier (FILE *output, char *N_sequence, char *S_sequence, int number_of_sequence, int sub_difference)
{
	int x = 1, runner = 1, temp = 1, sub_runner = 1;

	while (temp <= number_of_sequence)
	{
		fprintf(output,"Mutation(s) found in sequence %d\n", temp);
		while (runner <= 15)
		{
			if (S_sequence[x] != N_sequence[x] || S_sequence[x + 15] != N_sequence[x + 15]) //Check for mismatch DNA, If a mismatch found
			{
				if (S_sequence[x] == N_sequence[x + 15] && S_sequence[x + 15] == N_sequence[x])// Check if the mismatch is flipped
				{
					fprintf(output,"Pair %d flipped pair\n", runner);
				}
				else // if it's not flipped, then its just mismatch
				{
					fprintf(output,"Pair %d mismatched pair\n", runner);
				}
		
			} 
			x++;
			runner++;
		}
		
		
		x = x+15;
		runner = 1;
		temp++;
	}

	if (sub_difference > 0)
	{
		do
		{
			fprintf(output,"Mutation(s) found in sequence %d (subsequence)\n", temp);
			while (runner <= sub_difference)
			{
				if (S_sequence[x] != N_sequence[x] || S_sequence[x + sub_difference] != N_sequence[x + sub_difference])//Check for mismatch DNA, If a mismatch found
				{
					if (S_sequence[x] == N_sequence[x + sub_difference] && S_sequence[x + sub_difference] == N_sequence[x])// Check if the mismatch is flipped
					{
						fprintf(output,"Pair %d flipped pair\n",runner);
					}
					else // if it's not flipped, then its just mismatch
					{
						fprintf(output,"Pair %d mismatched pair\n",runner);
					}
		
				} 
				x++;
				runner++;
			}
	
			break;
		}while (1);
	}
}

/////////////////////////////////////////////////////	Extra credit	//////////////////////////////////////////////////////////////

//This function generate randomly paired bases to form random DNA sequences and write it to “sequences.txt” file.
void generator (char DNA_holder[4], char random_paired[15][15], int size)
{
	int random = 0, counter = 0;
	char temp = '\0';
	//generate random DNAs
	while (counter <= (size - 1))
	{
		random = rand() % 4;
		random_paired[0][counter] = DNA_holder [random];
		if (random == 0)
		{
			random_paired [1][counter] = DNA_holder [1];
		}
		else if (random == 1)
		{
			random_paired [1][counter] = DNA_holder [0];
		}
		else if (random == 2)
		{
			random_paired [1][counter] = DNA_holder [3];
		}
		else
		{
			random_paired [1][counter] = DNA_holder [2];
		}
		counter++;
	}

}

void write_randomed_sequence (FILE *output, char random_paired[15][15], int size)
{
	int counter = 0;
	char temp = '\0';
	//write first sequence
	while (counter <= (size - 1))
	{
		fprintf(output,"%c", random_paired[0][counter++]);
	}
	//write second sequence
	fprintf(output,"\n");
	counter = 0;
	while (counter <= (size - 1))
	{
		fprintf(output, "%c", random_paired[1][counter++]);
	}
}