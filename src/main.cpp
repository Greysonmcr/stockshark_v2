#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

int main() {
    std::vector<Player> players;

    players.push_back(Player("Greyson", 1000, true));
    players.push_back(Player("Bot 1", 1000, false));
    players.push_back(Player("Bot 2", 1000, false));

    Game game(players);

    game.startHand();

    for (const Player& player : game.getPlayers()) {
        std::cout << player.getPlayerName() << ":" << std::endl;

        for (const Card& card : player.getCardsInHand()) {
            std::cout << "  " << card.toString() << std::endl;
        }
    }

    std::cout << "Cards remaining: "
              << game.getDeck().size()
              << std::endl;

    return 0;
}