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
    static double fRand(double fMin, double fMax){ /*https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c*/
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    static bool GetChance(double probability){
        std::default_random_engine generator;
        auto now = std::chrono::high_resolution_clock::now();
        auto timeMillis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        generator.seed (timeMillis);
        std::bernoulli_distribution distribution(probability);
        return (distribution(generator));
    }
};

#endif // UTILITY_H
