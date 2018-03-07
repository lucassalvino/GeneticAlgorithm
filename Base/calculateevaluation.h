#ifndef CALCULATEEVALUATION_H
#define CALCULATEEVALUATION_H
#include "definesmacros.h"
#include "chromosome.h"
TEMPLATE
class CalculateEvaluation{
public:
    virtual double calculateEvaluation(Chromosome<T> value,int init, int final)
    {
        value = init = final = 0;
        return 0;
    }
    virtual double calculateEvaluation(Chromosome<T> value)
    {
        return value = 0;
    }
    virtual double GetEvaluation(Chromosome<T>* value)
    {
        return value = 0;
    }
};
#endif // CALCULATEEVALUATION_H
