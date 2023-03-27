#ifndef GAME_OBJECTS_HPP

#include <type_traits>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

class Harmonic {
    public:
        Harmonic(int resonanceRequirement): resonanceRequirement_(resonanceRequirement){};
        int getResonanceRequirement() const {return resonanceRequirement_;}
    private:
        int resonanceRequirement_;
};

class Actor {
    public:
        Actor(int health=100, int resonance=1): health_(health), resonance_(resonance){};

        virtual void attack()=0;
        virtual ~Actor() = default;
    protected:
        std::vector<Harmonic> harmonics_;
        int health_;
        int resonance_;
};

class Player: public Actor {
    public:
        Player(): Actor(100, 4) {};
        static Player& getPlayer() {
            static Player instance;
            return instance;
        }

        void attack() override {};
    private:
        static std::vector<Item> inventory_;
};

template <typename T>
class EnemyFactory {
    public:
        static_assert(std::is_base_of<Actor, T>::value, "Template argument must be a subclass of Enemy");

        static std::unique_ptr<T> createEnemy() {
            return std::make_unique<T>();
        };
};

class Rouge : public Actor {
    public:
        Rouge(): harmonics_({Harmonic(4), Harmonic(1)}){};
        void attack() override {};
        void printHarmonics() const {
            for (auto h : harmonics_)
                std::cout << h.getResonanceRequirement() << '\n';
        }
    private:
        std::vector<Harmonic> harmonics_;
};

#endif // !GAME_OBJECTS_HPP
