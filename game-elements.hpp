#ifndef GAME_CLASSES_HPP

#include <type_traits>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
using std::string;
using std::vector;

class Item {
    public:
        Item(string name, string desc) {
            name_ = name;
            desc_ = desc;
        }
        string getName() const {return name_;}
        string getDesc() const {return desc_;}
    private:
        std::string name_;
        std::string desc_;
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

class ItemFactory {
    public:
        std::shared_ptr<Item> getCaveDoorKeyOne() {
            return getItem("Cave Door Key One", "Opens cave door");
        }
        static ItemFactory& getInstance() {
            static ItemFactory instance;
            return instance;
        }
    private:
        std::shared_ptr<Item> getItem(string name, string desc) {
            auto it = items_.find(name);
            if (it != items_.end()) {
                return it->second;
            }
            auto item = std::make_shared<Item>(name, desc);
            items_[name] = item;
            return item;
        }
        std::unordered_map<string, std::shared_ptr<Item>> items_;
};


class HarmonicFactory {
    public:
        std::shared_ptr<Harmonic> getResonanceBlast() {
            return getHarmonic("Resonance Blast", "Channel energy from The Essence to unleash a concentrated blast of resonant force", 30, 2);
        }
        static HarmonicFactory& getInstance() {
            static HarmonicFactory instance;
            return instance;
        }
    private:
        std::shared_ptr<Harmonic> getHarmonic(string name, string desc, int attack, int resonanceRequirement) {
            auto it = harmonics_.find(name);
            if (it != harmonics_.end()) {
                return it->second;
            }
            auto harmonic = std::make_shared<Harmonic>(name, desc, attack, resonanceRequirement);
            harmonics_[name] = harmonic;
            return harmonic;
        }
        std::unordered_map<string, std::shared_ptr<Harmonic>> harmonics_;
};

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

#endif // !GAME_CLASSES_HPP
