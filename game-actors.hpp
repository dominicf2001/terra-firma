#pragma once

#include "game-elements.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
using std::vector; using std::string;

class Actor {
    public:
        Actor(int health=100, int resonance=1, string name="", std::vector<std::shared_ptr<Harmonic>> harmonics={}) {
            health_ = health;
            resonance_ = resonance;
            harmonics_ = harmonics;
            name_ = name;
        }
        virtual void attack(std::shared_ptr<Actor>)=0;
        void takeDamage(int damage) {health_ -= damage;}
        void printHarmonics() const;
        int getHealth() const {return health_;}
        int getResonance() const {return resonance_;}
        string getName() const {return name_;}
        virtual ~Actor() = default;
    protected:
        vector<std::shared_ptr<Harmonic>> harmonics_;
        int health_;
        int resonance_;
        string name_;
};

class Player: public Actor {
    public:
        Player(string);
        void attack(std::shared_ptr<Actor>) override;
    private:
        vector<std::shared_ptr<Item>> inventory_;
};

class RiftGuardian: public Actor {
    public:
        RiftGuardian(string);
        void attack(std::shared_ptr<Actor>) override;
};

