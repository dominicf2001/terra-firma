#include "game-elements.hpp"
#include "game-actors.hpp"
#include <memory>
#include <iostream>

int main() {
    Player* player = Player::getInstance();
    player->printHarmonics();

    return 0;
}
