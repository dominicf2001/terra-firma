#include "game-actors.hpp"
#include "battle-logic.hpp"
#include <iostream>
#include <memory>
#include <string>
#include "utilities.hpp"
using std::cout; using std::string; using std::cin;
using std::shared_ptr;

// GENERAL
BattleSystem::BattleSystem(shared_ptr<Player> player) : player_(player), playerTurn_(true) {};

bool BattleSystem::isBattleOver() {return (player_->getHealth() <= 0 || enemy_->getHealth() <= 0);}

void BattleSystem::startBattle(shared_ptr<Actor> enemy) {
    enemy_ = enemy;
    while (!isBattleOver()) {
        if (playerTurn_) {
            printPlayerDisplay();
            playerMove();
        } else {
            printEnemyDisplay();
            enemyMove();
        }
        playerTurn_ = !playerTurn_;
    }
    printGameOverDisplay();
}

// ATTACKS
void BattleSystem::playerMove() {
    // put additional calculations here
    int i = -1;
    while (i < 0 || i >= player_->getHarmonics().size()) {
        cout << "[0 - " << (player_->getHarmonics().size() - 1) << "]: ";
        cin >> i;
        if (i < 0 || i >= player_->getHarmonics().size())
            cout << "\n=-- Invalid! Please try again. --=\n\n";
    }
    shared_ptr<Harmonic> harmonic = player_->getHarmonics()[i];

    harmonic->use([this, harmonic](int dmg) {
            cout << "\nYou attack with: " << harmonic->getName() << " for: " << std::flush;
            sleep(1);
            cout << dmg << " DAMAGE!\n\n" << std::flush;
            sleep(1);
            enemyTakeDamage(dmg);
        });
}

void BattleSystem::enemyMove() {
    // put additional calculations here
    //  dmg * dmgMultiplier
    //  crit chance
    shared_ptr<Harmonic> harmonic = player_->getHarmonics()[0];
    harmonic->use([this, harmonic](int dmg) {
            cout << enemy_->getName() << " attacks you with: " << enemy_->getHarmonics()[0]->getName() << " for: " << std::flush;
            sleep(1);
            cout << dmg << " DAMAGE!\n\n" << std::flush;
            sleep(1);
            playerTakeDamage(dmg);
        });
}

// TAKE DAMAGE
void BattleSystem::playerTakeDamage(int dmg) {
    // put additional calculations here
    //  dmg / defense
    int newHealth = player_->getHealth() - dmg;
    player_->setHealth(newHealth);
}

void BattleSystem::enemyTakeDamage(int dmg) {
    // put additional calculations here
    int newHealth = enemy_->getHealth() - dmg;
    enemy_->setHealth(newHealth);
}

// DISPLAYS
void BattleSystem::printPlayerDisplay() {
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "\n========Your Move========\n\n";
    cout << "Your health: (" << player_->getHealth() << ')' << '\n' << "Your resonance: (" << player_->getResonance() << ")\n\n";
    cout << enemy_->getName() << "'s health: (" << enemy_->getHealth() << ')' << '\n' << enemy_->getName()<< "'s resonance: " << '(' << enemy_->getResonance() << ")\n\n";

    cout << "Choose a Harmonic!\n" << "-----------------\n";
    for (int i = 0; i < player_->getHarmonics().size(); ++i) {
        std::cout << "[" << i << "] " << player_->getHarmonics()[i]->getName() << '\n';
        std::cout << "    " << "Description: " << player_->getHarmonics()[i]->getDesc() << '\n';
        std::cout << "    " << "Resonance Requirement: " << player_->getHarmonics()[i]->getResReq() << '\n';;
    }
}

void BattleSystem::printEnemyDisplay() {
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "\n========Enemies Move========\n\n";
}

void BattleSystem::printGameOverDisplay() {
   if (player_->getHealth() <= 0) {
        cout << "\nYou have died...\n\n";
        printSkull();
    } else {
        cout << "\nYou have defeated: " << enemy_->getName() << ", you are a glorious warrior!\n\n";
        printTrophy();
    }
}



