//
//  main.cpp
//  tycoon command
//
//  Created by Angel Gutierrez on 7/23/21.
//
// I'm learning that xcode looks pretty but is kinda doggy bruh like what???? ? ?? ? maybe i dont know enough

// we going off of P5R Tycoon Millionare rules 1!!!11!1
// https://strangecastnews.com/tycoon-millionaire-persona-5-royal/
// this is going alright but I've got to find a better way to organize this

// TL;DR on how the game works: 4 players who each have 13-14 cards at hand. The goal of the game is to get rid of your cards as fast as possible by playing a stronger card than the previous player
// The ranking of the cards are as follow: 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A, 2, J
// however, special cards exist, for example, the player holding the three of diamonds must the game. or the three of spades is the only card that can trump the joker.
// there are more rules but I have yet to implement those

// all this code is so gross and messy bruh i obviously did not learn enough in oop

#include <iostream>
using namespace std;

// read up on circular referencing whatever stuff cause huh ???
#include "player.hpp"
#include "card.hpp"
#include "Tycoon.hpp"

int main(int argc, char *argv[]) {
    Tycoon game;
    game.init_game();
    game.current_player = game.locate_three_diamond();
    
    // loop to run the game we'll run the good ol switch statement
    int selection = -1;
    while (game.round() < 3) {
        // everything is set in place, players have a way of telling whether theyre active in game
        // players have a set of cards ranging from 13-14 cards at their hand,
        // all cards recognized as special by tycoon have been set (although not functional at the moment)
        // and we have found the player to start the game;
        // temp, but players start at 0 wouldnt be addressed as 1 becuase its giving me weird problems
        // maybe later i'll add to the class

        // add_player_points(players, point_array); ???? why did i write this

        // time to actually start yikers
        while (game.num_currently_playing() > 1) {
            // cout << "printing deck\n";
            // for (auto i = deck.begin(); i != deck.end(); i++) {
            //     i->print_info();
            // }
            // who will be playing a card ???
            // damn this wouldve been a great time to implement a queue huh, maybe a circular one that doesnt delete the previous element and just loops like forever until I remeove an element maybe hmmmmmmmm
            game.current_player = game.current_player % 4;
            selection = -1;

            cout << "It is currently player " << game.current_player + 1 << "'s turn!\n";
            cout << "Select an Option:\n";
            cout << "1) Play Turn\n";
            cout << "2) View Hand\n";
            cout << "3) Check Enemy Hand Size\n";
            cout << "0) Pass Turn\n";
            cout << "-1) Quit Game\n";
            // selection = -1;

            while (selection != 0) {
                
                if (game.player_in(game.current_player)){
                    cin >> selection;
                    switch (selection) {
                    case 1:
                        game.play_cards(game.current_player);
                        selection = 0;
                        break;
                    case 2:
                        game.show_hand(game.current_player);
                        break;
                    case 3:
                        cout << "Player " << (game.current_player + 1) % 4  + 1<< " has " << game.num_cards((game.current_player + 1) % 4) << " cards.\n";
                        cout << "Player " << (game.current_player + 2) % 4  + 1<< " has " << game.num_cards((game.current_player + 2) % 4) << " cards.\n";
                        cout << "Player " << (game.current_player + 3) % 4  + 1<< " has " << game.num_cards((game.current_player + 3) % 4) << " cards.\n";
                        break;
                    case 0:
                        break;
                    case -1:
                        exit(0);
                        break;
                    default:
                        cout << "Inavlid selection, womp womp.\n";
                        break;
                    }
                }
                else {
                    cout << "player is out for this round.\n;";
                }
            }

            cout << endl;
            // game.player_in_out();
            game.current_player++;
        }
        game.inc_round();
    }
}
