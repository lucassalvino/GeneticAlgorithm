#ifndef EXECUTAAGCAMINHOGRAFO_H
#define EXECUTAAGCAMINHOGRAFO_H
#include <sstream>
#include "../Base/include/managergeneticalgorithm.hpp"
#include "customgeneraterandomchromosome.h"
#include "Graph/graph.h"
using namespace BaseGraph;
using namespace std;

string ConvertIntToString(int a){
    ostringstream convert;
    convert << a;
    return convert.str();
}

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
    void Executa(bool showLog = false, bool saveLog = false, std::string FolderLog = std::string("")){
        CustomGenerateRandomChromosome* add = new CustomGenerateRandomChromosome();
        carregaGrafo();
        add->SetMaxValuesGene(graph.getNumVertex());
        gerenteAG.SetShowLog(showLog);
        gerenteAG.SetSaveLog(saveLog);
        gerenteAG.SetFolderLog(FolderLog);
        gerenteAG.SetFunctionConvertGeneAtString(ConvertIntToString);
        gerenteAG.GetPopulation()->SetGenerateRandomChormosome(add);
        gerenteAG.GetPopulation()->SetCalculateEvaluation(GetAvaliaCromossomo());
        gerenteAG.SetNumberClusters(1);
        int numeroGeracoes = 5000;
        int numeroIndividuos = 20;
        gerenteAG.RunGeneticAlgorithm(GetAmbiente(), numeroGeracoes, numeroIndividuos, graph.getNumVertex(), new Operators<int>(), UtilidadeConvert<int>::GetNumber);
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
        graph.addEdge(0,3,2);
        graph.addEdge(0,3,2);
        graph.addEdge(0,1,1);
        graph.addEdge(1,3,3);
        graph.addEdge(1,4,9);
        graph.addEdge(2,3,1);
        graph.addEdge(2,5,5);
        graph.addEdge(3,5,4);
        graph.addEdge(3,6,6);
        graph.addEdge(4,3,5);
        graph.addEdge(4,6,3);
        graph.addEdge(4,8,8);
        graph.addEdge(5,7,7);
        graph.addEdge(6,5,8);
        graph.addEdge(6,7,2);
        graph.addEdge(6,8,4);
        graph.addEdge(7,8,3);
    }
    Graph graph;
};

#endif // EXECUTAAGCAMINHOGRAFO_H
