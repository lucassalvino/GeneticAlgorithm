#ifndef GENERATERANDOMCHROMOSOME_H
#define GENERATERANDOMCHROMOSOME_H
#include "definesmacros.h"
#include "chromosome.h"
TEMPLATE
class GenerateRandomChromosome{
public:
    virtual Chromosome<T> GenerateChromosome(int numGenes, int ID)
    {
        numGenes = ID = 0;
        throw "GenerateChromosome not implements";
    }
};
#endif // GENERATERANDOMCHROMOSOME_H
