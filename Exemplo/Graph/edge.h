#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <utility>
#include "vertex.h"
#include <vector>
namespace  BaseGraph {
class Edge
{
public:
    Edge();
    void setOrigin(Vertex* value);
    void setDestiny(Vertex* value);
    void setDistance(double value);
    Vertex* getOrigin();
    Vertex* getDestiny();
    double getDistance();
    std::pair<int,int> getOriginDestiny();
protected:
    Vertex* origin;
    Vertex* destiny;
    double distance;
};
}
#endif // EDGE_H
