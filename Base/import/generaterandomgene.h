#ifndef GENERATERANDOMGENE_H
#define GENERATERANDOMGENE_H
#include <iostream>
#include "../definesmacros.h"

TEMPLATE
class GenerateRandomGene{
public:
    virtual TYPE GetRandomGene(){throw std::string("Not imlements GetRandomGene");}
};
#endif // GENERATERANDOMGENE_H
