#ifndef POPULATION_H
#define POPULATION_H
#include "definesmacros.h"
#include "environment.h"
#include "chromosome.h"
#include "generaterandomgene.h"
#include "generaterandomchromosome.h"
#include "include/operators.hpp"
#include "utility.h"
#include "include/baseclassid.hpp"
#include "calculateevaluation.h"
#include <cstdio>
#include <cstdlib>
#include <random>
#include <list>
TEMPLATE
class Population : public BaseClassId
{
private:
    void InitializeDefault();
    double evaluationSum;
    double deviationDefault;
    int populationSize;
    int numOfGenes;
    std::list<Chromosome<T> > defaultChromosomes;
    std::list<Chromosome<T> > swapChromosomes;
    GenerateRandomGene<T> * instanceOfGenerateRandomGene;
    Environment * instanceEnvironment;
    Operators<T> * instanceOfOperators;
    CalculateEvaluation<T> * instaceOfCalculateEvaluation;
    GenerateRandomChromosome<T> * instanceOfGenerateRandomChromosome;
public:
    Population();
    Population(int id);
    ~Population();
    void Clear();
    void UpdateEvaluationSum(); // update Evaluation of all Chromosomes
    void InitilizePopulation(int sizePopulation, int numGenes);
    Chromosome<T> Roulette();
    Chromosome<T> GetBestChromosome();
    double GetEvaluationSum();
    void CalculateNextPopulation();
};
#endif // POPULATION_H
