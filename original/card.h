#pragma once

#include <string>
class player;
using namespace std;

class card {
private:
	string suit;
	int num;
	int value;
	bool special;
public:
	// constructor
	card(string suit, int num, int value, bool special);

	// operator overload for sort algorithm (as opposed to doing it myself bc lazy)
	bool operator<(const card& lhs);

	void print_info();
	string get_suit();
	int get_num();
	int get_value();
	bool is_special();
};
