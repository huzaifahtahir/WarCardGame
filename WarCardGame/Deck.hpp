//
//  Deck.hpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/14/24.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include "Card.hpp"
#include <vector>
#include <algorithm>
#include <random>

class Deck {

private:
    // Create a vector of type Card
    std::vector<Card> cards;

public:
    // Constructor
    Deck()
    {
        // Populate the deck
        initializeDeck();
    }
    
    // Methods to initialize a deck, draw a card, and shuffle it.
    void initializeDeck();
    void shuffleDeck();
    Card drawCard();
    
    size_t cardCount() const;
};

#endif /* Deck_hpp */
