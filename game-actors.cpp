#include "game-actors.hpp"

void Actor::printHarmonics() const {
    for (auto h : harmonics_) {
        std::cout << h->getName() << '\n';
        std::cout << "    " << "Description: " << h->getDesc() << '\n';
        std::cout << "    " << "Attack: " << h->getAttack() << '\n';
        std::cout << "    " << "Resonance Requirement: " << h->getResonanceRequirement() << '\n';;
    }
}

Player::Player(): Actor(100, 3) {
    HarmonicFactory& hFac = HarmonicFactory::getInstance();
    ItemFactory& iFac = ItemFactory::getInstance();
    harmonics_ = {hFac.getResonanceBlast()};
    inventory_ = {iFac.getCaveDoorKeyOne()};
};

RiftGuardian::RiftGuardian(): Actor(200, 10) {
    HarmonicFactory& fac = HarmonicFactory::getInstance();
    harmonics_ = {fac.getResonanceBlast()};
};

