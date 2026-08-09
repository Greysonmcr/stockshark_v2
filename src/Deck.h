#pragma once
#include <vector>
#include "Card.h"

class Deck {
private:
    // A dynamic list of Card objects
    std::vector<Card> cards;

public:
    Deck();

    void shuffle();
    Card dealCard();

    int size() const;
};