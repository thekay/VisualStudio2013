#include "header.h"

int main (void)
{
	int temp = 0, player_hits = 0, player_misses = 0, computer_hits = 0, computer_misses = 0;
	char player[10][10] = {'\0'}, computer[10][10] = {'\0'};
	FILE *logfile = NULL;
	Stats playerstats, computerstats;
	logfile = fopen("logfile.dat", "w");
	srand ((unsigned int) time(NULL));
	welcome_screen();
	printf("Hit enter to continue.\n");
	getchar();
	system("cls");
	initializer (player, 10); //assign all the vualues to '-'
	initializer (computer, 10); //assign all the vualues to '-'
	
	//Ask the user if they want to manually place the ship or randomly place them and
	//check if the input is valid
	random_or_manually (&temp);
	// 1 for enter manually
	if (temp == 1)
	{
		place_manually(player, 10);
	}
	// 2 for enter randomly
	else
	{
		place_randomly(player, 10);
	}
	
	//And then randomly assign ships position for computer
	place_randomly(computer, 10);
	//printout2 (player, computer, 10);


	//Now determine who will go first
	temp  = rand() % 2;
	fprintf(logfile, "Game start\n");
	if(temp == 0)
	{
		fprintf (logfile,"Player go first\n");
	}
	else
	{
		fprintf (logfile, "Computer go first\n");
	}
	//Lobby is where all the actions happen
	temp = lobby(player, computer, 10, temp, logfile, &player_hits, &player_misses, &computer_hits, &computer_misses);

	//Now check to see who win
	if (temp == 0)//then player win
	{
		printf("Congratulation, you win the game\n");
		fprintf(logfile,"Player won\n");
	}
	else //then computer win
	{
		printf("You lost!\n");
		fprintf(logfile,"Computer won\n");
	}

	//printf("player plays: %d\ncomputer play: %d\n", player_hits + player_misses, computer_hits + computer_misses);
	//Update all the statistic
	playerstats.shots = player_hits + player_misses;
	computerstats.shots = computer_hits + computer_misses;
	playerstats.hits = player_hits;
	playerstats.misses = player_misses;
	computerstats.hits = computer_hits;
	computerstats.misses = computer_misses;
	playerstats.hits_percentage =((double) playerstats.hits / playerstats.shots) * 100;
	playerstats.misses_percentage =((double)playerstats.misses / playerstats.shots) * 100;
	computerstats.hits_percentage =((double) computerstats.hits / computerstats.shots) * 100;
	computerstats.misses_percentage =((double) computerstats.misses / computerstats.shots) * 100;

	//now output those stats to logfile.dat
	fprintf(logfile, "----------------------------------------------------------\nStatistics\n\n");
	fprintf(logfile, "Player\ntotal shots: %d\nhit: %d\nmisses: %d\nratio(hits to misses): %.3lf%% : %.3lf%%\n", playerstats.shots, playerstats.hits, playerstats.misses,playerstats.hits_percentage, playerstats.misses_percentage);
	fprintf(logfile, "\nComputer\ntotal shots: %d\nhit: %d\nmisses: %d\nratio(hits to misses): %.3lf%% : %.3lf%%\n",computerstats.shots, computerstats.hits, computerstats.misses, computerstats.hits_percentage,computerstats.misses_percentage);
	fclose(logfile);
	return 0;
}