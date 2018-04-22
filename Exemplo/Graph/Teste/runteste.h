#ifndef RUNTESTE_H
#define RUNTESTE_H
#include "../graph.h"
#include <stdio.h>
using namespace std;
using namespace BaseGraph;
class RunTeste
{
public:
    void executaTestesGrafo();
private:
    void carregaGrafo();
    Graph grafo;
    void printfResultadoTeste(string campo,bool aprovado = true);
    bool testaAdjacentes(int vertice, vector<int> adjacentes);
};

#endif // RUNTESTE_H
