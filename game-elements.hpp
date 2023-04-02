#pragma once
#include "utilities.hpp"
#include <memory>
#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
using std::string;
using std::shared_ptr;

// HARMONICS
class Harmonic {
    public:
        enum class Type {
            attack,
        };
        Harmonic(string name, string desc, int resReq, Type type) : name_(name), desc_(desc), resReq_(resReq), type_(type) {};

        virtual void use(std::function<void(int)>)=0;
        string getName() const {return name_;}
        string getDesc() const {return desc_;}
        int getResReq() const {return resReq_;}
        Type getType() const {return type_;}
    private:
        string name_;
        string desc_;
        int resReq_;
        Type type_;
};

class AttackHarmonic : public Harmonic {
    public:
        AttackHarmonic(string name, string desc, int resReq, int minDmg, int maxDmg)
        : Harmonic(name, desc, resReq, Type::attack),
            minDmg_(minDmg), maxDmg_(maxDmg){};
        void use(std::function<void(int)>) override;
        int rollDmg() const {
            RandomNumGen rng;
            return rng.gen(minDmg_, maxDmg_);
        }
        int getMinDmg() const {return minDmg_;}
        int getMaxDmg() const {return maxDmg_;}
    private:
        int minDmg_;
        int maxDmg_;
};

class ResonanceBlast : public AttackHarmonic {
    public:
        ResonanceBlast()
            : AttackHarmonic("Resonance Blast","Channel energy from The Essence to unleash a concentrated blast of resonant force" , 2, 27, 32) {};
};

// ITEMS
class Item;
class ItemFactory {
    public:
        shared_ptr<Item> getCaveDoorKeyOne() {
            return getItem("Cave Door Key One", "Opens cave door");
        }
        static ItemFactory& getInstance() {
            static ItemFactory instance;
            return instance;
        }
    private:
        ItemFactory(){};
        ItemFactory(ItemFactory&) = delete;
        ItemFactory& operator=(ItemFactory) = delete;
        shared_ptr<Item> getItem(string name, string desc);
        std::unordered_map<string, shared_ptr<Item>> items_;
};

class Item {
    public:
        Item(string name, string desc) {
            name_ = name;
            desc_ = desc;
        }
        string getName() const {return name_;}
        string getdesc() const {return desc_;}
    private:
        string name_;
        string desc_;
};
