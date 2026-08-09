#pragma once
#include <string>

enum class Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

// C++ Automatically assigns numerical values to these cards
// Three = 3, Four = 4, etc.
enum class Rank {
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card {
private:
// private means these vars can only be changed by the class itself

    // These are data belonging to each Card object
    Rank rank;
    Suit suit;

public:
// public means the following things can be accessed by outside the class itself

    // This line is the constructor
    // C++ functions usually have return types but this one doesn't
    Card(Rank rank, Suit suit);

    // Function declarations (for getters)
    // The const at the end means 'Calling this function won't modify the Card'
    Rank getRank() const;
    Suit getSuit() const;

    std::string toString() const;
};
