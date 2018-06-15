#ifndef UTOPIA_HELPERS_H
#define UTOPIA_HELPERS_H

#include <random>
#include <iostream>

//cpp11 random gen mechanism is recommended since ats::rand considered as harmful
class Random {
public:
    Random() : engine(std::random_device{}()) {}

    int integer(int min, int max) {
        std::uniform_int_distribution<>::param_type params{min, max};
        return int_dist(engine, params);
    }

private:
    std::mt19937 engine;
    std::uniform_int_distribution<> int_dist;
};

#endif //UTOPIA_HELPERS_H