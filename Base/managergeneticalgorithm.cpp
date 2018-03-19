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

template<class T>
void ManagerGeneticAlgorithm<T>::SetGenerateRandomGene(GenerateRandomGene<T> *random)
{
    population.SetGenerateRandomGene(random);
}

template<class T>
void ManagerGeneticAlgorithm<T>::SetGenerateRandomChormosome(GenerateRandomChromosome<T>* random)
{
    population.SetGenerateRandomChormosome(random);
}

template<class T>
void ManagerGeneticAlgorithm<T>::SetCalculateEvaluation(CalculateEvaluation<T> *calc)
{
    population.SetCalculateEvaluation(calc);
}

TEMPLATE
std::list<Generation<T> > ManagerGeneticAlgorithm<T>::getBestsChromosome()
{
    return bestsChromosome;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::setBestsChromosome(std::list<Generation<T> > &value)
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
