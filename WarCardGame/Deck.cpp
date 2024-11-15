//
//  Deck.cpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/14/24.
//

#include "Deck.hpp"

//Initialize and creates the deck
void Deck::initializeDeck() {
    cards.clear(); // Clears any existing cards
    
    //Creates cards from each suit and of each rank
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r)
        {
            cards.emplace_back(Card::Suit(s), Card::Rank(r));
        }
    }
}

// Shuffles the deck
// Shuffle uses a vector beginning, end, a random seed gen
void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::drawCard() {
    if (!cards.empty())
    {
        // Grab the card from the back of the vector
        Card topCard = cards.back();
        // Removes the card by popping it
        cards.pop_back();
        return topCard;
    }
    throw std::out_of_range("The deck is empty.");
}

size_t Deck::cardCount() const { 
    return cards.size();
}
