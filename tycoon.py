class Player:
    def __init__(self, hand, points = 0, sclass = "commoner"):
        self.sclass = sclass
        self.hand = hand
        self.points = points

    def show_hand():
        for card in hand:
            print(card.print_info()) 

class Card:
    def __init__(self, suit, num, value, special):
        self.suit = suit
        self.num = num
        self.value = value
        self.special = special

    def print_info():
        print("Your current card is the " + self.num + " of " + self.suit)

def init_deck(deck):

    #clear the deck for recurring rounds
    deck.clear()

    for i in range(13):
        card_name = "spades_" + (1 + i)
        val = 11 + i
        special = False

        if i == 2:
            special = True
            val = 14
        else if i == 7:
            special = True

        deck.append(card_name = Card("Spades", 1 + i, val % 13, special))

