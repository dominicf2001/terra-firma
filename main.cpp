#include "game-elements.hpp"
#include "game-actors.hpp"
#include "battle-logic.hpp"
#include <memory>
#include <iostream>

int main() {
    EnemyFactory& eFac = EnemyFactory::getInstance();

    startBattle(Player::getInstance(), eFac.getRiftGuardian("Rift Guardian"));

    return 0;
}
