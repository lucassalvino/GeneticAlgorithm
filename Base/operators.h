#ifndef OPERATORS_H
#define OPERATORS_H
#include "definesmacros.h"
#include "chromosome.h"
#include <cstdio>
#include <cstdlib>
TEMPLATE
class Operators
{
public:
    static Chromosome<T> CrossOverOnePoint(Chromosome<T> mother,Chromosome<T> father)
    {
        return CrossOverOnePoint(mother,father,rand() % mother.GetNumberOfElements());
    }
    static Chromosome<T> CrossOverOnePoint(Chromosome<T> mother,Chromosome<T> father, int divisionPoint)
    {
        if(mother.GetNumberOfElements() != father.GetNumberOfElements())
            throw "[ERROR] The number of genes of the mother is different of the number of genes of the father";
        if(divisionPoint < 0 || divisionPoint > mother.GetNumberOfElements())
            throw "[ERROR] The division point is invalid for lenght of genes the parents";
        Chromosome<T> ret;
        int i = 0;
        for (;i<divisionPoint;i++){
            ret.SetGeneAt(i,mother.GetGeneAt(i));
        }
        for (;i<father.GetNumberOfElements();i++){
            ret.SetGeneAt(i,father.GetGeneAt(i));
        }
        return ret;
    }
    static Chromosome<T> CrossOverTwoPoint(Chromosome<T> mother,Chromosome<T> father)
    {
        int first, second;
        GenerateTwoDivisionPoints(first,second,mother.GetNumberOfElements());
        return CrossOverTwoPoint(mother,father,first,second);
    }
    static Chromosome<T> CrossOverTwoPoint(Chromosome<T> mother,Chromosome<T> father, int firstDivisionPoint, int secondDivisionPoint)
    {
        if(mother.GetNumberOfElements() != father.GetNumberOfElements())
            throw "[ERROR] The number of genes of the mother is different of the number of genes of the father";
        if(firstDivisionPoint < 0 || firstDivisionPoint > mother.GetNumberOfElements() || secondDivisionPoint < 0 || secondDivisionPoint > mother.getNumberOfElements())
            throw "[ERROR] The division point is invalid for lenght of genes the parents";
        if(firstDivisionPoint > secondDivisionPoint)
            throw "[ERROR] The First division point is not less that of division point second";
        int i=0;
        Chromosome<T> ret;
        for(;i<firstDivisionPoint;i++){
            ret.SetGeneAt(i,mother.GetGeneAt(i));
        }
        for(;i<secondDivisionPoint;i++){
            ret.SetGeneAt(i,father.GetGeneAt(i));
        }
        for(;i<mother.GetNumberOfElements();i++){
            ret.SetGeneAt(i,mother.GetGeneAt(i));
        }
        return ret;
    }
    static Chromosome<T> Mutation(Chromosome<T> chromos, int SwapNumber = 1)
    {
        for(int i=0;i<SwapNumber;i++){
            chromos.Swap(rand()%n,rand()%n);
        }
        return chromos;
    }
private:
    static void GenerateTwoDivisionPoints(int& firstDivisionPoint, int& secondDivisionPoint,int maxPoint)
    {
        firstDivisionPoint = rand()%maxPoint;
        secondDivisionPoint = firstDivisionPoint + (rand()%(maxPoint - firstDivisionPoint));
    }
};
#endif // OPERATORS_H
