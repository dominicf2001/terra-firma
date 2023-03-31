#pragma once

#include "game-elements.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
using std::vector; using std::string;
using std::make_shared; using std::shared_ptr;

class Actor {
    public:
        Actor(int health=100, int resonance=1, string name="", vector<std::shared_ptr<Harmonic>> harmonics={})
            : health_(health), resonance_(resonance), name_(name), harmonics_(harmonics) {};

        virtual void attack(std::shared_ptr<Actor>);
        void takeDamage(int damage) {health_ -= damage;} // delegate to Battle implementor
        void printHarmonics() const;
        int getHealth() const {return health_;}
        int getResonance() const {return resonance_;}
        string getName() const {return name_;}
        virtual ~Actor() = default;
    protected:
        vector<shared_ptr<Harmonic>> harmonics_;
        int health_;
        int resonance_;
        string name_;
};

class Player: public Actor {
    public:
        Player(string name="Player")
            : Actor(100, 2, name) {
                HarmonicFactory& hFac = HarmonicFactory::getInstance();
                harmonics_ = {
                    hFac.getResonanceBlast()
                };
            };
        void attack(shared_ptr<Actor>) override; // Delegate to Battle implementor
        static shared_ptr<Player> getInstance() {
            if (instance_ == nullptr)
                instance_ = make_shared<Player>();
            return instance_;
        }
    private:
        static shared_ptr<Player> instance_;
        vector<shared_ptr<Item>> inventory_;
        // pointer to battle implementor
};

class RiftGuardian: public Actor {
    public:
        RiftGuardian(string name="Rift Guardian")
            : Actor(120, 10, name) {
                HarmonicFactory& hFac = HarmonicFactory::getInstance();
                harmonics_ = {
                    hFac.getResonanceBlast()
                };
            };
};


// shared_ptr<Player> player = Player::getInstance();
// shared_ptr<Enemy> Ghoul = make_shared<Goul>("Ghoul name");
