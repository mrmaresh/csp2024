#include "random.h"
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> //to use system("clear");
#include <string.h>

typedef struct {
    string name;
    int score;
} Player;

const int MAX_PLAYERS = 6;
Player players[MAX_PLAYERS];

int set_up_game(void);
void play_game(int num_players);
bool check_win(int num_players, int roll_score, int current_player);

int main(void) {
    int num_players = set_up_game();
    play_game(num_players);
    return 0;
}


int set_up_game(void){
    int num_players;
    do {
    num_players = get_int("Number of players: ");
    } while (num_players < 2 || num_players > 6);

    for(int i = 0; i < num_players; i = i + 1){
        players[i].name = get_string("Player %i name: ", i + 1);
        players[i].score = 0;
    }
    return num_players;
}


void play_game(int num_players){
    RANDOM_SEED; // This is so we can pick a random number
    int current_player = 0; //index of the 1st player
    string choice;
    int dice_roll;
    int roll_score = 0;
    bool game_over = false;

    while(!game_over){
        
        printf("Current player: %s\n", players[current_player].name);

        do{
            choice = get_string("Type \"roll\" to roll or type \"hold\" to hold.\n");
        } while (strcmp("roll", choice) != 0 && strcmp(choice, "hold") != 0);

        if (strcmp("roll", choice) == 0){
            dice_roll  = get_random_integer_between(1, 6);
            printf("You rolled %i\n", dice_roll);

            if (dice_roll != 1){
                roll_score = roll_score + dice_roll;
                printf("Turn total = %i\n", roll_score);
                game_over = check_win(num_players, roll_score, current_player);
            }
            else {
                roll_score = 0;
                current_player = (current_player + 1) % num_players;
            }
        }
        else {
            players[current_player].score = roll_score + players[current_player].score;
            current_player = (current_player + 1) % num_players;
            game_over = check_win(num_players, 0, current_player);
        }
    }
}


bool check_win(int num_players, int roll_score, int current_player){
    int temp;
    for (int i = 0; i < num_players; i = i + 1) {
        if (i == current_player) {
            temp = roll_score + players[i].score;
        }
        else {
            temp = players[i].score;
        }
        if (temp >= 100)
        {
            printf("The winner is %s!!!\n", players[i].name);
            return true;
        }
    }
    return false;

}
