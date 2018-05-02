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
    bool GetShowLog();
    void SetShowLog(bool value);
    int GetNumberClusters();
    void SetNumberClusters(int value);
    void SetFunctionConvertGeneAtString(std::string(*function)(T));
    std::string GetLog();
    std::string GetFolder();
    void SetFolderLog(std::string &value);
    std::list<Generation<T> > getBestsChromosome();
    void SetBestsChromosome(std::list<Generation<T> > &value);
    Population<T>* GetPopulation();
    void SetGenerateRandomGene(GenerateRandomGene<T>* random);
    void SetGenerateRandomChormosome(GenerateRandomChromosome<T>* random);
    void SetCalculateEvaluation(CalculateEvaluation<T>* calc);
    void RunGeneticAlgorithm(Environment enviromnent, int numGeneration,int sizePopulation, int numGenes, Operators<T>* operators = new Operators<T>(), string (*ConvertoToString)(T) = 0);
    std::string GetStringOfPopulation();
    void ExecutaCluster(Population<T> population, int numGeneration,string (*ConvertoToString)(T));
private:
    bool saveLog;
    bool showLog;
    int numberClusters;
    int ContIdPopulation;
    std::string (*FunctionConvertGeneAtString)(T);
    std::string log;
    std::string folder;
    JsonObject* JsonLog;
    std::list<Generation<T> > bestsChromosome;
    Population<T> population;
    void DefaultInitialize();
    void AddLogPopulation();
    void SaveLogFile(list<string>logs, int IdPopulation);
};

#endif // MANAGERGENETICALGORITHM_H
