#include <iostream>
#include <thread>
#include <chrono>
using std::cout;

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
