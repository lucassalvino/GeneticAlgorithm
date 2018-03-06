#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include "templateclassid.h"
#include "generaterandomgene.h"
#include "definesmacros.h"

TEMPLATE
class Chromosome : public TemplateClassId
{
private:
    std::vector<T> gene;
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

    std::vector<T> GetGene()
    {
        return this->gene;
    }

    T GetGeneAt(int index)
    {
        if(index < 0 || index >= (int)this->gene.size())
            throw "[index] is invald value";
        return this->gene[index];
    }
    void SetGeneAt(int index, T value)
    {
        if(!(index >=0 && index < GetNumberOfElements()))
            throw "The value of 'index' is invalid for lenght of gene";
        gene[index] = value;
    }
    void SetGene(std::vector<T> value)
    {
        if((int)value.size() <= 0) throw "The size of gene must be greater than zero";
        this->gene = value;
    }
    void GenerateRandom(GenerateRandomGene<T> * generateGene,int numberOfElements)
    {
        for(int i = 0; i<numberOfElements;i++)
             this->setGeneAt(i,generateGene->getRandomGene());
    }

    Chromosome<T> GetSubChromosome(int begin, int end)
    {
        if(begin < 0 || end < 0 || begin > (int)gene.size() || end > (int)gene.size() ||  begin > end)
            throw "Os valores [Init] e [Final] sao invalidos";
        Chromosome<T> ret;
        int _init = begin;
        for(;begin<end;begin++)
            ret.setGeneAt(begin - _init, this->getGeneAt(begin));
        return ret;
    }
    int GetNumberOfElements()
    {
        return (int)gene.size();
    }
    void Clear()
    {
        ative = false;
        evaluation = 0;
        gene.clear();
    }
    void SetEvaluation(double value)
    {
        this->evaluation = value;
    }
    double GetEvaluation()
    {
        return this->evaluation;
    }
    void Swap(int i, int j)
    {
        T aux = GetGeneAt(i);
        SetGeneAt(i,GetGeneAt(j));
        SetGeneAt(j,aux);
    }
    bool GetAtive()
    {
        return this->ative;
    }
    void SetAtive(bool value)
    {
        this->ative = value;
    }
};

#endif // CHROMOSOME_H
