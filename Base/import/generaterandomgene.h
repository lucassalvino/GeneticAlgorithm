#ifndef GENERATERANDOMGENE_H
#define GENERATERANDOMGENE_H
#include <iostream>
template <class TYPE>
class GenerateRandomGene{
public:
    virtual TYPE GetRandomGene(){throw std::string("Not imlements GetRandomGene");}
private:
};
#endif // GENERATERANDOMGENE_H
