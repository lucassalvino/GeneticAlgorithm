#include "customalgorithm.h"

BaseGraph::CustomAlgorithm::CustomAlgorithm(Graph *pointerGraph)
{
    graph = 0;
    if(pointerGraph == 0)
        throw std::string("He necessario informar um grafo valido");
    graph = pointerGraph;
}

BaseGraph::CustomAlgorithm::CustomAlgorithm()
{
    graph = 0;
}

void BaseGraph::CustomAlgorithm::execute()
{
    throw std::string("ainda nao foi implementado");
}

void BaseGraph::CustomAlgorithm::setInstanceGraph(Graph *pointerGraph)
{
    if(pointerGraph == 0)
        throw std::string("He necessario informar um grafo valido");
    else
        graph = pointerGraph;
}

void BaseGraph::CustomAlgorithm::checkInstanceGraph()
{
    if(graph == 0)
        throw std::string("He necessario informar um grafo valido");
    else
        return;
}

double BaseGraph::CustomAlgorithm::getDistance(int a, int b)
{
    checkInstanceGraph();
    return graph->getEdge(a,b)->getDistance();
}
