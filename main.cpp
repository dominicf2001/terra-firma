#include "game-classes.hpp"
#include <memory>

int main() {
    std::unique_ptr<Actor> rogue = std::make_unique<Rogue>();
    rogue->printHarmonics();

    return 0;
}
