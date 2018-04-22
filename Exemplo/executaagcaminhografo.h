#ifndef EXECUTAAGCAMINHOGRAFO_H
#define EXECUTAAGCAMINHOGRAFO_H
#include "../Base/include/managergeneticalgorithm.hpp"
#include "customgeneraterandomchromosome.h"
#include "Graph/graph.h"
using namespace BaseGraph;

class AvaliaCromossomo : public CalculateEvaluation<int>{
public:
    double GetEvaluation(Chromosome<int>* value) override
    {
        if(graph == 0)
            throw "Instância do grafo não definida para calculo de fitnes";
        if(value == 0)
            throw "Instância de cromossomo não definida para cálculo de fitness";
        double retorno = 0;
        for(int i = 0; i < (value->GetNumberOfElements() - 1); i++)
        {
            int verticeOrigem = value->GetGeneAt(i);
            int verticeDestino = value->GetGeneAt(i+1);
            Edge* arestaAtual = graph->getEdge(verticeOrigem, verticeDestino);
            if(arestaAtual == 0){
                // aresta não existe cromossomo inválido
                value->SetStatusChromosome(StatusChromosome::Invalido);
            }else{
                retorno += arestaAtual->getDistance();
            }
        }

        return retorno;
    }

    void SetGraph(Graph* value){
        graph = value;
    }

    Graph* GetGraph(){
        return graph;
    }

private:
    Graph* graph;
};


class ExecutaAGCaminhoGrafo{
public:
    void Executa(){
        CustomGenerateRandomChromosome* add = new CustomGenerateRandomChromosome();
        carregaGrafo();
        add->SetMaxValuesGene(graph.getNumVertex());
        gerenteAG.GetPopulation()->SetGenerateRandomChormosome(add);
        gerenteAG.GetPopulation()->SetCalculateEvaluation(GetAvaliaCromossomo());
        gerenteAG.RunGeneticAlgorithm(GetAmbiente(), 10, 20, graph.getNumVertex());
    }

private:
    ManagerGeneticAlgorithm<int> gerenteAG;

    Environment GetAmbiente(){
        Environment retorno;
        retorno.SetChangeRate(0.1);
        return retorno;
    }
    AvaliaCromossomo* GetAvaliaCromossomo(){
        AvaliaCromossomo* retorno = new AvaliaCromossomo();
        retorno->SetGraph(&graph);
        return retorno;
    }
    void carregaGrafo(){
        graph.addEdge(0,1,1);
        graph.addEdge(0,2,3);
        graph.addEdge(0,3,2);
        graph.addEdge(1,4,9);
        graph.addEdge(2,5,5);
        graph.addEdge(3,6,6);
        graph.addEdge(6,8,10);
        graph.addEdge(4,5,2);
        graph.addEdge(4,8,7);
        graph.addEdge(5,7,3);
        graph.addEdge(7,8,2.5);
    }
    Graph graph;
};

#endif // EXECUTAAGCAMINHOGRAFO_H
