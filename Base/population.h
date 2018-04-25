#ifndef POPULATION_H
#define POPULATION_H
#include "definesmacros.h"
#include "environment.h"
#include "include/chromosome.hpp"
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
#include "../MineJsonSuport/jsonobject.h"
TEMPLATE
class Population : public BaseClassId
{
private:
    void InitializeDefault();
    double evaluationSum;
    double deviationDefault;
    int populationSize;
    int numOfGenes;
    int idGeneration;
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
    string CalculateNextPopulation(bool generateLog, string (*ConvertoToString)(T));
    Environment* GetEnvironment();
    void SetEnvironment(Environment* value);
    int GetNumChromosomes();
    Chromosome<T> getChromosomeAt(int index);
    int GetNumGene();
    void SetNumGene(int value);
    int GetSizePopulation();
    double GetDefaultDeviation();
    void SetGenerateRandomGene(GenerateRandomGene<T>* rand);
    void SetGenerateRandomChormosome(GenerateRandomChromosome<T>* rand);
    void SetCalculateEvaluation(CalculateEvaluation<T>* calc);
    void SetOperators(Operators<T>* ope);
    std::string GetStringPopulation(std::string *convertGeneToString);
    std::string ToStringJson(string (*ConvertoToString)(T));
};
#endif // POPULATION_H
