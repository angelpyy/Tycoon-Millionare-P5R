#include "card.h"
#include <iostream>

using namespace std;

card::card(string suit, int num, int value, bool special) {
	this->suit = suit;
	this->num = num;
	this->value = value;
	this->special = special;
}

bool card::operator<(const card &rhs) {
	if (this->value < rhs.value) {
		return true;
	}
	return false;
}

void card::print_info() {
	cout << "Your current card is the " << num << " of " << suit << " and value of " << value << endl;
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