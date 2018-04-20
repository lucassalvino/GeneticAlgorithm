#ifndef EXECUTAAGCAMINHOGRAFO_H
#define EXECUTAAGCAMINHOGRAFO_H
#include "../Base/include/managergeneticalgorithm.hpp"
#include "customgeneraterandomchromosome.h"

class ExecutaAGCaminhoGrafo{
public:
    void Executa(){
        CustomGenerateRandomChromosome* add = new CustomGenerateRandomChromosome();
        add->SetMaxValuesGene(2);
        gerenteAG.GetPopulation()->SetGenerateRandomChormosome(add);
        gerenteAG.RunGeneticAlgorithm(GetAmbiente(), 10, 20, 10);
    }
private:
    ManagerGeneticAlgorithm<int> gerenteAG;

    Environment GetAmbiente(){
        Environment retorno;
        retorno.SetChangeRate(0.1);
        return retorno;
    }
};

#endif // EXECUTAAGCAMINHOGRAFO_H
