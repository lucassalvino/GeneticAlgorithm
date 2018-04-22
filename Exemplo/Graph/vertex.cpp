#include "vertex.h"

BaseGraph::Vertex::Vertex()
{
    ID = -1;
}

BaseGraph::Vertex::Vertex(int id)
{
    setId(id);
}

BaseGraph::Vertex::~Vertex()
{
    adjacent.clear();
}

void BaseGraph::Vertex::setId(int value)
{
    if(value < 0)throw std::string("O valor ID de um Vertice nao pode ser negativo");
    ID = value;
}

int BaseGraph::Vertex::getId()
{
    return ID;
}


int BaseGraph::Vertex::numberAdjacents()
{
    return adjacent.size();
}

BaseGraph::Vertex *BaseGraph::Vertex::getAdjacentAt(int index)
{
    if(index < 0 || index >= numberAdjacents())
        throw std::string("index he invalido para getAdjacentAt");
    return adjacent[index];
}

std::vector<int> BaseGraph::Vertex::getIDVertexAdjacent()
{
    std::vector<int> ret; ret.resize((int)adjacent.size());
    for(int i = 0; i < (int)adjacent.size(); i++)
        ret[i] = adjacent[i]->getId();
    return ret;
}

void BaseGraph::Vertex::addVertexAdjacent(Vertex *idVertice)
{
    for(int i = 0; i<numberAdjacents(); i++){
        if(idVertice->getId() == adjacent[i]->getId())return;
    }
    adjacent.push_back(idVertice);
}
