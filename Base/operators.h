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
    static Chromosome<T> CrossOverOnePoint(Chromosome<T> mother,Chromosome<T> father);
    static Chromosome<T> CrossOverOnePoint(Chromosome<T> mother,Chromosome<T> father, int divisionPoint);
    static Chromosome<T> CrossOverTwoPoint(Chromosome<T> mother,Chromosome<T> father);
    static Chromosome<T> CrossOverTwoPoint(Chromosome<T> mother,Chromosome<T> father, int firstDivisionPoint, int secondDivisionPoint);
    static Chromosome<T> Mutation(Chromosome<T> chromos, int SwapNumber = 1);
private:
    static void GenerateTwoDivisionPoints(int& firstDivisionPoint, int& secondDivisionPoint,int maxPoint);
};
#endif // OPERATORS_H
