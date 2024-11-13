#include "random.h"
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct {
    string suit;
    string value;
    bool available;
} Cards;

Cards deck[52];
string suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
string values[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

void create_deck(void);
void print_hand(int num_cards, Cards hand[]);
void shuffle_deck(void);
void build_hand(int num_cards, Cards hand[]);

int main(void){
    system("clear");
    RANDOM_SEED;
    create_deck();
    shuffle_deck();

    int num_cards;
    do {
        num_cards = get_int("How many cards would you like? ");
    } while (num_cards < 1 || num_cards > 52);

    Cards hand[num_cards];
    build_hand(num_cards, hand);
    print_hand(num_cards, hand);
}

void create_deck(void){
    int index;
    for (int i = 0; i < 52; i = i + 1){
        index = i / 13;
        deck[i].suit = suits[index];
        deck[i].value = values[i % 13];
        deck[i].available = true;
    }
}

void print_hand(int num_cards, Cards hand[]){
    for (int i = 0; i < num_cards; i = i + 1){
        printf("%s of %s\n", hand[i].value, hand[i].suit);
    }
}


void shuffle_deck(void){
    Cards temp[52];
    int used_indices[52];
    int size_of_used = 0;
    int random_index;
    bool match_found;
    while (size_of_used < 52){
        match_found = false;
        random_index = get_random_integer_between(0,51);
        for (int i = 0; i < size_of_used; i = i + 1){
            if (random_index == used_indices[i]){
                match_found = true;
            }
        }
        if (!match_found){
            temp[size_of_used] = deck[random_index];
            used_indices[size_of_used] = random_index;
            size_of_used = size_of_used + 1;
        }
    }

    for(int j = 0; j < 52; j = j + 1){
        deck[j] = temp[j];
    }
}


void build_hand(int num_cards, Cards hand[]){
    for (int i = 0; i < num_cards; i = i + 1){
        for (int j = 0; j < 52; j = j + 1){
            if (deck[j].available) {
                hand[i] = deck[j];
                deck[j].available = false;
                break;
            }
        }
    }
}
