#include "header.h"
void my_str_n_cat(char source[], char destination[], int n)
{
	int index = 0;
	while ( source[index] != '\0' && index <= n)
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
}

int binary_search (int list[], int n, int target)
{
	int found = 0, left = 1, right = n, targetindex = -1, mid = 0;
	while (found != 1)
	{
		mid = right / left;
		if (target == list[mid])
		{
			found = 1;
			targetindex = mid;
		}
		else if( list[mid] < target)
		{
			left = mid+1;
			mid = right / left;
		}
		else if (list[mid] > target)
		{
			right = mid - 1;
			mid = right / left;
		}
	}
	return targetindex;
}

void bubble_sort (char source[][10], int length)
{
	int unsorted = length, index = 0, counter = 0;
	char temp[100] = {'\0'}, *storage[10]; //assume that there are less than 10 string pass in
	while ( counter <= length)
	{
		storage[counter] = source[counter];
		//printf("%d\n", storage[counter]);
		counter++;

	}
	for (;unsorted > 0; unsorted--)
	{
		for (index = 0; index < unsorted; index++)
		{
			if ((strcmp(storage[index], storage[index+1])) > 0)
			{
				strcpy(temp, storage[index]);
				strcpy(storage[index], storage[index+1]);
				strcpy(storage[index+1], temp);
			}
			else
			{
				//move on dont do anything
			}
		}
	}

}

int is_palindrome (char source[], int length, int index)
{
	int result = 0;
	if (index >= length)
	{
		return 1;
	}
	if (source[index] != ' ' && source[length] != ' ')
	{
		if(source[index] == source[length])
		{
			return is_palindrome(source, length - 1, index + 1);
		}
		else
			return 0;
	}
	else
	{
		while(1)
		{
			if (source[index] == ' ')
			{
				index++;
			}
			if (source[length] == ' ')
			{
				length--;
			}
			if (source[index] != ' ' && source[length] != ' ')
			{
				break;
			}
		}
		if(source[index] == source[length])
		{
			return is_palindrome(source, length - 1, index + 1);
		}
		else
			return 0;
	}
	return -1; 
}

int sum_primes (unsigned int n)
{
	int result = 0, temp = 0;
	if (n == 1 || n == 0)
	{
		result = 0;
	}
	else if (n == 2)
	{
		result = 2;
	}
	else
	{
		temp = is_prime (n);
		result = temp + sum_primes(n - 1);
	}
	return result;
}

int is_prime (int n)
{
	int counter = 2;
	if (n == 2)
	{
		return n;
	}
	while (counter < n)
	{
		if ((n % counter) == 0)
		{
			return 0;
		}
		counter++;
	}
	return n;

}

Occurrences *maximum_occurrences (char source[], Occurrences **info, int *most_occur, char *character, int length)
{
	Occurrences *first = NULL;
	int counter = 0, index = 0;
	char temp = '\0';
	first = *info;
	*most_occur = 0;
	*character = '\0';
	while (counter < length)
	{
		
		temp = source[counter];
		while (temp == '\0')
		{
			counter++;
			temp = source[counter];
			
		}
		(*info)->character = temp;
		while (index < length)
		{
			if (source[index] == temp)
			{
				(*info)->num_occurrences += 1;
				source[index] = '\0';
			}
			index++;
		}
		if ((*info)->num_occurrences > *most_occur)
		{
			*most_occur = (*info)->num_occurrences;
			*character = (*info)->character;
		}
		(*info)->frequency = (((double)(*info)->num_occurrences) / (length));
		(*info)->next = (Occurrences *) malloc ( sizeof (Occurrences));
		*info = (*info)->next;
		//Initialize everything to 0 or NULL
		(*info)->character = '\0';
		(*info)->frequency = 0.0;
		(*info)->next = NULL;
		(*info)->num_occurrences = 0;
		counter++;
		index = 0;
		
	}
	return first;
}

int smallest_sum_sequence (int arr[], int length)
{
	int counter = 0, index = 0, temp = 0, smallest = 0;
	smallest = arr[length - 2] + arr[length - 1];
	for (counter = 0; counter < length; counter++)
	{
		for (index = counter; index < length; index++)
		{
			temp += arr[index];
		}
		if (temp < smallest)
		{
			smallest = temp;
		}
		temp = 0;
	}
	return smallest;
}

//Bonus assignment
void max_consecutive_integers (int arr[][5], int row, int col, int *ptr, int **consecutive, int size, int *appear_times) //assume that the array will be size x size
{
	int current_number = 0, previous_number = 0, current_appear = 0, most_appear = 0, temp = 0, index = 0, *pointer = NULL, most_row = 0, most_col = 0;
	row = 0;
	col = 0;
	while (row < size)
	{
		current_number = arr[row][col];
		if (current_number == previous_number)
		{
			current_appear++;
		}
		else
		{
			if ((current_appear ) > most_appear)
			{
				most_appear = current_appear + 1;
				temp = previous_number;
				//*ptr = ((int) &previous_number) - (sizeof(int) * (most_appear - 1));
				if (col == 0)
				{
					most_row = row -1;
					most_col = 4;
				}
				else
				{
					most_row = row;
					most_col = col -1;
				}
			}
			current_appear = 0;	
		}

		col++;
		if (col == size)
		{
			row++;
			col = 0;
		}
		previous_number = current_number;
	}

	while (index < most_appear)
	{
		
		(*consecutive)[index] = arr[most_row][most_col];
		index++;
		most_col--;
		if (most_col < 0)
		{
			most_row--;
			most_col = 4;
		}
		if (index == (most_appear - 1))
		{
			*ptr = (int) (&arr[most_row][most_col]);
		}
	}
	*appear_times = most_appear;

}