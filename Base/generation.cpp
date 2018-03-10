#include "generation.h"

TEMPLATE
Generation<T>::Generation():BaseClassId()
{
    evaluatioSum = 0;
}

TEMPLATE
Generation<T>::Generation(int id):BaseClassId(id)
{
    evaluatioSum = 0;
}

TEMPLATE
void Generation<T>::SetEvaluatioSum(double value)
{
    this->evaluatioSum = value;
}

TEMPLATE
double Generation<T>::GetEvaluationSum()
{
    return this->evaluatioSum;
}

TEMPLATE
void Generation<T>::SetBestChromosome(Chromosome<T> value)
{
    this->bestChromosome = value;
}

TEMPLATE
Chromosome<T> Generation<T>::GetBestChromosome()
{
    return bestChromosome;
}

TEMPLATE
void Generation<T>::SetEnvironment(Environment value)
{
    this->environment = value;
}

TEMPLATE
Environment Generation<T>::GetEnvironment()
{
    return this->environment;
}
