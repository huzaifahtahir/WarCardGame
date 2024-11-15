//
//  Card.cpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/14/24.
//

#include "Card.hpp"

Card::Suit Card::getSuit() {
    return suit;
}

Card::Rank Card::getRank() {
    return rank;
}

const int Card::getValue() { 
    return static_cast<int>(rank);
}


