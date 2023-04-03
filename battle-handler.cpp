#include "game-actors.hpp"
#include "battle-handler.hpp"
#include <iostream>
#include <memory>
#include <string>
#include "game-elements.hpp"
#include "utilities.hpp"
using std::cout; using std::string; using std::cin;
using std::shared_ptr;

// GENERAL
BattleHandler::BattleHandler(shared_ptr<Player> player) : player_(player), playerTurn_(true) {};

bool BattleHandler::battleHasEnded() {return (player_->getHealth() <= 0 || enemy_->getHealth() <= 0);}

void BattleHandler::startBattle(shared_ptr<Actor> enemy) {
    enemy_ = enemy;
    while (!battleHasEnded()) {
        if (playerTurn_) {
            handlePlayerTurn();
        } else {
            handleEnemyTurn();
        }
        playerTurn_ = !playerTurn_;
    }
    displayBattleOutcome();
}

// Turn handling
void BattleHandler::handlePlayerTurn() {
    displayPlayerTurnInfo();
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
            handleDamageToTarget(enemy_, dmg);
        });
}

void BattleHandler::handleEnemyTurn() {
    displayEnemyTurnInfo();
    // put additional calculations here
    //  dmg * dmgMultiplier
    //  crit chance
    shared_ptr<Harmonic> harmonic = player_->getHarmonics()[0];
    if (harmonic->getType() == Harmonic::Type::attack) {
        harmonic->use([this, harmonic](int dmg){
                cout << enemy_->getName() << " attacks you with: " << enemy_->getHarmonics()[0]->getName() << " for: " << std::flush;
                sleep(1);
                cout << dmg << " DAMAGE!\n\n" << std::flush;
                sleep(1);
                handleDamageToTarget(player_, dmg);
            });
    }
}

// Damage handling
void BattleHandler::handleDamageToTarget(shared_ptr<Actor> target, int dmg) {
    // put additional calculations here
    int newHealth = target->getHealth() - dmg;
    target->setHealth(newHealth);
}

// DISPLAYS
void BattleHandler::displayPlayerTurnInfo() {
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

void BattleHandler::displayEnemyTurnInfo() {
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "\n========Enemies Move========\n\n";
}

void BattleHandler::displayBattleOutcome() {
   if (player_->getHealth() <= 0) {
        cout << "\nYou have died...\n\n";
        printSkull();
    } else {
        cout << "\nYou have defeated: " << enemy_->getName() << ", you are a glorious warrior!\n\n";
        printTrophy();
    }
}



