#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Deck.h"
#include "Card.h"

class Game {
private:
    std::vector<Player> players;

    int dealerIndex;

    Deck deck;

    std::vector<Card> communityCards;

    int currentBet;

    int lastRaiseSize;

    int pot;

    std::vector<int> currentBets;

    std::vector<int> betWhenLastActed;

    int currentPlayerIndex;

public:
    // Creates a reference to the players vector as to not create an unnecessary copy
    Game(const std::vector<Player>& players);
    
    const std::vector<Player>& getPlayers() const;

    int getDealerIndex() const;

    const Deck& getDeck() const;

    const std::vector<Card>& getCommunityCards() const;

    int getCurrentBet() const;

    int getLastRaiseSize() const;

    int getPot() const;

    const std::vector<int>& getCurrentBets() const;

    int getCurrentPlayerIndex() const;

    void startHand();

    void dealFlop();

    void dealTurnOrRiver();

    void bettingRound();

    bool bettingRoundComplete() const;

    bool canPlayerRaise(int PlayerIndex) const;

};