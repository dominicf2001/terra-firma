#include "game-elements.hpp"
#include "game-actors.hpp"
#include "battle-logic.hpp"
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<Actor> player = std::make_shared<Player>("Player");
    std::shared_ptr<Actor> testGuardian = std::make_shared<RiftGuardian>("Test Guardian");
    startBattle(player, testGuardian);

    return 0;
}
