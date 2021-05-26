#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "card.h"

using namespace std;

class player {
private:
	vector<card> current_hand {};
	string rclass;
	int points;
	bool in_game;

public:

	// default constructor  
	player();

	void show_hand();
	void add_card(card c);
	bool three_of_diamond();
	void sort_hand();
	void add_points(int p);
	void set_class(string s);
	bool is_playing();
	void player_in_out();
};