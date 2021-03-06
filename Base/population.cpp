#include "population.h"
TEMPLATE
void Population<T>::InitializeDefault()
{
    evaluationSum = 0;
    deviationDefault = 0;
    numOfGenes = 0;
    instanceOfGenerateRandomGene = 0;
    instanceOfOperators = 0;
    instaceOfCalculateEvaluation = 0;
    instanceOfGenerateRandomChromosome = 0;
    instanceEnvironment = 0;
    ContIdChromosome = 0;
    defaultChromosomes.clear();
    swapChromosomes.clear();
}

TEMPLATE
Chromosome<T> Population<T>::GetCopyChromosome(Chromosome<T> Origin)
{
    Chromosome<T> retor;
    retor.SetGene(Origin.GetGene());
    return retor;
}

TEMPLATE
void Population<T>::UpdateEvaluationSum()
{
    if(instaceOfCalculateEvaluation == 0)
        throw "instaceOfCalculateEvaluation value not yet defined";
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
    else{
        this->numOfGenes = numGenes;
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
string Population<T>::CalculateNextPopulation(string (*ConvertoToString)(T value), bool generateLog)
{
    swapChromosomes.clear();
    UpdateEvaluationSum();

    string log = "";

    if(generateLog){
        log = this->ToStringJson(ConvertoToString);
    }

    if(evaluationSum == 0)
    {
        printf("[WARNING] The EvaluationSum is zero\n");
    }

    for(typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin(); it != defaultChromosomes.end(); it++){
        Chromosome<T> role = Roulette();
        bool add = false;
        if(Utility::GetChance(instanceEnvironment->GetCrossOverRate())){
            Chromosome<T> son = instanceOfOperators->CrossOverTwoPoint(*it,role);
            son.SetId(this->ContIdChromosome++);
            swapChromosomes.push_back(son);
            add = true;
        }
        role = GetCopyChromosome(role);
        if(Utility::GetChance(instanceEnvironment->GetChangeRate())){
            role = instanceOfOperators->Mutation(role);
            role.SetId(this->ContIdChromosome++);
            swapChromosomes.push_back(role);
            add = true;
        }
        if(!add){
            role.SetId(this->ContIdChromosome++);
            swapChromosomes.push_back(role);
        }
    }
    defaultChromosomes = swapChromosomes;
    return log;
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
Chromosome<T> Population<T>::GetChromosomeAt(int index)
{
    typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin();
    if((int)defaultChromosomes.size() > index && index >= 0)
        for(;index!=0;index--)
            it++;
    return *it;
}

TEMPLATE
void Population<T>::AddChromosome(Chromosome<T> addValue)
{
    defaultChromosomes.push_back(addValue);
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
    return (int)defaultChromosomes.size();
}

TEMPLATE
double Population<T>::GetDefaultDeviation()
{
    return deviationDefault;
}

TEMPLATE
void Population<T>::SetGenerateRandomGene(GenerateRandomGene<T> *rand)
{
    if(rand == 0)
        throw "Instance of GenerateRandomGene is null";
    instanceOfGenerateRandomGene = rand;
}

TEMPLATE
void Population<T>::SetGenerateRandomChormosome(GenerateRandomChromosome<T> *rand)
{
    if(rand == 0)
        throw "Instance of GenerateRandomChormosome is null";
    instanceOfGenerateRandomChromosome = rand;
}

TEMPLATE
GenerateRandomChromosome<T> *Population<T>::GetGenerateRandomChormosome()
{
    return instanceOfGenerateRandomChromosome;
}

TEMPLATE
void Population<T>::SetCalculateEvaluation(CalculateEvaluation<T> *calc)
{
    if(calc == 0)
        throw "Instance of CalculateEvaluation is null";
    instaceOfCalculateEvaluation = calc;
}

TEMPLATE
CalculateEvaluation<T> *Population<T>::GetCalculateEvaluation()
{
    return instaceOfCalculateEvaluation;
}

TEMPLATE
void Population<T>::SetOperators(Operators<T>* ope)
{
    if(ope == 0)
        throw "Instance of Operators is invalid";
    instanceOfOperators = ope;
}

TEMPLATE
std::string Population<T>::GetStringPopulation(std::string *convertGeneToString)
{
    std::string retorno;
    for(int i = 0; i < this->GetNumChromosomes(); i++){
        Chromosome<T> at = this->getChromosomeAt(i);
        retorno += std::string("[");
        for(int j = 0; j < at.GetNumberOfElements(); j++){
            retorno += (*convertGeneToString)(at.GetGeneAt(j));
            if(j < (at.GetNumberOfElements()-1))
                retorno += std::string(", ");
        }
        retorno += std::string("]\n");
    }
    return retorno;
}

TEMPLATE
string Population<T>::ToStringJson(string (*ConvertoToString)(T))
{
    JsonObject json("Population");
    json.AddIntValue("ID",this->GetId());
    json.AddDoubleValue("evaluationSum",evaluationSum);
    json.AddDoubleValue("deviationDefault", deviationDefault);
    json.AddIntValue("populationSize", GetSizePopulation());
    json.AddIntValue("numOfGenes", numOfGenes);
    json.AddObjectValue(instanceEnvironment->ToStringJson());
    if(ConvertoToString!=0){
        string array = "[";
        typename list<Chromosome<T> >::iterator it = defaultChromosomes.begin();
        for(int i = 0, n = (int)defaultChromosomes.size(); it != defaultChromosomes.end(); it++, i++){
            array += it->ToStringJson(ConvertoToString);
            if(i != (n-1)) array += ",";
        }
        array += "]";
        json.AddStringValue("Chromosomes",array);
    }
    return json.GetJsonObjectNoName();
}
