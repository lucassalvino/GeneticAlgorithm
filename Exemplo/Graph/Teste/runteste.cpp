#include "runteste.h"
void RunTeste::executaTestesGrafo()
{
    printf("\n\nINICIANDO TESTES\n\n");
    carregaGrafo();
    printf("Grafo carregado, verificando dados\n\n");
    printfResultadoTeste(string("NumeroVerticesGrafo"),grafo.getNumVertex() == 5);
    printfResultadoTeste(string("NumeroArestasGrafo"), grafo.getNumEdge() == 8);
    printfResultadoTeste(string("NumeroVerticesAdjacentesa[0]"), grafo.getVertex(0)->numberAdjacents() == 2);
    printfResultadoTeste(string("NumeroVerticesAdjacentesa[2]"), grafo.getVertex(2)->numberAdjacents() == 3);
    printfResultadoTeste(string("NumeroVerticesAdjacentesa[3]"), grafo.getVertex(3)->numberAdjacents() == 1);
    grafo.addEdge(0,1,-1,false,true);
    printfResultadoTeste(string("updateDistanceAresta[true]"), grafo.getEdge(0,1)->getDistance() == -1);
    grafo.addEdge(0,1,6);
    printfResultadoTeste(string("updateDistanceAresta[false]"), grafo.getEdge(0,1)->getDistance() == -1);
    vector<int> adjacente0{1,2};
    vector<int> adjacente2{1,3,4};
    printfResultadoTeste(string("TesteAdjacentesAoVertice0"), testaAdjacentes(0,adjacente0));
    printfResultadoTeste(string("TesteAdjacentesAoVertice2"), testaAdjacentes(2,adjacente2));
    printf("\n\nFINALIZANDO TESTES\n\n");
}

void RunTeste::carregaGrafo()
{
    grafo.addEdge(0,1,6);
    grafo.addEdge(0,2,3);
    grafo.addEdge(1,2,1);
    grafo.addEdge(2,1,2);
    grafo.addEdge(1,3,3);
    grafo.addEdge(2,3,7);
    grafo.addEdge(2,4,1);
    grafo.addEdge(3,4,5);
}

void RunTeste::printfResultadoTeste(string campo, bool aprovado)
{
    if(aprovado){
        printf("[INFO] A propriedade [%s] foi testada sem problemas.\n", campo.c_str());
    }else{
        printf("\n\t[ERRO] A propriedade [%s] foi testada com problemas.\n\n", campo.c_str());
    }
}

bool RunTeste::testaAdjacentes(int vertice, vector<int> adjacentes )
{
    vector<int> adjacentVertice = grafo.getVertex(vertice)->getIDVertexAdjacent();
    for(int i = 0; i < (int) adjacentes.size(); i++){
        bool achei = false;
        for(int j = 0; j < (int) adjacentVertice.size(); j++){
            if(adjacentes[i] == adjacentVertice[j]){
                achei = true;
                break;
            }
        }
        if (achei == false)
            return false;
    }
    return true;
}
