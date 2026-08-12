#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <vector>
#include "Player.h"
#include "Game.h"

int main() {
    // -------------------------
    // Create players
    // -------------------------

    std::vector<Player> players;

    players.push_back(Player("Greyson", 1000, true));
    players.push_back(Player("Alice", 1000, true));
    players.push_back(Player("Bob", 1000, true));

    // -------------------------
    // Create game
    // -------------------------

    Game game(players);

    std::cout << "Game created with "
              << game.getPlayers().size()
              << " players.\n\n";

    // -------------------------
    // Test starting a hand
    // -------------------------

    game.startHand();

    std::cout << "--- Players after startHand() ---\n";

    for (const Player& player : game.getPlayers()) {
        std::cout << player.getPlayerName()
                  << " | Stack: "
                  << player.getStackAmount()
                  << " | Cards: "
                  << player.getCardsInHand().size()
                  << " | Folded: "
                  << player.isFolded()
                  << "\n";
    }

    // -------------------------
    // Test flop
    // -------------------------

    game.dealFlop();

    std::cout << "\nCommunity cards after flop: "
              << game.getCommunityCards().size()
              << "\n";

    // -------------------------
    // Test turn
    // -------------------------

    game.dealTurnOrRiver();

    std::cout << "Community cards after turn: "
              << game.getCommunityCards().size()
              << "\n";

    // -------------------------
    // Test river
    // -------------------------

    game.dealTurnOrRiver();

    std::cout << "Community cards after river: "
              << game.getCommunityCards().size()
              << "\n";

    // -------------------------
    // Test initial betting state
    // -------------------------

    std::cout << "\n--- Initial betting state ---\n";

    std::cout << "Pot: "
              << game.getPot()
              << "\n";

    std::cout << "Current bet: "
              << game.getCurrentBet()
              << "\n";

    std::cout << "Last raise size: "
              << game.getLastRaiseSize()
              << "\n";

    std::cout << "Current player index: "
              << game.getCurrentPlayerIndex()
              << "\n";

    std::cout << "Current bets: ";

    for (int bet : game.getCurrentBets()) {
        std::cout << bet << " ";
    }

    std::cout << "\n";

    // -------------------------
    // Test Player::chooseAction()
    // separately
    // -------------------------

    std::cout << "\n--- Testing chooseAction() ---\n";

    Player testPlayer("Test Player", 100, true);

    /*
        Scenario:

        Current highest bet = 20
        Test Player has already bet = 10
        Amount to call = 10

        Last full raise size = 10

        Therefore minimum raise-to should be:
        20 + 10 = 30

        Test Player can raise because they have
        not previously lost raising rights.
    */

    Action action = testPlayer.chooseAction(
        10,     // amountToCall
        20,     // currentBet
        10,     // player's current bet
        10,     // lastRaiseSize
        true    // canRaise
    );

    std::cout << "\nAction returned successfully.\n";
    std::cout << "Action amount: "
              << action.amount
              << "\n";

    return 0;
}