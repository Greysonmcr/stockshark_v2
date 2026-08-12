#include "Game.h"

// Takes players by const reference to avoid an extra copy into the constructor parameter
Game::Game(const std::vector<Player>& players)
    : players(players),
      dealerIndex(0),
      pot(0),
      currentBet(0),
      lastRaiseSize(0),
      currentBets(players.size(), 0),
      betWhenLastActed(players.size(), -1),
      currentPlayerIndex(0) {
}

const std::vector<Player>& Game::getPlayers() const {
    return players;
}

int Game::getDealerIndex() const {
    return dealerIndex;
}

const Deck& Game::getDeck() const {
    return deck;
}

const std::vector<Card>& Game::getCommunityCards() const {
    return communityCards;
}

int Game::getCurrentBet() const {
    return currentBet;
}

int Game::getLastRaiseSize() const {
    return lastRaiseSize;
}

int Game::getPot() const {
    return pot;
}

const std::vector<int>& Game::getCurrentBets() const {
    return currentBets;
}

int Game::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

void Game::startHand() {
    communityCards.clear();
    pot = 0;
    deck = Deck();
    deck.shuffle();
    for (Player& player : players) {
        player.resetFold();
        player.clearCardsFromHand();
        player.addCardToHand(deck.dealCard());
    }
    for (Player& player : players) {
        player.addCardToHand(deck.dealCard());
    }
}

void Game::dealFlop() {
    deck.dealCard();
    communityCards.push_back(deck.dealCard());
    communityCards.push_back(deck.dealCard());
    communityCards.push_back(deck.dealCard());
}

void Game::dealTurnOrRiver() {
    deck.dealCard();
    communityCards.push_back(deck.dealCard());
}

bool Game::canPlayerRaise(int playerIndex) const {
    if (betWhenLastActed[playerIndex] == -1) {
        return true;
    }

    int amountRaisedSinceLastAction =
        currentBet - betWhenLastActed[playerIndex];

    return amountRaisedSinceLastAction >= lastRaiseSize;
}

bool Game::bettingRoundComplete() const {
    for (int i = 0; i < players.size(); i++) {

        if (players[i].isFolded()) {
            continue;
        }

        if (players[i].getStackAmount() == 0) {
            continue;
        }

        if (betWhenLastActed[i] == -1) {
            return false;
        }

        if (currentBets[i] != currentBet) {
            return false;
        }
    }

    return true;
}

void Game::bettingRound() {
    while (!bettingRoundComplete()) {

        Player& playerToAct = players[currentPlayerIndex];

        if (playerToAct.isFolded() ||
            playerToAct.getStackAmount() == 0) {

            currentPlayerIndex =
                (currentPlayerIndex + 1) % players.size();

            continue;
        }

        int amountToCall =
            currentBet - currentBets[currentPlayerIndex];

        bool canRaise =
            canPlayerRaise(currentPlayerIndex);

        Action action = playerToAct.chooseAction(
            amountToCall,
            currentBet,
            currentBets[currentPlayerIndex],
            lastRaiseSize,
            canRaise
        );

        // process action

        currentPlayerIndex =
            (currentPlayerIndex + 1) % players.size();
    }
}