#pragma once

#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
using std::string;

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
        ItemFactory(){};
        ItemFactory(ItemFactory&) = delete;
        ItemFactory& operator=(ItemFactory) = delete;
        std::shared_ptr<Item> getItem(string name, string desc);
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
        std::shared_ptr<Harmonic> getHarmonic(string name, string desc, int attack, int resonanceRequirement);
        std::unordered_map<string, std::shared_ptr<Harmonic>> harmonics_;
};

