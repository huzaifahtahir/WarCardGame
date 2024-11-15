//
//  Player.cpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/15/24.
//

#include "Player.hpp"


std::string Player::getName() const { 
    return name;
}

void Player::addCard(const Card &card) { 
    hand.push_back(card);
}

Card Player::playCard() { 
    if (!hand.empty()) {
        Card topCard = hand.back(); // Get the last card
        hand.pop_back(); // Remove it from the hand
        return topCard;
    }
    throw std::out_of_range("No cards left to play");
}

bool Player::isOutOfCards() const { 
    return hand.empty();
}

size_t Player::cardCount() const { 
    return hand.size();
}





