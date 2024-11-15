//
//  Game.hpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/15/24.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Deck.hpp"
#include "Player.hpp"

class Game {
private:
    Deck deck; // The deck of cards
    Player player1;
    Player player2;
    
public:
    // Constructor
    Game(const std::string& name1, const std::string& name2) : player1(name1), player2(name2) {}
    
    // Initialize the game
    void initialize();
    
    // Deal cards to players (evenly between players)
    void dealCards();
    
    // Play a single round (draw top cards)
    void playRound();
    
    // Handle when war intiates (a draw of cards)
    void handleWar(const Card& card1, const Card& card2);
    
    // Check if game is ended
    bool isGameOver() const;
    
    // Start the game
    void start();
};


#endif /* Game_hpp */
