#include "game-actors.hpp"
#include "game-elements.hpp"
#include <iostream>
#include <memory>
using std::cout;

void startBattle(std::shared_ptr<Actor> player, std::shared_ptr<Actor> enemy) {
    bool battleOver = false;
    bool playerTurn = true;
    cout << "\nYou have encountered: " << enemy->getName() << " - Resonance: " << enemy->getResonance() << '\n';
    cout << "-----------------------------------------------------------------------------\n\n";
    while (!battleOver) {
        if (playerTurn) {
            player->attack(enemy);
            battleOver = enemy->getHealth() < 0;
        } else {
            enemy->attack(player);
            battleOver = player->getHealth() < 0;
        }
        playerTurn = !playerTurn;
    }
}
