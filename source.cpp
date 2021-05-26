// we going off of P5R Tycoon Millionare rules 1!!!11!1
// https://strangecastnews.com/tycoon-millionaire-persona-5-royal/
// this is going alright but I've got to find a better way to organize this


// TL;DR on how the game works: 4 players who each have 13-14 cards at hand. The goal of the game is to get rid of your cards as fast as possible by playing a stronger card than the previous player
// The ranking of the cards are as follow: 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A, 2, J
// however, special cards exist, for example, the player holding the three of diamonds must the game. or the three of spades is the only card that can trump the joker.
// there are more rules but I have yet to implement those

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

// read up on circular referencing whatever stuff cause huh ???
#include "player.h"
#include "card.h"

// def main game run functions
void init_deck(vector<card> &vect);
void init_players(vector<player> &vect);
void shuffle_deck(vector<card> &vect);
void assign_player_hands(vector<card> &c_vect, vector<player> &p_vect);
int locate_three_diamond(vector<player> &vect);
void add_player_points(vector<player>& vect, int points[]);
int num_currently_playing(vector<player>& vect);


int main()
{
    vector<card> deck;
    vector<player> players;

    // cant create new object each time 
    init_players(players);

    int game_round = 0;
    int point_array[4] { -1, -1, -1, -1 };
    int current_player = 0;

    /*
    init_deck(deck);
    init_players(players);

    shuffle_deck(deck);

    
    // print out the deck to ensure it all works

    for (auto i = deck.begin(); i != deck.end(); i++) {
        i->print_info();
    }
    cout << endl << endl;
    

    assign_player_hands(deck, players);

    // print out player hands to view initial state
    for (auto i = players.begin(); i != players.end(); i++) {
        i->show_hand();
        cout << endl;

        // after i've printed each hand sort it and print it to compare(as to avoid making another loop)
        i->sort_hand();
        i->show_hand();
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    }
    // it all looks to be working very much as intended thankfully.
    */

    while (game_round < 3) {
        // everything is set in place, players have a way of telling whether theyre active in game
        // players have a set of cards ranging from 13-14 cards at their hand, 
        // all cards recognized as special by tycoon have been set (although not functional at the moment)
        // and we have found the player to start the game;

        add_player_points(players, point_array);

        init_deck(deck);
        assign_player_hands(deck, players);

        current_player = locate_three_diamond(players);

        // time to actually start yikers
        while (num_currently_playing(players) > 1) {
            // who will be playing a card ???
            // damn this wouldve been a great time to implement a queue huh, maybe a circular one that doesnt delete the previous element and just loops like forever until I remeove an element maybe hmmmmmmmm
            current_player = current_player % 4;

            cout << "It is currently player " << current_player + 1 << "'s turn!\n";
            cout << "Select an Option:\n";
            cout << "future to be inserted switch statement which will then have functions attached to each case as well nice.\n";

            cout << endl;
            players[current_player].player_in_out();
            current_player++;
        }

        game_round++;
    }

}

void init_deck(vector<card> &vect) {
    // clear the deck to ensure there are no dupes
    vect.clear();

    for (int i = 0; i < 13; i++) {
        string suit = "Spades";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8 || num == 3) {
            special = true;
        } 

        card temp(suit, num, val, special);
        vect.push_back(temp);
    }

    for (int i = 0; i < 13; i++) {
        string suit = "Diamonds";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8 || num == 3) {
            special = true;
        }

        card temp(suit, num, val, special);
        vect.push_back(temp);
    }

    for (int i = 0; i < 13; i++) {
        string suit = "Clubs";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8) {
            special = true;
        }

        card temp(suit, num, val, special);
        vect.push_back(temp);
    }

    for (int i = 0; i < 13; i++) {
        string suit = "Hearts";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8) {
            special = true;
        }

        card temp(suit, num, val, special);
        vect.push_back(temp);
    }

    // insert the joker cards which are used in the game
    card jok1("Joker", 0, 13, true);
    card jok2("Joker", 0, 13, true);

    vect.push_back(jok1);
    vect.push_back(jok2);
}

void init_players(vector<player>& vect) {
    // create the player objects
    player p1;
    player p2;
    player p3;
    player p4;

    // assuming this adds them as {p1, p2, p3, p4}
    vect.insert(vect.end(), { p1, p2, p3, p4 });
}

void shuffle_deck(vector<card> &vect) {
    // randomize the set of cards
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(vect.begin(), vect.end(), default_random_engine(seed));
}

void assign_player_hands(vector<card> &c_vect, vector<player> &p_vect) {
    // grab random element, swap with the end, and remove from the end. alt is create a randomizer function which is betetr
    shuffle_deck(c_vect);
    int count = 0;

    while (!c_vect.empty()) {
        p_vect[count % 4].add_card(c_vect.back());
        c_vect.pop_back();

        count++;
    }
}

int locate_three_diamond(vector<player> &vect) {
    int index = 0;

    for (int i = 0; i < vect.size(); i++) {
        if (vect[i].three_of_diamond()) {
            return index;
        }
        index++;
    }

    cout << "if you're reading this there's been a mistake !!!\n";
    return -255;
}

void add_player_points(vector<player>& vect, int points[]) {
    if (points[0] == -1) {
        return;
    }

    // worry about it later, you cant even get one round going lmao
    vect[points[0]].add_points(30);
    vect[points[0]].set_class("tycoon");
    vect[points[0]].player_in_out();

    vect[points[1]].add_points(20);
    vect[points[1]].set_class("rich");
    vect[points[1]].player_in_out();

    vect[points[2]].add_points(10);
    vect[points[2]].set_class("poor");
    vect[points[2]].player_in_out();

    vect[points[3]].add_points(0);
    vect[points[3]].set_class("beggar");
    vect[points[3]].player_in_out();

    // reset the array to make sure past points dont go to next round and to make sure i dont f* up 
    for (int i = 0; i < 4; i++) {
        points[i] = -1;
    }
}

int num_currently_playing(vector<player> &vect) {
    int count = 0;
    
    for (int i = 0; i < 4; i++) {
        if (vect[i].is_playing()) {
            count++;
        }
    }
    
    return count;
}