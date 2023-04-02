#pragma once
#include "battle-logic.hpp"
#include "game-elements.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
using std::vector; using std::string;
using std::make_shared; using std::shared_ptr; using std::make_unique; using std::unique_ptr;

class Actor {
    public:
        Actor(int health=100, int resonance=1, string name="", vector<shared_ptr<Harmonic>> harmonics={})
            : health_(health), resonance_(resonance), name_(name), harmonics_(harmonics) {};

        void setHealth(int x) {health_ = x;};
        int getHealth() const {return health_;}
        int getResonance() const {return resonance_;}
        string getName() const {return name_;}
        vector<shared_ptr<Harmonic>> getHarmonics() const {return harmonics_;}
        virtual ~Actor() = default;
    protected:
        vector<shared_ptr<Harmonic>> harmonics_;
        int health_;
        int defense_;
        int resonance_;
        string name_;
};


class BattleSystem;
class Player: public Actor {
    public:
        Player(string name="Player")
            : Actor(100, 2, name) {
                harmonics_ = {
                    make_shared<ResonanceBlast>()
                };
            };

        static shared_ptr<Player> getInstance() {
            if (instance_ == nullptr) {
                instance_ = make_shared<Player>();
                instance_->battleSystem_ = make_unique<BattleSystem>(instance_);
            }
            return instance_;
        }
        void startBattle(shared_ptr<Actor> enemy) {battleSystem_->startBattle(enemy);}
    private:
        static shared_ptr<Player> instance_;
        vector<shared_ptr<Item>> inventory_;
        unique_ptr<BattleSystem> battleSystem_;
};

class RiftGuardian: public Actor {
    public:
        RiftGuardian(string name="Rift Guardian")
            : Actor(120, 10, name) {
                harmonics_ = {
                    make_shared<ResonanceBlast>()
                };
            };
};
