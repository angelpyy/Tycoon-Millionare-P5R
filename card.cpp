//
//  card.cpp
//  tycoon command
//
//  Created by Angel Gutierrez on 7/23/21.
//

#include "card.hpp"
#include <iostream>
using namespace std;

card::card(string suit, int num, int value, bool special) {
    this->suit = suit;
    this->num = num;
    this->value = value;
    this->special = special;
    this->id = to_string(num) + suit[0];
}

card::card() {
    this->suit = "temp";
    this->num = 0;
    this->value = 0;
    this->special = true;
    this->id = to_string(num) + suit[0];
}

bool card::operator<(const card &rhs) const{
    return this->value < rhs.value;
}

void card::print_info() {
    cout << "Your current card is the " << num << " of " << suit << " and value of " << value << endl;
}

string card::get_id() {
    return id;
}

string card::get_suit() {
    return this->suit;
}

int card::get_num() {
    return this->num;
}

int card::get_value() {
    return this->value;
}

bool card::is_special() {
    return this->special;
}


