#include "header.h"

// A bunch of rules
void print_game_rules (void)
{
	printf (" A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. the \"house\" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point.\" To win, you must continue rolling the dice until you \"make your point.\" The player loses by rolling a 7 before making the point.Enough with the rules, let's play.\n\n");
}

double get_bank_balance (double bank_balance)// add bank_balance
{
	double temp = 0.0;
	printf("How much you want to add?\n");
	scanf (" %lf", &temp);
	return bank_balance + temp;
}

double get_wager_amount (double bank_balance)// get wager
{
	double wager = 0.0;
	char choice = '\0';


	printf("Your balance is: %lf\nHow much you want to bet? \n", bank_balance);
	scanf (" %lf", &wager);
	return wager;
}

int check_wager_amount (double wager, double balance) // Check if the wager is more than bank_balance
{
	double deficit = 0.0;
	deficit = balance - wager;
	if (deficit >= 0)
		return 1;
	else if (deficit < 0)
	{
		printf("Sorry, you don't have enough money, mate\n");
		return 0;
	}
	else
	{
		printf("There is an unknown error occur, system terminated!\n");
		exit(EXIT_SUCCESS);
	}

}

int roll_die (void) // Roll die
{
	int temp = 0;
	temp = (rand () % 6) + 1;
	return temp;
}

int calculate_sum_dice (int die1_value, int die2_value) // calculate the sum of the dice
{
	return die1_value + die2_value;
}

int is_win_loss_or_point (int sum_dice)
{
	int is_point_win = 0, point_value = sum_dice;
	if (sum_dice == 7 || sum_dice == 11) // if win
	{
		printf("Dude, you just won\n");
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12 ) // if lose
	{
		printf("Craps!\n");
		return 0;
	}
	else // if point
	{
		printf("point\n");
		is_point_win = is_point_loss_or_neither (point_value); // call this function
		if  (is_point_win == 1)
			return -1;
		else 
			return -2;
	}
}

int is_point_loss_or_neither (int point_value) // this function check of the point is win or lost
{
	int die1 = 0, die2 = 0, sum = 0;
	while (1)
	{
		die1 = roll_die (); // roll
		die2 = roll_die (); // roll
		sum = die1 + die2; // sum them up
		printf ("You rolled %d and %d, which is %d\n",die1, die2, sum);
		if ( sum == point_value) // if the sum of the new roll appear before 7 then the user win
		{
			printf ("You just won!\n");
			return 1;
		}
		else if (sum == 7)
		{
			printf("You just lost!\n");
			return 0;
		}
			
		else
			continue;
	}
	

}

double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
{
	double new_balance = 0.0;
	if (add_or_subtract == 1) // win
	{
		new_balance = bank_balance + wager_amount;
		return new_balance;
	}
	else if (add_or_subtract == 0) // lost
	{
		new_balance = bank_balance - wager_amount;
		return new_balance;
	}
	else if (add_or_subtract == -1) // point , then win
	{
		new_balance = bank_balance + wager_amount;
		return new_balance;
	}
	else if (add_or_subtract == -2) // point, then lost
	{
		new_balance = bank_balance - wager_amount;
		return new_balance;
	}

	else // just in case anything weird uccur
		printf("unknown\n");
		return new_balance;
}

void lobby (void)
{
	//Declare all the varibles need for the game
	int die1 = 0, die2 = 0, choice = 0, able_or_not = 0, sum_of_dice = 0, is_win = 0, win_counter = 0, number_rolls = 0;
	double bank_balance = 0.0, wager = 0.0, initial_bank_balance = 0.0, current_bank_balance = 0.0;
	char add_chip = '\0';

	srand ((unsigned int) time(NULL));
	print_game_rules(); //first time play, print game rule
	// first time play, get bank balance
	printf("Please add some balance, ");
	bank_balance = get_bank_balance(bank_balance); 
	initial_bank_balance = bank_balance; // For chatter_messages
	do
	{
			wager = get_wager_amount (bank_balance);//see how much the user want to bet
			able_or_not = check_wager_amount (wager, bank_balance);//Check if the player have enough chip to play
			if (able_or_not == 1)//play if enough chip
			{
				die1 = roll_die();// roll the first die
				die2 = roll_die();// roll the second die
				printf("You rolled : %d and %d which is %d\n", die1, die2, die1 + die2);
				sum_of_dice = calculate_sum_dice (die1, die2); // Calculate the sum of the dice
				is_win = is_win_loss_or_point (sum_of_dice); // check if the player win 1 for win, 0 for lose , and -1 for point win, -2 for point lost
				bank_balance = adjust_bank_balance (bank_balance, wager, is_win); // adjust new balance
			}
		
			else // If not enough chip, ask if the user want to add more chip
			{
				printf ("Do you want to add more chips?(y/n)\n");
				scanf(" %c", &add_chip);
				switch (add_chip)
				{
					case 'y':
						bank_balance = get_bank_balance(bank_balance);// If yes, then add more chip
						break;
					case 'n':
						printf("Sorry, you don't have enough chips, Please make another bet\n"); // If not, repeat the loop
						//exit(EXIT_SUCCESS);
						break;
					default:
						printf("unknown input, system terminated\n");// All unknown input will make the program exit
						exit(EXIT_SUCCESS);
				}
			//values tracker for chatter messages function
			
			}
			//These values for random messages
			number_rolls++;
			win_counter = is_win;
			current_bank_balance = bank_balance;
			//Random messages
			chatter_messages (number_rolls, win_counter, initial_bank_balance, current_bank_balance, wager);
			// At the end of the game ask if user want to continue or cash out
			printf("What do you want to do?\n1/Keep going\n2/Quit, Cash Out\n");
			scanf(" %d", &choice);
			switch (choice)
			{
			case 1: // If the player want to play, clear the screen and repeat the loop
				system("cls");
				break;
			case 2: //End the program if the player want to stop
				printf("Thank you for playing see you later\n");
				exit (EXIT_SUCCESS);
				break;
			default: // All unknown input will make the program exit
				printf("unknown input, system terminated\n");
				exit(EXIT_SUCCESS);
			}

	}while (choice !=2); // Loop will end if the user want to cash out
}

// Random chat messages
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager)
{
	if (number_rolls == 5 || number_rolls == 10 || number_rolls == 15 || number_rolls == 20 || number_rolls == 25 || number_rolls ==30 )
	{
		printf("Think about cash out?\n");
	}
	if (win_loss_neither >= 3)
	{
		printf("You win too much, let me check your hand\n");
	}
	if (win_loss_neither <= -2)
	{
		printf("You have no luck today\n");
	}
	if (initial_bank_balance <= 1000)
	{
		printf("Come on, deposit more to win big\n");
	}
	if (current_bank_balance >= 3000)
	{
		printf ("You're so rich\n");
	}
	if (current_bank_balance <= 100)
	{
		printf ("You're about to out of chip!\n");
	}
	if (wager <= 10)
	{
		printf("Come on, bet big to win big!\n");
	}
	if (wager >= 200)
	{
		printf("Let win big!\n");
	}
}



