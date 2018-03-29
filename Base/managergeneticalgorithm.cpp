#include "managergeneticalgorithm.h"

TEMPLATE
ManagerGeneticAlgorithm<T>::ManagerGeneticAlgorithm(): BaseClassId()
{
    DefaultInitialize();
}

TEMPLATE
ManagerGeneticAlgorithm<T>::ManagerGeneticAlgorithm(int id): BaseClassId(id)
{
    DefaultInitialize();
}

TEMPLATE
bool ManagerGeneticAlgorithm<T>::GetSaveLog()
{
    return saveLog;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetSaveLog(bool value)
{
    saveLog = value;
}

TEMPLATE
std::string ManagerGeneticAlgorithm<T>::GetLog()
{
    return log;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetLog(std::string &value)
{
    log = value;
}

TEMPLATE
std::string ManagerGeneticAlgorithm<T>::GetFolder()
{
    return folder;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetFolder(std::string &value)
{
    folder = value;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::GetPopulation(){
    return this->population;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetGenerateRandomGene(GenerateRandomGene<T> *random)
{
    population.SetGenerateRandomGene(random);
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetGenerateRandomChormosome(GenerateRandomChromosome<T>* random)
{
    population.SetGenerateRandomChormosome(random);
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetCalculateEvaluation(CalculateEvaluation<T> *calc)
{
    population.SetCalculateEvaluation(calc);
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::RunGeneticAlgorithm(Environment enviromnent, int numGeneration,int sizePopulation, int numGenes, Operators<T>* operators)
{
    population.SetEnvironment(enviromnent);

    population.InitilizePopulation(sizePopulation, numGenes);

    population.SetOperators(operators);

    for(int i = 0; i < numGeneration; i++)
    {
        population.CalculateNextPopulation();
    }
}

TEMPLATE
std::list<Generation<T> > ManagerGeneticAlgorithm<T>::getBestsChromosome()
{
    return bestsChromosome;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetBestsChromosome(std::list<Generation<T> > &value)
{
    bestsChromosome = value;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::DefaultInitialize()
{
    saveLog = false;
    log = "";
    folder = "";
}
