#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include "include/baseclassid.hpp"
#include "generaterandomgene.h"
#include "definesmacros.h"

TEMPLATE
class Chromosome : public BaseClassId
{
private:
    std::vector<T> gene;
    double evaluation;
    bool ative;
public:
    Chromosome();
    Chromosome(int Id);
    Chromosome(int Id, bool Ativo);
    ~Chromosome();
    std::vector<T> GetGene();
    T GetGeneAt(int index);
    void SetGeneAt(int index, T value);
    void SetGene(std::vector<T> value);
    void GenerateRandom(GenerateRandomGene<T> * generateGene,int numberOfElements);
    Chromosome<T> GetSubChromosome(int begin, int end);
    int GetNumberOfElements();
    void Clear();
    void SetEvaluation(double value);
    double GetEvaluation();
    void Swap(int i, int j);
    bool GetAtive();
    void SetAtive(bool value);
};

#endif // CHROMOSOME_H
