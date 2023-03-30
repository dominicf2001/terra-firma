#include "game-elements.hpp"
#include <memory>

std::shared_ptr<Item> ItemFactory::getItem(string name, string desc) {
    auto it = items_.find(name);
    if (it != items_.end()) {
        return it->second;
    }
    auto item = std::make_shared<Item>(name, desc);
    items_[name] = item;
    return item;
}

std::shared_ptr<Harmonic> HarmonicFactory::getHarmonic(string name, string desc, int minDmg, int maxDmg, int resonanceRequirement) {
    auto it = harmonics_.find(name);
    if (it != harmonics_.end()) {
        return it->second;
    }
    auto harmonic = std::make_shared<Harmonic>(name, desc, minDmg, maxDmg, resonanceRequirement);
    harmonics_[name] = harmonic;
    return harmonic;
}



