//
//  Tycoon.cpp
//  tycoon command
//
//  Created by Angel Gutierrez on 7/23/21.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>
#include "Tycoon.hpp"
using namespace std;

void Tycoon::init_deck() {
    // clear the deck to ensure there are no dupes
    this->deck.clear();

    for (int i = 0; i < 13; i++) {
        string suit = "Spades";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8 || num == 3) {
            special = true;
        }

        card temp(suit, num, val, special);
        this->deck.push_back(temp);
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
        this->deck.push_back(temp);
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
        this->deck.push_back(temp);
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
        this->deck.push_back(temp);
    }
    
    // insert the joker cards which are used in the game
    card jok1("Joker", 0, 13, true);
    card jok2("Joker", 0, 13, true);

    this->deck.push_back(jok1);
    this->deck.push_back(jok2);
}

void Tycoon::init_players() {
    // create the player objects
    player p1;
    player p2;
    player p3;
    player p4;

    // assuming this adds them as {p1, p2, p3, p4}
    this->players.insert(this->players.end(), {p1, p2, p3, p4});
}
    
void Tycoon::shuffle_deck() {
    // randomize the set of cards
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(this->deck.begin(), this->deck.end(), default_random_engine(seed));
}

void Tycoon::assign_player_hands () {
    // grab random element, swap with the end, and remove from the end. alt is create a randomizer function which is betetr
    shuffle_deck();
    int count = 0;

    while (!this->deck.empty()) {
        this->players[count % 4].add_card(this->deck.back());
        this->deck.pop_back();

        count++;
    }
}

int Tycoon::locate_three_diamond() {
    // just return i????
    int index = 0;

    for (int i = 0; i < this->players.size(); i++) {
        if (this->players[i].three_of_diamond()) {
            return index;
        }
        index++;
    }

    cout << "if you're reading this there's been a mistake !!!\n";
    return -255;
}

void Tycoon::add_player_points() {
    if (this->points[0] == -1) {
        return;
    }

    // worry about it later, you cant even get one round going lmao
    // assuming i set is_game to false for this, pop their index into points array in descending order (1st, 2nd ... )
    // set in_game back to true
    this->players[points[0]].add_points(30);
    this->players[points[0]].set_class("tycoon");
    this->players[points[0]].player_in_out();

    this->players[points[1]].add_points(20);
    this->players[points[1]].set_class("rich");
    this->players[points[1]].player_in_out();

    this->players[points[2]].add_points(10);
    this->players[points[2]].set_class("poor");
    this->players[points[2]].player_in_out();

    this->players[points[3]].add_points(0);
    this->players[points[3]].set_class("beggar");
    this->players[points[3]].player_in_out();

    // reset the array to make sure past points dont go to next round and to make sure i dont f* up
    for (int i = 0; i < 4; i++) {
        points[i] = -1;
    }
}

int Tycoon::num_currently_playing() {
    int count = 0;
    
    for (int i = 0; i < 4; i++) {
        if (this->players[i].is_playing()) {
            count++;
        }
    }
    
    return count;
}

// this is the hardest part out of everything man i hate this shit right here
// i'll get it tho
// and i need to add comments that dont look like trash and make sense
void Tycoon::play_cards(int c) {
    // we are trying again
    
    int idx = 0;
    int num_cards = 0;
    string parse[4];
    
    cout << "how many cards would you like to play? (cards played must equal same amount as previous player. UNless new turn.)\n";
    while (true) {
        cin >> num_cards;
        if (num_cards > 0 && num_cards < 5) { break; }
        cout << " num: 1-4 pls\n";
    }
    
    
    cout << "Enter the cards you would like to play as follows: (ex: Joker == 0J, 3 of Diamonds == 3D, K of Spades== 13S)\n";
    for (int i = 0; i < num_cards; i++) {
        while (true) {
            cin >> parse[i];
            if (players[current_player].card_validation(parse[i], idx)) {
                break;
            }
            cout << "Invalid selection. Card does not exist or is not in your hand.\n";
        }
    }
    
    // okay very valid inputs and we have all our cards to be played now what we'll figure it out tomrrow lolz
    
    // it did not work
    // god this is gonna be the hardest part im gonna cry
    // int idx;
    // int to_be_played = 0;
    //
    // i probably dont need this array ill fix it later doe
    //string to_parse[4];
    //
    // i should consider a switch statement in case lets say like they decide they dont wanna play the card but wanna go back to selection or maybe
    // they goof it up a bit
    // cout << "how many cards would you like to play?? ? ?\n";
    // cin >> to_be_played;
    //
    //cout << endl << "follow the following format pleasepleasepleaseplease\nSelect your cards: (ex: Joker == 0J, 3 of Diamonds == 3D, K of
    // Spades== 13S)\n";
    //
    // for (int i = 0; i < to_be_played; i++) {
    //     bool sus = true;
    //
    //    while (sus) {
    //         cin >> to_parse[i];
    //
    //         if (players[current_player].card_validation(to_parse[i], idx) &&
    //             last_played[i].get_value() == players[current_player].val_at_idx(idx)) {
    //             //wow please work not done tho.
    //             sus = false;
    //             last_played[i] = players[current_player].remove_card(idx);
    //
    //             // man wtf is this even for who does it help
    //             cards_in_play.push_back(to_parse[i]);
    //         }
    //     }
    // }
    // this is so much harder than just these weird inputs.
    
}

void Tycoon::init_game() {
    this->init_deck();
    this->init_players();
    // this->print_deck();
    this->shuffle_deck();
    this->assign_player_hands();
    
    for (auto i = players.begin(); i != players.end(); i++) {
        i->sort_hand();
    }
}

void Tycoon::print_deck() {
    for (auto i = deck.begin(); i != deck.end(); i++) {
         i->print_info();
     }
     cout << endl << endl;
}

void Tycoon::print_player_hands() {
    // print out player hands to view initial state
        for (auto i = players.begin(); i != players.end(); i++) {
            i->show_hand();
            cout << endl;

            // after i've printed each hand sort it and print it to compare(as to avoid making another loop)
            i->sort_hand();
            i->show_hand();
            cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        }

}

int Tycoon::round() {
    return game_round;
}

void Tycoon::inc_round() {
    game_round++;
}

void Tycoon::show_hand(int c) {
    this->players[c].show_hand();
}

int Tycoon::num_cards(int c) {
    return this->players[c].num_cards();
}

bool Tycoon::player_in(int c) {
    return this->players[c].is_playing();
}

void Tycoon::reset() {
    // this->last_played = {card(), card(), card(), card()};
}
