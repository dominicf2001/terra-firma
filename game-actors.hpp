#pragma once

#include "game-elements.hpp"
#include <vector>
#include <memory>
#include <iostream>
using std::vector;

class Actor {
    public:
        Actor(int health=100, int resonance=1, std::vector<std::shared_ptr<Harmonic>> harmonics={}): health_(health), resonance_(resonance), harmonics_(harmonics){};

        virtual void attack(Actor*)=0;
        void takeDamage(int damage) {health_ -= damage;}
        virtual void printSelf() const {
            for (auto h : harmonics_)
                std::cout << h->getName();
        }
        int getHealth() const {return health_;}
        int getResonance() const {return resonance_;}
        virtual ~Actor() = default;
    protected:
        vector<std::shared_ptr<Harmonic>> harmonics_;
        int health_;
        int resonance_;
};

class Player: public Actor {
    public:
        Player(): Actor(100, 4)  {
            HarmonicFactory hFac = HarmonicFactory::getInstance();
            ItemFactory iFac = ItemFactory::getInstance();
            harmonics_ = {hFac.getResonanceBlast()};
            inventory_ = {iFac.getCaveDoorKeyOne()};
        };

        void attack(Actor*) override {};
        void printSelf() const override{
            for (auto h : harmonics_)
                std::cout << "HARMONICS: " << h->getName() << " ";
            for (auto i : inventory_)
                std::cout << "ITEMS: " << i->getName() << " ";
        }
    private:
        vector<std::shared_ptr<Item>> inventory_;
};

class RiftGuardian: public Actor {
    public:
        RiftGuardian(): Actor(200, 10)  {
            HarmonicFactory fac = HarmonicFactory::getInstance();
            harmonics_ = {fac.getResonanceBlast()};
        };
        void attack(Actor*) override {}; };

