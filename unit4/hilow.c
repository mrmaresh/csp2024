#include "random.h"
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct{
    string name;
    bool eliminated;
} Player;

const int MAX_PLAYERS = 10;
Player players[MAX_PLAYERS];
string display[MAX_PLAYERS + 1][2];

void play_game(int num_players);
void update_screen(int num_players, int dice_roll);
int set_up_game(void);
void build_display(int num_players);
void question_player(int player_index, int dice_roll, int next_dice_roll);
bool check_game_over(int num_players);

int main(void){
    RANDOM_SEED;
    int num_players = set_up_game(); //sets up game and returns num of players
    play_game(num_players);
}


// gets number of players and stores names
int set_up_game(void){
    system("clear");
    int num_players;
    display[0][0] = "IN GAME:";
    display[0][1] = "ELIMINATED:";
    do{
        num_players = get_int("How many players? ");
    } while (num_players > 10 || num_players < 2);

    for (int i = 0; i < num_players; i = i + 1){
        players[i].name = get_string("Player %i name: ", i + 1);
        players[i].eliminated = false;
    }
    build_display(num_players);
    return num_players;
}


// updates the display table separating those still in the game
void build_display(int num_players){
    int in_game_index = 1;
    int eliminated_index = 1;
    for (int i = 1; i <= num_players; i = i + 1){
        display[i][0] = "";
        display[i][1] = "";
        if (players[i - 1].eliminated){
            display[eliminated_index][1] = players[i - 1].name;
            eliminated_index = eliminated_index + 1;
        }
        else{
            display[in_game_index][0] = players[i - 1].name;
            in_game_index = in_game_index + 1;
        }
    }
}

// This displays current data on the screen
void update_screen(int num_players, int dice_roll){
    system("clear");
    for (int i = 0; i <= num_players; i = i + 1){
            printf("%-30s %-30s\n", display[i][0], display[i][1]);
    }
    printf("\n\n\n");

    if (!check_game_over(num_players)){
        printf("Dice roll = %i\n", dice_roll);
        printf("Will the next roll be above or below?\n\n");
    }
    else {
        printf("We have a winner!!!\n\n\n\n");
    }


}

// Game play
void play_game(int num_players){
    int dice_roll = get_random_integer_between(1,6);
    int next_dice_roll;

    while(!check_game_over(num_players)){
        update_screen(num_players, dice_roll);
        next_dice_roll = get_random_integer_between(1,6);
        for (int i = 0; i < num_players; i = i + 1){
            if (!players[i].eliminated){
                question_player(i, dice_roll, next_dice_roll);
            }
        }
        build_display(num_players);
        dice_roll = next_dice_roll;
    }

    update_screen(num_players, dice_roll);

}

// Questions player and eliminates if wrong
void question_player(int player_index, int dice_roll, int next_dice_roll){
    char response;
    do{
        response = get_char("%s: Above (\"a\") or Below (\"b\")? ", players[player_index].name);
    }while(response != 'a' && response != 'b');

    bool incorrect1 = (response == 'a' && (next_dice_roll < dice_roll));
    bool incorrect2 = (response == 'b' && (next_dice_roll > dice_roll));

    if (incorrect1 || incorrect2){
            players[player_index].eliminated = true;
        }
}

// Checks if there is only one player left
bool check_game_over(int num_players){
    int count = 0;
    for (int i = 0; i < num_players; i = i + 1){
        if (!players[i].eliminated) {
            count = count + 1;
        }
    }
    return count == 1;
}
