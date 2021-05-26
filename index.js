// card val goes from 0 - 13
// 3 of spades can only be used to beat a joker, my current set up does not account for that
// python and javascript really make me appreciate defining each variables data type :(
// jesus accepting terminal input is much more troublesome than i anticipated in node

const { read } = require('fs');
const { rawListeners } = require('process');
const prompt = require('prompt-sync')({ sigint: true });
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

class Player {
    constructor(hand, points = 0, sclass = "commoner") {
        this.sclass = sclass;
        this.hand = hand;
        this.points = points;
    }

    show_hand() {
        for (i = 0; i < cast.length; i++) {
            console.log(cast[i].hand);
        }
    }
}

// num vs value ex: 2 of hearts will have num = 2 and value = 13
class Card {
    constructor(suit, num, value, special) {
        this.suit = suit;
        this.num = num;
        this.value = value;
        this.special = special;
    }

    print_info() {
        console.log("Your current card is the " + this.num + " of " + this.suit)
    }
}

// function to initialize the deck and reset hands
function init_deck(deck) {

    // clear the deck for recurring rounds, don't wanna have extra data to mess the flow
    var temp = deck.length;
    for (i = 0; i < temp; i++) {
        deck.pop();
    }

    // for loops for each card suit
    for (i = 0; i < 13; i++) {
        var card_name = "spades_" + (1 + i);
        var val = 11 + i;
        var special = false;

        if (i == 2) { // implies the 3 of spades strongest card in the game
            special = true;
            val = 14
        }
        else if (i == 7) { // implies the 8 card, or a cut
            special = true;
        }

        // time to do some mod math lets go
        deck.push(card_name = new Card("Spades", 1 + i, val % 13, special))
    }
    for (i = 0; i < 13; i++) {
        var card_name = "diamonds_" + (1 + i);
        var val = 11 + i;
        var special = false;

        if (i == 2) { // implies the 3 of diamonds, starts off the game
            special = true;
        }
        else if (i == 7) { // implies the 8 card, or a cut
            special = true;
        }

        // time to do some mod math lets go
        deck.push(card_name = new Card("Diamonds", 1 + i, val % 13, special))
    }
    for (i = 0; i < 13; i++) {
        var card_name = "clubs_" + (1 + i);
        var val = 11 + i;
        var special = false;

        if (i == 7) { // implies the 8 card, or a cut
            special = true;
        }

        // time to do some mod math lets go
        deck.push(card_name = new Card("Clubs", 1 + i, val % 13, special))
    }
    for (i = 0; i < 13; i++) {
        var card_name = "hearts_" + (1 + i);
        var val = 11 + i;
        var special = false;

        if (i == 7) { // implies the 8 card, or a cut
            special = true;
        }

        // time to do some mod math lets go
        deck.push(card_name = new Card("Hearts", 1 + i, val % 13, special))
    }
    // manually append the two joker cards bc it seems eSasier
    deck.push(joker_1 = new Card("Joker", 0, 13, true));
    deck.push(joker_2 = new Card("Joker", 0, 13, true));

    return 0;
}

function init_players(cast) {
    
    //clear data
    var temp = cast.length;
    for (i = 0; i < temp; i++) {
        cast.pop();
    }

    // init our 4 objects
    for (i = 0; i < 4; i++) { 
        var player_name = "player_" + (i+1);

        player_name = new Player([], 0, "commoner");
        cast[i] = player_name;
    }

}

// function to randomly "shuffle" the deck and split the cards amongst the players
function assign_hands(deck, cast) {
    var card_count = 54;
    for (i = 0; i < 54; i++) {
        var rand = Math.floor(Math.random() * card_count);

        cast[i % 4].hand.push(deck[rand]);
        deck.splice(rand, 1);

        card_count--;
    }

    /*
    for (i = 0; i < cast.length; i++) {
        console.log(cast[i].hand);
    }
    */

   return 0;
}

// function to find three of diamods (start the game)
function three_of_diamonds(cast) {
    //index to signify which player has the card, will be returned
    var index = -1;

    // example obj for ez finding
    var ex = new Card("Diamonds", 3, 0, true);

    // loop throuh each players hand
    for (i = 0; i < cast.length; i++) {
        // x represents the length of the players hand (it wont always be the same bc of uneven num of cards)
        var x = cast[i].hand.length;

        for (j = 0; j < x; j++) {
            if (cast[i].hand[j].suit == ex.suit && cast[i].hand[j].value == ex.value) {
                // console.log("card has been found")
                index = i;
                break;
            }
        }
        
        // if we found the player with the three of diamonds lets break
        if (index >= 0)
            break;
    }        

    console.log("Player " + (index + 1) + " has the three of diamonds!");
    return index;
}

// im thinking maybe this can be hardcoded array that would make things a lot easier; length of 54
var deck = [] 
// list which will hold our 4 players
var cast = []

// set up complete, however i am unsure about the array being passed into our class
// begin the infinte loop that signifies an on going game

// instead of a true/false flag we'll just do rounds
var rounds = 0;
var starting_player = -1

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
// while loop that will let the game run until all three rounds have been played.
// hold off on the loop for min, play one round succesfully first
   
// initial set ups
init_deck(deck);
init_players(cast);

assign_hands(deck, cast);
starting_player = three_of_diamonds(cast);

// how do we find out how many players have left finished the game. well we have many many possible options this is just one of them. possibly the worst one even poggers
function players_out(cast) {
    var count = 0;

}

// how do i make this function work? well for starters it will end when three players have no more cards in their hand
function play_game() {
    var flag = true;

    while ( flag ) {
        if (players_out() >= 3) {
            flag = false;
        }
    }
}

console.log('Select your game options:\n1) Start Game\n2) Quit\n')
let user_selection = prompt() //'Select your game options:\n1) Start Game\n2) Quit\n')
switch(user_selection) {
    case '1':
        console.log('we going somewhere')
        break;     
    case '2':
        console.log('until next time, bye bye')
        break;
}