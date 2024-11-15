//
//  Game.cpp
//  WarCardGame
//
//  Created by Huzaifah Tahir on 11/15/24.
//

#include "Game.hpp"

// Populate and shuffle the deck. Then deal the cards
void Game::initialize() {
    deck.initializeDeck();
    deck.shuffleDeck();
    dealCards();
}

// Deal cards to players
void Game::dealCards() {
    // Divide deck evenly between players
    for (size_t i = 0; i < deck.cardCount(); ++i)
    {
        if (i % 2 == 0)
            player1.addCard(deck.drawCard());
        else
            player2.addCard(deck.drawCard());
    }
}

//Play a single round
void Game::playRound() {
    // If players are out of cards, dont continue
    if (player1.isOutOfCards() || player2.isOutOfCards()) return;
    
    // Each players plays their top card
    Card card1 = player1.playCard();
    Card card2 = player2.playCard();
    
    // Display the cards
    std::cout << player1.getName() << " plays: Suit " << static_cast<int>(card1.getSuit())
    << ", Rank " << static_cast<int>(card1.getRank()) << "\n";
    std::cout << player2.getName() << " plays: Suit " << static_cast<int>(card2.getSuit())
    << ", Rank " << static_cast<int>(card2.getRank()) << "\n";
    
    // Compare the cards
    if (card1.getValue() > card2.getValue())
    {
        std::cout << player1.getName() << " wins this round!\n";
        player1.addCard(card1);
        player1.addCard(card2);
    } else if (card1.getValue() < card2.getValue()) {
        std::cout << player2.getName() << " wins this round!\n";
        player2.addCard(card1);
        player2.addCard(card2);
    } else {
        std::cout << "it's a tie! Initiating war...\n";
        handleWar(card1, card2);
    }
}

// Handle war (tie condition)
void Game::handleWar(const Card &card1, const Card &card2) {
    // Each player adds 3 cards (face down)
    std::vector<Card> warPile = {card1, card2 };
    
    for (int i = 0; i < 3; ++i)
    {
        if (!player1.isOutOfCards()) warPile.push_back(player1.playCard());
        if (!player2.isOutOfCards()) warPile.push_back(player2.playCard());
    }
    if (player1.isOutOfCards() || player2.isOutOfCards()) return;
    Card warCard1 = player1.playCard();
    Card warCard2 = player2.playCard();
    warPile.push_back(warCard1);
    warPile.push_back(warCard2);
    
    // Determine the winner
    if (warCard1.getValue() > warCard2.getValue()) {
        std::cout << player1.getName() << " wins the war!\n";
        for (const auto& card : warPile) player1.addCard(card);
    } else if (warCard1.getValue() < warCard2.getValue()) {
        std::cout << player2.getName() << " wins the war!\n";
        for (const auto& card : warPile) player2.addCard(card);
    } else {
        std::cout << "Another tie! War continues...\n";
        handleWar(warCard1, warCard2);  // Recursively handle another war
    }
}

bool Game::isGameOver() const {
    return player1.isOutOfCards() || player2.isOutOfCards();
}

void Game::start() {
    initialize();

            while (!isGameOver()) {
                playRound();
            }

            // Declare the winner
            if (player1.isOutOfCards()) {
                std::cout << player2.getName() << " wins the game!\n";
            } else {
                std::cout << player1.getName() << " wins the game!\n";
            }
}
