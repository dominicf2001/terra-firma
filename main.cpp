#include "game-objects.hpp"
#include <memory>

int main() {
    std::unique_ptr<Rouge> rouge = EnemyFactory<Rouge>::createEnemy();
    rouge->printHarmonics();

    return 0;
}
