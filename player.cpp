//
//  player.cpp
//  tycoon command
//
//  Created by Angel Gutierrez on 7/23/21.
//

#include "player.hpp"
#include <iostream>

using namespace std;

player::player() {
    this->current_hand.clear();
    this->points = 0;
    this->rclass = "commoner";
    this->in_game = true;
}

void player::show_hand() {
    // int arrSize = current_hand.size();

    for (auto i = current_hand.begin(); i != current_hand.end(); i++) {
        i->print_info();
    }
}

void player::add_card(card c) {
    this->current_hand.push_back(c);
}

bool player::three_of_diamond() {
    for (int i = 0; i < current_hand.size(); i++) {
        if (current_hand[i].get_suit() == "Diamonds" && current_hand[i].get_num() == 3) {
            return true;
        }
    }

    return false;
}

void player::sort_hand() {
    sort(current_hand.begin(), current_hand.end());
}

void player::add_points(int p) {
    this->points += p;
}


void player::set_class(string s) {
    this->rclass = s;
}

bool player::is_playing() {
    if (this->num_cards() == 0 && this->in_game) {
        this->player_in_out();
    }
    
    return in_game;
}

void player::player_in_out() {
    this->in_game = !this->in_game;
}

int player::num_cards() {
    return current_hand.size();
}

bool player::card_validation(string a, int &i) {
    for (i = 0; i < this->num_cards(); i++) {
        if (this->current_hand[i].get_id() == a) {
            return true;
        }
    }
    return false;
}

card player::remove_card(int index) {
    card temp = current_hand[index];
    current_hand.erase(current_hand.begin() + index);
    return temp;
}

int player::val_at_idx(int index) {
    return current_hand[index].get_value();
}
