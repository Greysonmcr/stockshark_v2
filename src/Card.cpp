#include "Card.h"

// Defines initialization for Card class
Card::Card(Rank rank, Suit suit)
    // Member initializer list
    : rank(rank), suit(suit) {
}

// Defines the getter for rank
Rank Card::getRank() const {
    return rank;
}

// Defines the getter for suit
Suit Card::getSuit() const {
    return suit;
}

std::string Card::toString() const {
    std::string rankString;
    std::string suitString;

    switch(rank) {
        case Rank::Two:
            rankString = "Two";
            break;
        case Rank::Three:
            rankString = "Three";
            break;
        case Rank::Four:
            rankString = "Four";
            break;
        case Rank::Five:
            rankString = "Five";
            break;
        case Rank::Six:
            rankString = "Six";
            break;
        case Rank::Seven:
            rankString = "Seven";
            break;
        case Rank::Eight:
            rankString = "Eight";
            break;
        case Rank::Nine:
            rankString = "Nine";
            break;
        case Rank::Ten:
            rankString = "Ten";
            break;
        case Rank::Jack:
            rankString = "Jack";
            break;
        case Rank::Queen:
            rankString = "Queen";
            break;
        case Rank::King:
            rankString = "King";
            break;
        case Rank::Ace:
            rankString = "Ace";
            break;
    }

    switch(suit) {
        case Suit::Clubs:
            suitString = "Clubs";
            break;
        case Suit::Diamonds:
            suitString = "Diamonds";
            break;
        case Suit::Hearts:
            suitString = "Hearts";
            break;
        case Suit::Spades:
            suitString = "Spades";
            break;
    }

    return rankString + " of " + suitString;
}
