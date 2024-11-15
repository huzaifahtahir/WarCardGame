//
//  Card.hpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/14/24.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <iostream>

class Card {
    
public:
    // Create enums for readability
    enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    
    enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
    
private:
    Suit suit;
    Rank rank;
    
public:
    // Constructor to initialize card with a suit and a rank
    Card(Suit s, Rank r) : suit(s), rank(r) {}
    
    // Accessor methods
    Suit getSuit();
    Rank getRank();
    
    // Method to get return numeric value of the card from enum Rank
    const int getValue();
    
};


#endif /* Card_hpp */
