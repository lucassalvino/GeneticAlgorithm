#ifndef GENERATION_H
#define GENERATION_H
#include "include/baseclassid.hpp"
#include "include/chromosome.hpp"
#include "environment.h"

TEMPLATE
class Generation : public BaseClassId
{
public:
    Generation();
    Generation(int id);
    void SetEvaluatioSum(double value);
    double GetEvaluationSum();
    void SetBestChromosome(Chromosome<T> value);
    Chromosome<T> GetBestChromosome();
    void SetEnvironment(Environment value);
    Environment GetEnvironment();
private:
    double evaluatioSum;
    Chromosome<T> bestChromosome;
    Environment environment;
};

#endif // GENERATION_H
