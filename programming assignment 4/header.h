
#define _CRT_SECURE_NO_WARNINGS
#ifndef PA4_H
#define PA4_H
#define max_length 100
#define dice1 "-----\n|   |\n| o |\n|   |\n-----"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_game_rules (void);
double get_bank_balance (double bank_balance);
double get_wager_amount (double bank_balance);
int check_wager_amount (double wager, double balance);
int roll_die (void);
int calculate_sum_dice (int die1_value, int die2_value);
int is_win_loss_or_point (int sum_dice);
int is_point_loss_or_neither (int point_value);
double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract);
void lobby (void);
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager);
#endif