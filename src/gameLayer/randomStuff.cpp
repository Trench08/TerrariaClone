//
// Created by vsuni on 30/07/2026.
//

#include "randomStuff.h"

#include <random>

// Returns a float in [min, max]
float getRandomFloat(std::ranlux24_base &rng, float min, float max)
{
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(rng);
}

// Returns an int in [min, max]
int getRandomInt(std::ranlux24_base &rng, int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

bool getRandomChance(std::ranlux24_base &rng, float chance)
{
    float dice = getRandomFloat(rng, 0.0, 1.0);
    return dice <= chance;
}