#pragma once

#include "game-elements.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
using std::vector; using std::string;

class Actor {
    public:
        Actor(int health=100, int resonance=1, string name="", vector<std::shared_ptr<Harmonic>> harmonics={})
            : health_(health), resonance_(resonance), harmonics_(harmonics), name_(name) {};

        virtual void attack(std::shared_ptr<Actor>)=0;
        void takeDamage(int damage) {health_ -= damage;} // delegate to Battle implementor
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
        Player(int health=100, int resonance=1, string name="Player")
            : Actor(health, resonance, name) {
                HarmonicFactory& hFac = HarmonicFactory::getInstance();
                harmonics_ = {
                    hFac.getResonanceBlast()
                };
            };
        void attack(std::shared_ptr<Actor>) override; // Delegate to Battle implementor
        static std::shared_ptr<Player> getInstance() {
            if (instance_ == nullptr)
                instance_ = std::make_shared<Player>();
            return instance_;
        }
    private:
        static std::shared_ptr<Player> instance_;
        vector<std::shared_ptr<Item>> inventory_;
        // pointer to battle implementor
};

class Enemy: public Actor {
    public:
        Enemy(int health=100, int resonance=1, string name="", vector<std::shared_ptr<Harmonic>> harmonics={})
            : Actor(health, resonance, name, harmonics) {};
        void attack(std::shared_ptr<Actor>) override;// Delegate to Battle implementor
};

class EnemyFactory {
    public:
        std::shared_ptr<Enemy> getRiftGuardian(string name) {
            HarmonicFactory& hFac = HarmonicFactory::getInstance();
            vector<std::shared_ptr<Harmonic>> harmonics = {
                hFac.getResonanceBlast()
            };
            return std::make_shared<Enemy>(200, 10, name, std::move(harmonics));
        }
        static EnemyFactory& getInstance() {
            static EnemyFactory instance;
            return instance;
        }
    private:
        EnemyFactory(){};
        EnemyFactory(EnemyFactory&) = delete;
        EnemyFactory& operator=(EnemyFactory) = delete;
};





// std::shared_ptr<Actor> Ghoul = std::make_unique(new Ghoul("Ghoul name"));
