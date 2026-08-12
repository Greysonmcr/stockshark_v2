#include "Player.h"
#include <iostream>
#include <algorithm>

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

Action Player::chooseAction(
    int amountToCall,
    int currentBet,
    int playerCurrentBet,
    int lastRaiseSize,
    bool canRaise
) {
    while (true) {
        int choice;

        int maxRaiseTo = playerCurrentBet + stackAmount;

        // Minimum legal full raise
        int minimumRaiseTo = currentBet + lastRaiseSize;

        bool canAffordFullRaise =
            maxRaiseTo >= minimumRaiseTo;

        bool canShortAllInRaise =
            canRaise &&
            maxRaiseTo > currentBet &&
            maxRaiseTo < minimumRaiseTo;

        // -------------------------
        // Display choices
        // -------------------------

        std::cout << name << ", choose an action:\n";

        if (amountToCall == 0) {
            std::cout << "1. Check\n";
        } else {
            std::cout << "1. Call " 
                      << std::min(amountToCall, stackAmount)
                      << "\n";
        }

        if (canRaise) {
            if (canAffordFullRaise) {
                std::cout << "2. Raise\n";
            }
            else if (canShortAllInRaise) {
                std::cout << "2. All-in to "
                          << maxRaiseTo << "\n";
            }
            else {
                std::cout << "2. Raise unavailable\n";
            }
        }
        else {
            std::cout << "2. Raise unavailable\n";
        }

        std::cout << "3. Fold\n";

        // -------------------------
        // Validate 1, 2, or 3
        // -------------------------

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Input 1, 2, or 3.\n";
            continue;
        }

        if (choice < 1 || choice > 3) {
            std::cout << "Input 1, 2, or 3.\n";
            continue;
        }

        // -------------------------
        // CHECK / CALL
        // -------------------------

        if (choice == 1) {

            if (amountToCall == 0) {
                return {ActionType::CHECK, 0};
            }

            // Player doesn't have enough to fully call
            if (amountToCall >= stackAmount) {
                return {ActionType::CALL, stackAmount};
            }

            return {ActionType::CALL, amountToCall};
        }

        // -------------------------
        // RAISE / ALL-IN
        // -------------------------

        if (choice == 2) {

            if (!canRaise) {
                std::cout
                    << "Betting has not been reopened. "
                    << "You cannot raise.\n";
                continue;
            }

            // Player can only make a short all-in raise
            if (canShortAllInRaise) {
                return {ActionType::RAISE, maxRaiseTo};
            }

            // Player can't even exceed current bet
            if (!canAffordFullRaise) {
                std::cout << "You do not have enough chips to raise.\n";
                continue;
            }

            int raiseAmount;

            while (true) {
                std::cout
                    << "Raise to (minimum "
                    << minimumRaiseTo
                    << ", maximum "
                    << maxRaiseTo
                    << "): ";

                if (!(std::cin >> raiseAmount)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');

                    std::cout << "Enter a valid number.\n";
                    continue;
                }

                if (raiseAmount < minimumRaiseTo) {
                    std::cout
                        << "Minimum raise is to "
                        << minimumRaiseTo
                        << ".\n";
                    continue;
                }

                if (raiseAmount > maxRaiseTo) {
                    std::cout
                        << "You only have enough chips to raise to "
                        << maxRaiseTo
                        << ".\n";
                    continue;
                }

                return {ActionType::RAISE, raiseAmount};
            }
        }

        // -------------------------
        // FOLD
        // -------------------------

        if (choice == 3) {
            return {ActionType::FOLD, 0};
        }
    }
}