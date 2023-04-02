#include "game-elements.hpp"
#include <memory>
using std::shared_ptr; using std::make_shared;

shared_ptr<Item> ItemFactory::getItem(string name, string desc) {
    auto it = items_.find(name);
    if (it != items_.end()) {
        return it->second;
    }
    auto item = make_shared<Item>(name, desc);
    items_[name] = item;
    return item;
}

void AttackHarmonic::use(std::function<void(int)> effectCallback) {
    int dmg = rollDmg();
    effectCallback(dmg);
}
