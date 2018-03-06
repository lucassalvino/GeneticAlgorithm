#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include "templateclassid.h"
#include "import/generaterandomgene.h"
#include "definesmacros.h"

TEMPLATE
class Chromosome : public TemplateClassId
{
private:
    std::vector<TYPE> gene;
    double evaluation;
    bool ative;
public:
    Chromosome():TemplateClassId(){
        ative = false;
        evaluation = 0;
    }

    Chromosome(int Id):TemplateClassId(Id){
        ative = true;
        evaluation = 0;
    }

    Chromosome(int Id, bool Ativo):TemplateClassId(Id){
        ative = Ativo;
        evaluation = 0;
    }

    ~Chromosome()
    {
        Clear();
    }
    vector<TYPE> GetGene();
    TYPE GetGeneAt(int index);
    void SetGeneAt(int index, TYPE value);
    void SetGene(vector<TYPE>);
    void GenerateRandom(GenerateRandomGene<TYPE> * generateGene,int numberOfElements);
    Chromosome<TYPE> GetSubChromosome(int begin, int end);
    int GetNumberOfElements();
    void Clear();
    void SetEvaluation(double value);
    double GetEvaluation();
    void Swap(int i, int j);
    bool GetAtive();
    void SetAtive(bool value);
};

#endif // CHROMOSOME_H
