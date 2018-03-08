#ifndef POPULATION_H
#define POPULATION_H
#include "definesmacros.h"
#include "environment.h"
#include "chromosome.h"
#include "generaterandomgene.h"
#include "generaterandomchromosome.h"
#include "operators.h"
#include "utility.h"
#include "templateclassid.h"
#include "calculateevaluation.h"
#include <cstdio>
#include <cstdlib>
#include <random>
#include <list>
TEMPLATE
class Population : public TemplateClassId
{
private:
    void UpdateEvaluationSum() // update Evaluation of all Chromosomes
    {
        evaluationSum = deviationDefault = 0;
        for(typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin(); it != defaultChromosomes.end(); it++)
        {
            it->SetEvaluation(instaceOfCalculateEvaluation->GetEvaluation(&(*it)));
            evaluationSum += it->GetEvaluation();
        }
    }
    void InitializeDefault()
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
    Population():TemplateClassId(){
        InitializeDefault();
    }
    Population(int id):TemplateClassId(id){
        InitializeDefault();
    }
    ~Population(){
        Clear();
    }
    void Clear(){
        InitializeDefault();
    }

    void UpdateEvaluation()
    {
        UpdateEvaluationSum();
    }

    void InitilizePopulation(int sizePopulation, int numGenes)
    {
        if(instanceOfGenerateRandomChromosome == 0)
            throw "Not Exists instance for GenerateRandomChromosome";
        for(int i = 0; i < sizePopulation; i++){
            defaultChromosomes.push_back(instanceOfGenerateRandomChromosome->GenerateChromosome(numGenes,i));
        }
    }

    Chromosome<T> Roulette()
    {
        double aux = 0;
        double limit =  Utility::fRand(0,this->evaluationSum);
        typename std::list<Chromosome<T> >::iterator it = defaultChromosomes.begin();
        for(; (aux < limit) && it != defaultChromosomes.end(); it++){
            aux += it->GetEvaluation();
        }
        return *it;
    }

    Chromosome<T> GetBestChromosome()
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
    double GetEvaluationSum()
    {
        return evaluationSum;
    }
    void CalculateNextPopulation()
    {
        swapChromosomes.clear();
        UpdateEvaluationSum();
        if(evaluationSum == 0){
            printf("\n[PERIGO] A populacao [%d] esta com nenhum individuo valido, todos com aptidao = 0\n\tA roleta nao irá selecionar nenhum individuo\n\n",this->idGeneration);
        }
        for(typename list<Chromosome<T> >::iterator it = defaultChromosomes.begin(); it != defaultChromosomes.end(); it++){
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
                new_chromosomes.push_back(role);
                add = true;
            }
            if(!add){
                swapChromosomes.push_back(role);
            }
        }
    }
};

#endif // POPULATION_H
