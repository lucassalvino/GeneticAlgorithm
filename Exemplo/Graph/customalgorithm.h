#ifndef CUSTOMALGORITHM_H
#define CUSTOMALGORITHM_H
#include "graph.h"
namespace  BaseGraph {
class CustomAlgorithm
{
public:
    CustomAlgorithm(Graph *pointerGraph);
    CustomAlgorithm();
    virtual void execute();
    void setInstanceGraph(Graph *pointerGraph);
protected:
    Graph* graph;
private:
    void checkInstanceGraph();
    double getDistance(int a, int b);
};
}
#endif // CUSTOMALGORITHM_H
