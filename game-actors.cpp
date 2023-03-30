#include "game-actors.hpp"
#include "utilities.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <string>
using std::cout; using std::cin; using std::string;

void Actor::printHarmonics() const {
    for (int i = 0; i < harmonics_.size(); ++i) {
        std::cout << "[" << i << "] " << harmonics_[i]->getName() << '\n';
        std::cout << "    " << "Description: " << harmonics_[i]->getDesc() << '\n';
        std::cout << "    " << "Damage: " << harmonics_[i]->getMinDmg() << "-" << harmonics_[i]->getMaxDmg() << '\n';
        std::cout << "    " << "Resonance Requirement: " << harmonics_[i]->getResonanceReq() << '\n';;
    }
}

Player::Player(string name): Actor(100, 3, name) {
    HarmonicFactory& hFac = HarmonicFactory::getInstance();
    ItemFactory& iFac = ItemFactory::getInstance();
    harmonics_ = {hFac.getResonanceBlast()};
    inventory_ = {iFac.getCaveDoorKeyOne()};
};

RiftGuardian::RiftGuardian(string name): Actor(100, 10, name) {
    HarmonicFactory& fac = HarmonicFactory::getInstance();
    harmonics_ = {fac.getResonanceBlast()};
};

void Player::attack(std::shared_ptr<Actor> enemy) {
    int i = -1;
    while (i < 0 || i >= harmonics_.size()) {
        cout << "Your health: (" << getHealth() << ')' << '\n' << "Your resonance: (" << getResonance() << ")\n\n";
        cout << enemy->getName() << "'s health: (" << enemy->getHealth() << ')' << '\n' << enemy->getName()<< "'s resonance: " << '(' << enemy->getResonance() << ")\n\n";

        cout << "Choose an attack!\n" << "-----------------\n";
        printHarmonics();
        cout << "[0 - " << harmonics_.size() - 1 << "]: ";
        cin >> i;
        if (i < 0 || i >= harmonics_.size())
            cout << "\nInvalid! Please try again.\n\n";
    }
    int dmg = harmonics_[i]->getDmg();
    cout << "\nYou attack with: " << harmonics_[0]->getName() << " for: " << std::flush;
    sleep(1);
    cout << dmg << " DAMAGE!\n\n" << std::flush;
    sleep(1);
    enemy->takeDamage(dmg);
}

void RiftGuardian::attack(std::shared_ptr<Actor> player) {
    int dmg = harmonics_[0]->getDmg();
    cout << getName() << " attacks you with: " << harmonics_[0]->getName() << " for: " << std::flush;
    sleep(1);
    cout << dmg << " DAMAGE!\n\n" << std::flush;
    sleep(1);
    player->takeDamage(dmg);
}
