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
            playerAttack();
        } else {
            printEnemyDisplay();
            enemyAttack();
        }
        playerTurn_ = !playerTurn_;
    }
    printGameOverDisplay();
}


// ATTACKS
void BattleSystem::playerAttack() {
    // put additional calculations here
    int i = -1;
    while (i < 0 || i >= player_->getHarmonics().size()) {
        cout << "[0 - " << (player_->getHarmonics().size() - 1) << "]: ";
        cin >> i;
        if (i < 0 || i >= player_->getHarmonics().size())
            cout << "\n=-- Invalid! Please try again. --=\n\n";
    }
    shared_ptr<Harmonic> harmonic = player_->getHarmonics()[i];
    int dmg = harmonic->getDmg();
    cout << "\nYou attack with: " << harmonic->getName() << " for: " << std::flush;
    sleep(1);
    cout << dmg << " DAMAGE!\n\n" << std::flush;
    sleep(1);
    enemyTakeDamage(dmg);
}

void BattleSystem::enemyAttack() {
    // put additional calculations here
    int dmg = enemy_->getHarmonics()[0]->getDmg();
    cout << enemy_->getName() << " attacks you with: " << enemy_->getHarmonics()[0]->getName() << " for: " << std::flush;
    sleep(1);
    cout << dmg << " DAMAGE!\n\n" << std::flush;
    sleep(1);
    playerTakeDamage(dmg);
}

// TAKE DAMAGE
void BattleSystem::playerTakeDamage(int dmg) {
    // put additional calculations here
    int newHealth = player_->getHealth() - dmg;
    player_->changeHealth(newHealth);
}

void BattleSystem::enemyTakeDamage(int dmg) {
    // put additional calculations here
    int newHealth = enemy_->getHealth() - dmg;
    enemy_->changeHealth(newHealth);
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
        std::cout << "    " << "Damage: " << player_->getHarmonics()[i]->getMinDmg() << "-" << player_->getHarmonics()[i]->getMaxDmg() << '\n';
        std::cout << "    " << "Resonance Requirement: " << player_->getHarmonics()[i]->getResonanceReq() << '\n';;
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



