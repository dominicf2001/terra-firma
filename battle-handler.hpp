#pragma once
#include "game-actors.hpp"
#include <memory>
#include <iostream>
using std::shared_ptr;

class Actor;
class Player;
class BattleHandler {
    public:
        BattleHandler(shared_ptr<Player>);
        void startBattle(shared_ptr<Actor>);
    private:
        bool battleHasEnded();
        // Turn handling
        void handlePlayerTurn();
        void handleEnemyTurn();
        // Damage handling
        void handleDamageToTarget(shared_ptr<Actor>, int);

        // Displays
        void displayPlayerTurnInfo();
        void displayEnemyTurnInfo();
        void displayBattleOutcome();

        shared_ptr<Player> player_;
        shared_ptr<Actor> enemy_;
        bool playerTurn_;
};
