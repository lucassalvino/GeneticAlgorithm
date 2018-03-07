#ifndef CALCULATEEVALUATION_H
#define CALCULATEEVALUATION_H
#include "definesmacros.h"
#include "chromosome.h"
TEMPLATE
class CalculateEvaluation{
public:
    virtual double calculateEvaluation(Chromosome<T> value,int init, int final)
    {
        return value = init = final = 0;
    }
    virtual double calculateEvaluation(Chromosome<T> value)
    {
        return value = 0;
    }
    virtual double getEvaluation(Chromosome<T>* value)
    {
        return value = 0;
    }
};
#endif // CALCULATEEVALUATION_H
