#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#include "templateclassid.h"
#include "import/generaterandomgene.h"
#define TEMPLATE template<class TYPE>

TEMPLATE
class Chromosome : public TemplateClassId
{
private:
    vector<TYPE> gene;
    double evaluation;
    bool ative;
public:
    Chromosome():TemplateClassId(){
        ative = false;
    }

    Chromosome(int Id):TemplateClassId(Id){
        ative = true;
    }

    Chromosome(int Id, bool Ativo):TemplateClassId(Id){
        ative = Ativo;
    }

    ~Chromosome();
    vector<TYPE> GetGene();
    TYPE GetGeneAt(int index);
    void SetGeneAt(int index, TYPE value);
    void SetGene(vector<TYPE>);
    void GenerateRandom(GenerateRandomGene * generateGene,int numberOfElements);
    Chromosome<TYPE> GetSubChromosome(int begin, int end);
    int GetNumberOfElements();
    void SetNumberOfElements(int value);
    void Clear();
    void SetEvaluation(double value);
    double GetEvaluation();
    void Swap(int i, int j);
    bool GetAtive();
    bool SetAtive(bool value);
};

#endif // CHROMOSOME_H
