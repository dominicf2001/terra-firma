#include "game-actors.hpp"
#include "utilities.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <string>
using std::cout; using std::cin; using std::string;

std::shared_ptr<Player> Player::instance_ = nullptr;

