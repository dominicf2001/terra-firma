#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "utilities.hpp"
using std::cout;

int RandomNumGen::gen(int min, int max) {
    // update distribution
    using param_type = std::uniform_int_distribution<int>::param_type;
    dist.param(param_type(min, max));
    return dist(rng);
}

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void printSkull() {
    cout << R"(
  _____
 /     \
| () () |
 \  ^  /
  |||||
  |||||
)" << '\n';
}

void printTrophy() {
    cout << R"(
                                  ___________
                             .---'::'        `---.
                            (::::::'              )
                            |`-----._______.-----'|
                            |              :::::::|
                           .|               ::::::!-.
                           \|               :::::/|/
                            |               ::::::|
                            | Special Flonk Award:|
                            |    for Silliness::::|
                            |               ::::::|
                            |              .::::::|
                            J              :::::::F
                             \            :::::::/
                              `.        .:::::::'
                                `-._  .::::::-'
____________________________________|  """|"_________________________________________
                                    |  :::|
                                    F   ::J
                                   /     ::\
                              __.-'      :::`-.__
                             (_           ::::::_)
                               `"""---------"""'
)" << '\n';
}
