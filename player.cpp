#include "player.h"
#include <iostream>

using namespace std;

player::player() {
	this->current_hand.clear();
	this->points = 0;
	this->rclass = "commoner";
	this->in_game = true;
}

void player::show_hand() {
	int arrSize = current_hand.size();

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
	return in_game;
}

void player::player_in_out() {
	this->in_game = !this->in_game;
}