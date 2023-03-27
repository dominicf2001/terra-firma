#ifndef GAME_CLASSES_HPP

#include <type_traits>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
using std::string;

class Item {
    public:
        Item();
    private:
        std::string name;
        std::string description;
};

class Harmonic {
    public:
        Harmonic(int resonanceRequirement): resonanceRequirement_(resonanceRequirement){};
        int getResonanceRequirement() const {return resonanceRequirement_;}
    private:
        int resonanceRequirement_;
        string name;
        string description;
        int attack;
};

class Actor {
    public:
        Actor(int health=100, int resonance=1, std::vector<Harmonic> harmonics={}): health_(health), resonance_(resonance), harmonics_(harmonics){};

        virtual void attack()=0;
        virtual ~Actor() = default;
        void printHarmonics() const {
            for (auto h : harmonics_)
                std::cout << h.getResonanceRequirement();
        };
    private:
        std::vector<Harmonic> harmonics_;
        int health_;
        int resonance_;
};

class Player: public Actor {
    public:
        Player(): Actor(100, 4) {};
        void attack() override;
    private:
        static std::vector<Item> inventory_;
};

class RiftGuardian: public Actor {
    public:
        RiftGuardian(): Actor(200, 5, {Harmonic(5), Harmonic(4)}){};
        void attack() override {};
};

#endif // !GAME_CLASSES_HPP
