#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include "include/baseclassid.hpp"
#include "generaterandomgene.h"
#include "definesmacros.h"
#include "../MineJsonSuport/jsonobject.h"

enum StatusChromosome{
    Ativo = 1,
    Valido = 2,// cromossomo valido
    Invalido = 3,// A funcao de avaliacao o define como invalido
    Morto = 4// o cromossomo será retirado da população
};

TEMPLATE
class Chromosome : public BaseClassId
{
private:
    std::vector<T> gene;
    double evaluation;
    int StatusChromos;
public:
    Chromosome();
    Chromosome(int Id);
    Chromosome(int Id, bool Ativo);
    ~Chromosome();
    std::vector<T> GetGene();
    T GetGeneAt(int index);
    void SetGeneAt(int index, T value);
    void SetGene(std::vector<T> value);
    void AddGeneInBack(T value);
    void GenerateRandom(GenerateRandomGene<T> * generateGene,int numberOfElements);
    Chromosome<T> GetSubChromosome(int begin, int end);
    int GetNumberOfElements();
    void Clear();
    void SetEvaluation(double value);
    double GetEvaluation();
    void Swap(int i, int j);
    int GetStatusChromosome();
    void SetStatusChromosome(StatusChromosome value);
    string ToStringJson(string (*ConvertoToString)(T));
};

#endif // CHROMOSOME_H
