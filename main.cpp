#include "game-elements.hpp"
#include "game-actors.hpp"
#include "battle-logic.hpp"
#include <memory>
#include <iostream>
using std::make_shared; using std::shared_ptr;

int main() {

    startBattle(Player::getInstance(), make_shared<RiftGuardian>("Test Guardian"));

    return 0;
}
