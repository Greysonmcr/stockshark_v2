#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            // Individually add each Card into the Deck
            cards.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
        }
    }
}

void Deck::shuffle() {
    // Gives us a random seed
    std::random_device rd;

    // A type of random number generator
    std::mt19937 generator(rd());

    // begin and end define the range of cards to shuffle
    std::shuffle(cards.begin(), cards.end(), generator);
}

Card Deck::dealCard() {
    // Gets the last card and saves it
    Card dealtCard = cards.back();

    // Removes the last card from the vector
    cards.pop_back();
    return dealtCard;
}

int Deck::size() const {
    return cards.size();
}