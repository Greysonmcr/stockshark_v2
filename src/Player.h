#pragma once
#include "Card.h"
#include <string>
#include <vector>

class Player {
private:
    std::string name;
    int stackAmount;
    std::vector<Card> currentHand;
    bool human;
    bool folded;

public:
    Player(const std::string& name, int stackAmount, bool isHuman);

    const std::string& getPlayerName() const;

    int getStackAmount() const;

    bool isHuman() const;

    bool isFolded() const;

    void addCardToHand(Card card);

    const std::vector<Card>& getCardsInHand() const;

    void clearCardsFromHand();

    void changeStackAmount(int amount);

    void fold();

    void resetFold();
};