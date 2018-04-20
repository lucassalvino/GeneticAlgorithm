#include "chromosome.h"

TEMPLATE
Chromosome<T>::Chromosome():BaseClassId(){
    ative = false;
    evaluation = 0;
}

TEMPLATE
Chromosome<T>::Chromosome(int Id):BaseClassId(Id){
    ative = true;
    evaluation = 0;
}

TEMPLATE
Chromosome<T>::Chromosome(int Id, bool Ativo):BaseClassId(Id){
    ative = Ativo;
    evaluation = 0;
}

TEMPLATE
Chromosome<T>::~Chromosome()
{
    Clear();
}

TEMPLATE
std::vector<T> Chromosome<T>::GetGene()
{
    return this->gene;
}

TEMPLATE
T Chromosome<T>::GetGeneAt(int index)
{
    if(index < 0 || index >= (int)this->gene.size())
        throw "[index] is invald value";
    return this->gene[index];
}

TEMPLATE
void Chromosome<T>::SetGeneAt(int index, T value)
{
    if(!(index >=0 && index < GetNumberOfElements()))
        throw "The value of 'index' is invalid for lenght of gene";
    gene[index] = value;
}

TEMPLATE
void Chromosome<T>::SetGene(std::vector<T> value)
{
    if((int)value.size() <= 0) throw "The size of gene must be greater than zero";
    this->gene = value;
    ative = true;
    evaluation = 0;
}

TEMPLATE
void Chromosome<T>::AddGeneInBack(T value)
{
    gene.push_back(value);
}

TEMPLATE
void Chromosome<T>::GenerateRandom(GenerateRandomGene<T> * generateGene,int numberOfElements)
{
    for(int i = 0; i<numberOfElements;i++)
         this->setGeneAt(i,generateGene->getRandomGene());
}

TEMPLATE
Chromosome<T> Chromosome<T>::GetSubChromosome(int begin, int end)
{
    if(begin < 0 || end < 0 || begin > (int)gene.size() || end > (int)gene.size() ||  begin > end)
        throw "Os valores [Init] e [Final] sao invalidos";
    Chromosome<T> ret;
    int _init = begin;
    for(;begin<end;begin++)
        ret.setGeneAt(begin - _init, this->getGeneAt(begin));
    return ret;
}

TEMPLATE
int Chromosome<T>::GetNumberOfElements()
{
    return (int)gene.size();
}

TEMPLATE
void Chromosome<T>::Clear()
{
    ative = false;
    evaluation = 0;
    gene.clear();
}

TEMPLATE
void Chromosome<T>::SetEvaluation(double value)
{
    this->evaluation = value;
}

TEMPLATE
double Chromosome<T>::GetEvaluation()
{
    return this->evaluation;
}

TEMPLATE
void Chromosome<T>::Swap(int i, int j)
{
    T aux = GetGeneAt(i);
    SetGeneAt(i,GetGeneAt(j));
    SetGeneAt(j,aux);
}

TEMPLATE
bool Chromosome<T>::GetAtive()
{
    return this->ative;
}

TEMPLATE
void Chromosome<T>::SetAtive(bool value)
{
    this->ative = value;
}
