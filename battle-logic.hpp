#pragma once
#include "game-actors.hpp"
#include <memory>
#include <iostream>
using std::shared_ptr;

class Actor;
class Player;
class BattleSystem {
    public:
        BattleSystem(shared_ptr<Player>);
        void startBattle(shared_ptr<Actor>);
    private:
        bool isBattleOver();

        void printPlayerDisplay();
        void printEnemyDisplay();
        void printGameOverDisplay();

        void playerMove();
        void enemyMove();
        void playerTakeDamage(int);
        void enemyTakeDamage(int);

        shared_ptr<Player> player_;
        shared_ptr<Actor> enemy_;
        bool playerTurn_;
};
