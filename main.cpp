#include "game-classes.hpp"
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<Actor> player = std::make_unique<Player>();
    player->printSelf();

    return 0;
}
