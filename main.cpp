#include "game-elements.hpp"
#include "game-actors.hpp"
#include "battle-logic.hpp"
#include <memory>
#include <iostream>
using std::make_shared; using std::shared_ptr;

int main() {
    shared_ptr<Player> player = Player::getInstance();

    player->startBattle(make_shared<RiftGuardian>("Test Guardian"));
    return 0;
}
