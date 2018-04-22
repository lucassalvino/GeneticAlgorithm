#ifndef CUSTOMGENERATERANDOMCHROMOSOME_H
#define CUSTOMGENERATERANDOMCHROMOSOME_H
#include "../Base/include/generaterandomchromosome.hpp"
#include "cstdlib"
#include "cstdio"

class CustomGenerateRandomChromosome : public GenerateRandomChromosome<int>
{
public:
    Chromosome<int> GenerateChromosome(int numGenes, int ID) override
    {
        Chromosome<int> retorno;
        retorno.SetId(ID);
        retorno.SetStatusChromosome(StatusChromosome::Ativo);
        for (int i = 0; i < numGenes; i++)
        {
            retorno.AddGeneInBack(rand()%this->GetMaxValueGene());
        }
        return retorno;
    }

    int GetMaxValueGene()
    {
        if(maxValueGene <= 0)throw "Valor maximo do gene ainda não foi setado";
        return maxValueGene;
    }

    void SetMaxValuesGene(int value)
    {
        if(value <= 0)
            throw "O Valor maximo para o gene não pode ser menor do que ou igual a zero";
        maxValueGene = value;
    }
private:
    int maxValueGene;
};
#endif // CUSTOMGENERATERANDOMCHROMOSOME_H
