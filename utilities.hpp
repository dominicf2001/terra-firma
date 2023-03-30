#pragma once
#include <random>
class RandomNumGen {
    public:
        RandomNumGen() :
            rng(std::random_device{}()), dist(1, 1) {};
        int gen(int min, int max);
    private:
        std::mt19937 rng;
        std::uniform_int_distribution<int> dist;
};
void getRandomInt(int, int);
void sleep(int);
void printSkull();
void printTrophy();


