#pragma once

#include "game-elements.hpp"
#include <vector>
#include <memory>
#include <iostream>
using std::vector;

class Actor {
    public:
        Actor(int health=100, int resonance=1, std::vector<std::shared_ptr<Harmonic>> harmonics={}) {
            health_ = health;
            resonance_ = resonance;
            harmonics_ = harmonics;
        }
        virtual void attack(Actor&)=0;
        void takeDamage(int damage) {health_ -= damage;}
        void printHarmonics() const;
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
        static Player* getInstance() {
            static Player instance;
            return &instance;
        }
        void attack(Actor&) override {};
    private:
        Player();
        Player(Player&) = delete;
        Player& operator=(Player) = delete;
        vector<std::shared_ptr<Item>> inventory_;
};

class RiftGuardian: public Actor {
    public:
        RiftGuardian();
        void attack(Actor&) override {};
};

