//
//  player.hpp
//  tycoon command
//
//  Created by Angel Gutierrez on 7/23/21.
//

#ifndef player_hpp
#define player_hpp

#include <string>
#include <vector>
#include <algorithm>
#include "card.hpp"
class card;
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
    int num_cards();
    bool card_validation(string a, int &i);
    card remove_card(int index);
    int val_at_idx(int index);
};

#endif /* player_hpp */
