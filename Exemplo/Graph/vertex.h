#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
namespace  BaseGraph {
class Vertex
{
public:
    Vertex();
    Vertex(int id);
    ~Vertex();
    void setId(int value);
    int getId();
    int numberAdjacents();
    Vertex* getAdjacentAt(int index);
    std::vector<int> getIDVertexAdjacent();
    void addVertexAdjacent(Vertex* idVertice);
private:
    int ID;
    std::vector<Vertex*> adjacent;
protected:
};
}
#endif // VERTEX_H
