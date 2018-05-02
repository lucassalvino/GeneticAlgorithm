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
bool ManagerGeneticAlgorithm<T>::GetShowLog()
{
    return showLog;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetShowLog(bool value)
{
    showLog = value;
}

TEMPLATE
int ManagerGeneticAlgorithm<T>::GetNumberClusters()
{
    return numberClusters;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetNumberClusters(int value)
{
    numberClusters = value;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetFunctionConvertGeneAtString(std::string (*function)(T))
{
    if(function == 0){
        throw "Não é possível setar o valor da funcao de conversao como nulo";
    }
    FunctionConvertGeneAtString = function;
}

TEMPLATE
std::string ManagerGeneticAlgorithm<T>::GetLog()
{
    return log;
}

TEMPLATE
std::string ManagerGeneticAlgorithm<T>::GetFolder()
{
    return folder;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SetFolderLog(std::string &value)
{
    folder = value;
}

TEMPLATE
Population<T> *ManagerGeneticAlgorithm<T>::GetPopulation(){
    return &population;
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
void ManagerGeneticAlgorithm<T>::RunGeneticAlgorithm(Environment enviromnent, int numGeneration,int sizePopulation, int numGenes, Operators<T>* operators, string (*ConvertoToString)(T))
{
    population.SetId(ContIdPopulation);
    population.SetEnvironment( & enviromnent);

    population.InitilizePopulation(sizePopulation, numGenes);

    population.SetOperators(operators);

    ExecutaCluster(this->population, numGeneration, ConvertoToString);

    //executa clusters
    int numberElementsByClusters = sizePopulation / numberClusters;
    int ChAt = 0;
    for(int i = 0; i < numberClusters; i++){
        Population<T> newPopulation;
        newPopulation.SetEnvironment( & enviromnent);
        newPopulation.SetOperators(operators);
        newPopulation.SetGenerateRandomChormosome(population.GetGenerateRandomChormosome());
        newPopulation.SetCalculateEvaluation(population.GetCalculateEvaluation());
        newPopulation.SetId(++ContIdPopulation);
        for(int j = 0; j < numberElementsByClusters; j++)
            newPopulation.AddChromosome(population.GetChromosomeAt(ChAt++));
        ExecutaCluster(newPopulation, numGeneration, ConvertoToString);
    }
}

TEMPLATE
std::string ManagerGeneticAlgorithm<T>::GetStringOfPopulation()
{
    std::string retorno;
    retorno += std::string("'Population ID':"+FunctionConvertGeneAtString(this->GetId()));
    return retorno;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::ExecutaCluster(Population<T> population, int numGeneration, string (*ConvertoToString)(T))
{
    list<string> logs;
    for(int i = 0; i < numGeneration; i++)
    {
        string logAt = (population.CalculateNextPopulation(ConvertoToString, (showLog || saveLog)));
        if(showLog)
            cout<<logAt<<endl;
        if(saveLog)
            logs.push_back(logAt);
    }
    if(saveLog){
        this->SaveLogFile(logs, population.GetId());
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
    JsonLog = 0;
    numberClusters = 4;
    ContIdPopulation = 0;
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::AddLogPopulation(){
    if(JsonLog == 0)JsonLog = new JsonObject("ResultGeneticAlgorithm");
    JsonObject geneAt("Population");
}

TEMPLATE
void ManagerGeneticAlgorithm<T>::SaveLogFile(list<string> logs, int IdPopulation)
{
    string fileName = folder + string("/ReportGeneticAlgorithm_"+UtilidadeConvert<int>::GetNumber(IdPopulation)+string(".json"));
    FILE* arq = fopen(fileName.c_str(), "w");
    if(arq == 0)throw "Arquivo nao acessivel";
    fprintf(arq, "[");
    int i = 0;
    for (list<string>::iterator it = logs.begin(); it != logs.end(); it++, i++){
        fprintf(arq,"%s", it->c_str());
        if(i != ((int)logs.size()-1)) fprintf(arq, ",");
    }
    fprintf(arq, "]");
    fclose(arq);
}
