#pragma once
#include "utilities.hpp"
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
        Harmonic(string name, string desc, int minDmg, int maxDmg, int resonanceReq) {
            name_ = name;
            desc_ = desc;
            minDmg_ = minDmg;
            maxDmg_ = maxDmg;
            resonanceReq_ = resonanceReq;
        };
        string getName() const {return name_;}
        string getDesc() const {return desc_;}
        int getDmg() const {
            RandomNumGen rng;
            return rng.gen(minDmg_, maxDmg_);
        }
        int getMinDmg() const {return minDmg_;}
        int getMaxDmg() const {return maxDmg_;}
        int getResonanceReq() const {return resonanceReq_;}
    private:
        string name_;
        string desc_;
        int minDmg_;
        int maxDmg_;
        int resonanceReq_;
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
            return getHarmonic("Resonance Blast", "Channel energy from The Essence to unleash a concentrated blast of resonant force", 27, 32, 2);
        }
        static HarmonicFactory& getInstance() {
            static HarmonicFactory instance;
            return instance;
        }
    private:
        std::shared_ptr<Harmonic> getHarmonic(string name, string desc, int minDmg, int maxDmg, int resonanceRequirement);
        std::unordered_map<string, std::shared_ptr<Harmonic>> harmonics_;
};

