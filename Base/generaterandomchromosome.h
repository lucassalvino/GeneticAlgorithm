#ifndef GENERATERANDOMCHROMOSOME_H
#define GENERATERANDOMCHROMOSOME_H
#include "definesmacros.h"
#include "chromosome.h"
TEMPLATE
class GenerateRandomChromosome{
public:
    virtual Chromosome<T> GenerateChromosome(int numGenes, int ID)
    {
        ID = 0;
        numGenes = 0;
        throw "GenerateChromosome not implements";
    }
};
#endif // GENERATERANDOMCHROMOSOME_H
