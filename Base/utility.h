#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <random>
#include <chrono>

class Utility{
public:
    static bool GetChance(double probability){
        default_random_engine generator;
        auto now = chrono::high_resolution_clock::now();
        auto timeMillis = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();
        generator.seed (timeMillis);
        bernoulli_distribution distribution(probability);
        return (distribution(generator));
    }
};

#endif // UTILITY_H
