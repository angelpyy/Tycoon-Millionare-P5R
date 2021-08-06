//
//  Tycoon.hpp
//  tycoon command
//
//  Created by Angel Gutierrez on 7/23/21.
//

#ifndef Tycoon_hpp
#define Tycoon_hpp


#include "player.hpp"
#include "card.hpp"
using namespace std;

class Tycoon {
private:
    // fundamentals of game
    vector<card> deck;
    vector<player> players;
    vector<string> cards_in_play;
    //stat tracking
    int game_round = 0;
    int points[4] {30, 20, 10, 0};
public:
    //constructor
    // STICK DEFAULT RN Tycoon();
    int current_player = 0;
    int last_play = 0;
    
    // primary functions to make the gaem function
    // maaaaaaaaan i need to fix this cause bruh what
    void init_deck();
    void init_players();
    void shuffle_deck();
    void assign_player_hands();
    int locate_three_diamond();
    void init_game();
    
    
    void add_player_points();
    int num_currently_playing();
    void play_cards(int c);

    
    void print_deck();
    void print_player_hands();
    int round();
    
    void inc_round();
    
    void show_hand(int c);
    int num_cards(int c);
    bool player_in(int c);
    
    void reset();
};

#endif /* Tycoon_hpp */
