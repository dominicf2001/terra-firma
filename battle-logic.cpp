#include "game-actors.hpp"
#include "game-elements.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>
using std::cout; using std::string;

void startBattle(std::shared_ptr<Actor> player, std::shared_ptr<Actor> enemy) {
    bool battleOver = false;
    bool playerTurn = true;
    string encounterInfo = "\nYou have encountered: " + enemy->getName() + " - Resonance: " + std::to_string(enemy->getResonance());
    cout << "\n" << string(encounterInfo.size(), '*') << encounterInfo << '\n' << string(encounterInfo.size(), '*') << "\n\n";
    while (!battleOver) {
        if (playerTurn) {
            cout << "---------------------------------------------------------------------------------------------\n";
            cout << "\n========Your Move========\n\n";
            player->attack(enemy);
            battleOver = enemy->getHealth() <= 0;
        } else {
            cout << "---------------------------------------------------------------------------------------------\n";
            cout << "\n========Enemies Move========\n\n";
            enemy->attack(player);
            battleOver = player->getHealth() <= 0;
        }
        playerTurn = !playerTurn;
        cout << "---------------------------------------------------------------------------------------------\n";
    }
    if (player->getHealth() <= 0) {
        cout << "\nYou have died...\n\n";
        cout << R"(
  _____
 /     \
| () () |
 \  ^  /
  |||||
  |||||
)" << '\n';
    }
}
