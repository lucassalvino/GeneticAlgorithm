#ifndef MANAGERGENETICALGORITHM_H
#define MANAGERGENETICALGORITHM_H
#include "definesmacros.h"
#include "include/population.hpp"
#include "include/generation.hpp"
#include "include/baseclassid.hpp"
#include "include/generaterandomgene.hpp"
#include "include/generaterandomchromosome.hpp"
#include <iostream>
#include <list>

TEMPLATE
class ManagerGeneticAlgorithm: public BaseClassId
{
public:
    ManagerGeneticAlgorithm();
    ManagerGeneticAlgorithm(int id);
    bool GetSaveLog();
    void SetSaveLog(bool value);
    std::string GetLog();
    void SetLog(std::string &value);
    std::string GetFolder();
    void SetFolder(std::string &value);
    std::list<Generation<T> > getBestsChromosome();
    void SetBestsChromosome(std::list<Generation<T> > &value);
    Population<T>* GetPopulation();
    void SetGenerateRandomGene(GenerateRandomGene<T>* random);
    void SetGenerateRandomChormosome(GenerateRandomChromosome<T>* random);
    void SetCalculateEvaluation(CalculateEvaluation<T>* calc);
    void RunGeneticAlgorithm(Environment enviromnent, int numGeneration,int sizePopulation, int numGenes, Operators<T>* operators = new Operators<T>());
private:
    bool saveLog;
    std::string log;
    std::string folder;
    std::list<Generation<T> > bestsChromosome;
    Population<T> population;
    void DefaultInitialize();
};

#endif // MANAGERGENETICALGORITHM_H
