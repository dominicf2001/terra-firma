#include "game-actors.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <string>
using std::cout; using std::cin; using std::string;

void Actor::printHarmonics() const {
    for (int i = 0; i < harmonics_.size(); ++i) {
        std::cout << "[" << i << "] " << harmonics_[i]->getName() << '\n';
        std::cout << "    " << "Description: " << harmonics_[i]->getDesc() << '\n';
        std::cout << "    " << "Damage: " << harmonics_[i]->getDamage() << '\n';
        std::cout << "    " << "Resonance Requirement: " << harmonics_[i]->getResonanceReq() << '\n';;
    }
}

Player::Player(string name): Actor(100, 3, name) {
    HarmonicFactory& hFac = HarmonicFactory::getInstance();
    ItemFactory& iFac = ItemFactory::getInstance();
    harmonics_ = {hFac.getResonanceBlast()};
    inventory_ = {iFac.getCaveDoorKeyOne()};
};

RiftGuardian::RiftGuardian(string name): Actor(200, 10, name) {
    HarmonicFactory& fac = HarmonicFactory::getInstance();
    harmonics_ = {fac.getResonanceBlast()};
};

void Player::attack(std::shared_ptr<Actor> enemy) {
    int i = -1;
    while (i < 0 || i >= harmonics_.size()) {
        cout << "Your health: " << getHealth() << " Your resonance: " << getResonance() << '\n';
        cout << enemy->getName() << "'s health: " << enemy->getHealth() << " " << enemy->getName()<< "'s resonance: " << enemy->getResonance() << '\n';

        cout << "Choose an attack!\n";
        printHarmonics();
        cout << "[0 - " << harmonics_.size() - 1 << "]: ";
        cin >> i;
        if (i < 0 || i >= harmonics_.size())
            cout << "Invalid! Please try again.\n";
    }
    enemy->takeDamage(harmonics_[i]->getDamage());
}

void RiftGuardian::attack(std::shared_ptr<Actor> player) {
    player->takeDamage(harmonics_[0]->getDamage());
}
