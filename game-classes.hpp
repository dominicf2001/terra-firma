#ifndef GAME_CLASSES_HPP

#include <type_traits>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
using std::string;

class Item {
    public:
        Item();
    private:
        std::string name_;
        std::string description_;
};

class Harmonic {
    public:
        Harmonic(string name, string desc, int attack, int resonanceRequirement) {
            name_ = name;
            desc_ = desc;
            attack_ = attack;
            resonanceRequirement_ = resonanceRequirement;
        };
        string getName() const {return name_;}
        string getDesc() const {return desc_;}
        int getAttack() const {return attack_;}
        int getResonanceRequirement() const {return resonanceRequirement_;}
    private:
        string name_;
        string desc_;
        int attack_;
        int resonanceRequirement_;
};

class HarmonicFactory {
    public:
        std::shared_ptr<Harmonic> getHarmonic(string name, string desc, int attack, int resonanceRequirement) {
            auto it = harmonics_.find(name);
            if (it != harmonics_.end()) {
                return it->second;
            }
            auto harmonic = std::make_shared<Harmonic>(name, desc, attack, resonanceRequirement);
            harmonics_[name] = harmonic;
            return harmonic;
        }
        std::shared_ptr<Harmonic> getResonanceBlast() {
            return getHarmonic("Resonance Blast", "Channel energy from The Essence to unleash a concentrated blast of resonant force",30, 2);
        }
    private:
        static std::unordered_map<string, std::shared_ptr<Harmonic>> harmonics_;
};

class Actor {
    public:
        Actor(int health=100, int resonance=1, std::vector<Harmonic> harmonics={}): health_(health), resonance_(resonance), harmonics_(harmonics){};

        virtual void attack(Actor*)=0;
        virtual ~Actor() = default;
        void printHarmonics() const {
            for (auto h : harmonics_)
                std::cout << h.getResonanceRequirement();
        };
    private:
        std::vector<Harmonic> harmonics_;
        int health_;
        int resonance_;
};

class Player: public Actor {
    public:
        Player(): Actor(100, 4) {};
        void attack(Actor*) override;
    private:
        static std::vector<Item> inventory_;
};

class RiftGuardian: public Actor {
    public:
        RiftGuardian(): Actor(200, 5, {Harmonic(5), Harmonic(4)}){};
        void attack(Actor*) override {};
};

#endif // !GAME_CLASSES_HPP
