#ifndef CALCULATEEVALUATION_H
#define CALCULATEEVALUATION_H
#include "definesmacros.h"
#include "chromosome.h"
TEMPLATE
class CalculateEvaluation{
public:
    virtual double GetEvaluation(Chromosome<T>* value)
    {
        value = 0;
        value = value;
        return 0;
    }
};
#endif // CALCULATEEVALUATION_H
