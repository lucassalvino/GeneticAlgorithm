#include "population.h"
TEMPLATE
void Population<T>::InitializeDefault()
{
    evaluationSum = 0;
    deviationDefault = 0;
    populationSize = 0;
    numOfGenes = 0;
    instanceOfGenerateRandomGene = 0;
    instanceOfOperators = 0;
    instaceOfCalculateEvaluation = 0;
    instanceOfGenerateRandomChromosome = 0;
    instanceEnvironment = 0;
    defaultChromosomes.clear();
    swapChromosomes.clear();
}

TEMPLATE
void Population<T>::UpdateEvaluationSum()
{
    evaluationSum = deviationDefault = 0;
    for(typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin(); it != defaultChromosomes.end(); it++)
    {
        it->SetEvaluation(instaceOfCalculateEvaluation->GetEvaluation(&(*it)));
        evaluationSum += it->GetEvaluation();
    }
}

TEMPLATE
Population<T>::Population():BaseClassId(){
    InitializeDefault();
}

TEMPLATE
Population<T>::Population(int id):BaseClassId(id){
    InitializeDefault();
}

TEMPLATE
Population<T>::~Population(){
    Clear();
}

TEMPLATE
void Population<T>::Clear(){
    InitializeDefault();
}

TEMPLATE
void Population<T>::InitilizePopulation(int sizePopulation, int numGenes)
{
    if(instanceOfGenerateRandomChromosome == 0 && instanceOfGenerateRandomGene == 0)
        throw "Not Exists instance for GenerateRandomChromosome or instanceOfGenerateRandomGene";
    if(instanceOfGenerateRandomChromosome)
        for(int i = 0; i < sizePopulation; i++)
            defaultChromosomes.push_back(instanceOfGenerateRandomChromosome->GenerateChromosome(numGenes,i));
    else
        for(int i = 0; i < sizePopulation; i++)
        {
            Chromosome<T> valueAdd;
            std::vector<T> genes;
            for(int j = 0; j < numOfGenes; j++)
                genes.push_back(instanceOfGenerateRandomGene->GetRandomGene());
            valueAdd.SetGene(genes);
            defaultChromosomes.push_back(valueAdd);
        }
}

TEMPLATE
Chromosome<T> Population<T>::Roulette()
{
    double aux = 0;
    double limit =  Utility::fRand(0,this->evaluationSum);
    typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin();
    for(; (aux < limit) && it != defaultChromosomes.end(); it++){
        aux += it->GetEvaluation();
    }
    it--;
    return *it;
}

TEMPLATE
Chromosome<T> Population<T>::GetBestChromosome()
{
    Chromosome<T>* ret;
    double bestEvaluation = -9000;
    for(typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin(); it != defaultChromosomes.end(); it++){
        if(it->GetEvaluation() > bestEvaluation){
            bestEvaluation = it->GetEvaluation();
            ret = &(*it);
        }
    }
    return *ret;
}

TEMPLATE
double Population<T>::GetEvaluationSum()
{
    return evaluationSum;
}

TEMPLATE
void Population<T>::CalculateNextPopulation()
{
    swapChromosomes.clear();
    UpdateEvaluationSum();
    if(evaluationSum == 0){
        printf("\n[PERIGO] A populacao [%d] esta com nenhum individuo valido, todos com aptidao = 0\n\tA roleta nao irá selecionar nenhum individuo\n\n",this->idGeneration);
    }
    for(typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin(); it != defaultChromosomes.end(); it++){
        Chromosome<T> role = Roulette();
        bool add = false;
        if(Utility::GetChance(instanceEnvironment->GetCrossOverRate())){
            Chromosome<T> son = instanceOfOperators->CrossOverTwoPoint(*it,role);
            son.SetId(this->idGeneration++);
            swapChromosomes.push_back(son);
            add = true;
        }
        if(Utility::GetChance(instanceEnvironment->GetChangeRate())){
            role = instanceOfOperators->Mutation(role);
            swapChromosomes.push_back(role);
            add = true;
        }
        if(!add){
            swapChromosomes.push_back(role);
        }
    }
}

TEMPLATE
Environment *Population<T>::GetEnvironment()
{
    return instanceEnvironment;
}

TEMPLATE
void Population<T>::SetEnvironment(Environment* value)
{
    if (value == 0)
        throw "The value of the Environment instance is null";
    instanceEnvironment = value;
}

TEMPLATE
int Population<T>::GetNumChromosomes()
{
    return (int)defaultChromosomes.size();
}

TEMPLATE
Chromosome<T> Population<T>::getChromosomeAt(int index)
{
    typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin();
    if((int)defaultChromosomes.size() > index && index >= 0)
        for(;index!=0;index--)
            it++;
    return *it;
}

TEMPLATE
int Population<T>::GetNumGene()
{
    return numOfGenes;
}

TEMPLATE
void Population<T>::SetNumGene(int value)
{
    if(value == 0)
        throw "The value of NumOfGene is zero";
    this->numOfGenes = value;
}

TEMPLATE
int Population<T>::GetSizePopulation()
{
    return populationSize;
}

TEMPLATE
double Population<T>::GetDefaultDeviation()
{
    return deviationDefault;
}

template<class T>
void Population<T>::SetGenerateRandomGene(GenerateRandomGene<T> *rand)
{
    if(rand == 0)
        throw "Instance of GenerateRandomGene is null";
    instanceOfGenerateRandomGene = rand;
}

template<class T>
void Population<T>::SetGenerateRandomChormosome(GenerateRandomChromosome<T> *rand)
{
    if(rand == 0)
        throw "Instance of GenerateRandomChormosome is null";
    instanceOfGenerateRandomChromosome = rand;
}

template<class T>
void Population<T>::SetCalculateEvaluation(CalculateEvaluation<T> *calc)
{
    if(calc == 0)
        throw "Instance of CalculateEvaluation is null";
    instaceOfCalculateEvaluation = calc;
}
