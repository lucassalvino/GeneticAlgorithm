#include "chromosome.h"

TEMPLATE
std::vector<TYPE> Chromosome<TYPE>::GetGene()
{
    return this->gene;
}

TEMPLATE
TYPE Chromosome<TYPE>::GetGeneAt(int index)
{
    if(index < 0 || index >= (int)this->gene.size())
        throw "[index] is invald value";
    return this->gene[index];
}

TEMPLATE
void Chromosome<TYPE>::SetGene(vector<TYPE> value){
    if((int)value.size() <= 0) throw "The size of gene must be greater than zero";
    this->gene = value;
}

TEMPLATE
void Chromosome<TYPE>::GenerateRandom(GenerateRandomGene<TYPE> * generateGene,int numberOfElements){
    for(int i = 0; i<numberOfElements;i++)
        this->setGeneAt(i,generateGene->getRandomGene());
}

TEMPLATE
Chromosome<TYPE> Chromosome<TYPE>::GetSubChromosome(int begin, int end){
    if(begin < 0 || end < 0 || begin > (int)gene.size() || end > (int)gene.size() ||  begin > end)
        throw string("Os valores [Init] e [Final] sao invalidos");
    Chromosome<TYPE> ret;
    int _init = begin;
    for(;begin<end;begin++)
        ret.setGeneAt(begin - _init, this->getGeneAt(begin));
    return ret;
}

TEMPLATE
int Chromosome<TYPE>::GetNumberOfElements(){
    return (int)gene.size();
}

TEMPLATE
void Chromosome<TYPE>::Clear(){
    ative = false;
    evaluation = 0;
    gene.clear();
}

TEMPLATE
void Chromosome<TYPE>::SetEvaluation(double value){
    this->evaluation = value;
}

TEMPLATE
double Chromosome<TYPE>::GetEvaluation(){
    return this->evaluation;
}

TEMPLATE
void Chromosome<TYPE>::Swap(int i, int j){
    TYPE aux = GetGeneAt(i);
    SetGeneAt(i,GetGeneAt(j));
    SetGeneAt(j,aux);
}

TEMPLATE
bool Chromosome<TYPE>::GetAtive(){
    return this->ative;
}

TEMPLATE
void Chromosome<TYPE>::SetAtive(bool value){
    this->ative = value;
}
