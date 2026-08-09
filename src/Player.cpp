#include "Player.h"

Player::Player(const std::string& name, int stackAmount, bool human)
    : name(name), stackAmount(stackAmount), human(human), folded(false) {
}

const std::string& Player::getPlayerName() const {
    return name;
}

int Player::getStackAmount() const {
    return stackAmount;
}

bool Player::isHuman() const {
    return human;
}

bool Player::isFolded() const {
    return folded;
}

void Player::addCardToHand(Card card) {
    currentHand.push_back(card);
}

const std::vector<Card>& Player::getCardsInHand() const {
    return currentHand;
}

void Player::clearCardsFromHand() {
    currentHand.clear();
}

void Player::changeStackAmount(int amount) {
    stackAmount += amount;
}

void Player::fold() {
    folded = true;
}

void Player::resetFold() {
    folded = false;
}