//
//  Player.hpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/15/24.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Card.hpp"
#include <vector>
#include <iostream>
#include <string>

class Player {
private:
    std::vector<Card> hand; // Player's hand
    std::string name;
    
public:
    // Constructor to intialize player with a name
    Player(const std::string& playerName): name(playerName){}
    
    // Get player's name
    std::string getName() const;
    
    // Add card to player's hand
    void addCard(const Card& card);
    
    // Play (remove and turn) the top card from the player's hand
    Card playCard();
    
    // Get the number of cards in the player's hand
    size_t cardCount() const;
    
    // Check if the player has no cards left
    bool isOutOfCards() const;
};

#endif /* Player_hpp */
