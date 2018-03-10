#ifndef MANAGERGENETICALGORITHM_H
#define MANAGERGENETICALGORITHM_H
#include "definesmacros.h"
#include "include/population.hpp"
#include "include/generation.hpp"
#include "include/baseclassid.hpp"
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
    void setBestsChromosome(std::list<Generation<T> > &value);
    //void RunGeneticAlgorithm(GenerateGene<T> *generateGene,CalculateEvaluation<TIPO>*calculateEval,Environment enviromnent,GenerateRandomChromosome<TIPO>* generateRandomChormossome,int numGeneration,int sizePopulation, int numGenes, Operators<TIPO>* operators = new Operators<TIPO>());
private:
    bool saveLog;
    std::string log;
    std::string folder;
    std::list<Generation<T> > bestsChromosome;
    void DefaultInitialize();
};

#endif // MANAGERGENETICALGORITHM_H
