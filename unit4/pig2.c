#include "random.h"
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    string name;
    int score;
} Player;

const int MAX_PLAYERS = 6;
Player players[MAX_PLAYERS];

int set_up_game(int num_players);
void play_game(int num_players);
void update_score_board(int num_players, int current_player, int turn_total, int dice_roll);
bool check_for_winner(int num_players);

int main(void) {
    int num_players = 0;
    num_players = set_up_game(num_players);
    play_game(num_players);
    return 0;
}

int set_up_game(int num_players){
    //Getting the number of players
    while (num_players < 2 || num_players > MAX_PLAYERS){
        printf("You must select between 2 and 6 players.\n\n");
        num_players = get_int("How many players? ");
    }

    //Getting the names of the players
    for (int i = 0; i < num_players; i = i + 1){
        players[i].name = get_string("Player %i name: ", i + 1);
        players[i].score = 0;
    }

    return num_players;
}


void play_game(int num_players){
    RANDOM_SEED; // allows us to use the random functions
    int current_player = 0; // index of the first player
    int dice_roll = 0;
    int turn_total = 0;
    char decision;
    bool game_play = true;

    while(game_play){
        update_score_board(num_players, current_player, turn_total, dice_roll);

        do {
            decision = get_char("Press \"r\" for roll or \"h\" for hold: ");
        } while (decision != 'r' && decision != 'h');

        if (decision == 'r'){
            dice_roll = get_random_integer_between(1,6);
            update_score_board(num_players, current_player, turn_total, dice_roll);
            if (dice_roll != 1) {
                turn_total = turn_total + dice_roll;
                update_score_board(num_players, current_player, turn_total, dice_roll);
            }
            else {
                game_play = check_for_winner(num_players);
                current_player = (current_player + 1) % num_players;
                update_score_board(num_players, current_player, turn_total, dice_roll);
                printf("You rolled a 1.  Next player!\n");
                sleep(1);
                dice_roll = 0;
                turn_total = 0;

            }
        }
        else {
            players[current_player].score = players[current_player].score + turn_total;
            game_play = check_for_winner(num_players);
            current_player = (current_player + 1) % num_players;
            dice_roll = 0;
            turn_total = 0;
        }

    }
    return;
}


void update_score_board(int num_players, int current_player, int turn_total, int dice_roll){
    system("clear");
    printf("_____________________________________________________________________\n\n");
    printf("%-10s", "NAME: ");
    for (int i = 0; i < num_players; i = i + 1){
        printf("%-12s", players[i].name);
    }
    printf("\n");
    printf("%-10s", "SCORE: ");
    for (int i = 0; i < num_players; i = i + 1){
        printf("%-12i", players[i].score);
    }
    printf("\n");
    printf("_____________________________________________________________________\n\n");

    printf("Current Player: %s\n", players[current_player].name);
    printf("Turn Total: %i\n", turn_total);
    if (dice_roll != 0){
        printf("You rolled: %i\n", dice_roll);
    }
}



bool check_for_winner(int num_players) {
    for (int i = 0; i < num_players; i = i + 1){
        if (players[i].score >= 100){
            printf("\n\n\n%s is the winner!!!\n\n\n", players[i].name);
            return false;
        }
    }
    return true;
}



