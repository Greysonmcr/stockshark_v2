#include "Game.h"

// Takes players by const reference to avoid an extra copy into the constructor parameter
Game::Game(const std::vector<Player>& players)
    : players(players),
      dealerIndex(0),
      pot(0),
      currentBets(players.size(), 0),
      currentBetToMatch(0),
      currentPlayerIndex(0),
      lastRaiserIndex(0),
      hasActionOccurred(false) {
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

int Game::getPot() const {
    return pot;
}

const std::vector<int>& Game::getCurrentBets() const {
    return currentBets;
}

int Game::getCurrentBetToMatch() const {
    return currentBetToMatch;
}

int Game::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

int Game::getLastRaiserIndex() const {
    return lastRaiserIndex;
}

bool Game::getHasActionOccurred() const {
    return hasActionOccurred;
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