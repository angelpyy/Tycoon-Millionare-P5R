//
//  card.hpp
//  tycoon command
//
//  Created by Angel Gutierrez on 7/23/21.
//

#ifndef card_hpp
#define card_hpp

#include <string>
class player;
using namespace std;

class card {
private:
    string id;
    string suit;
    int num;
    int value;
    bool special;
public:
    // constructor
    card(string suit, int num, int value, bool special);
    card();

    // operator overload for sort algorithm (as opposed to doing it myself bc lazy)
    bool operator<(const card& rhs) const;
    
    void print_info();
    string get_suit();
    int get_num();
    int get_value();
    bool is_special();
    string get_id();
};


#endif /* card_hpp */
