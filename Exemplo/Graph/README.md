# Class Grafo
>Lucas Salvino de Deus

A classe **Graph** tem como principal objetivo criar uma representação de um grafo a fim de faciliar representar problemas que possam ser
abordados com grafo.

Estrutura basica:
* Basicamente possui um vetor de vertices e um vetor de Arestas

Utilização básica:
* Instanciação: Possui apenas o construtor padrão.
```C++
    #include "graph.h"
    using namespace BaseGraph;
    using namespace std;
    int main(){
        Graph grafo;
        return 0;
    }
```
* Inserindo Vertices e Arestas: Os vertices são inseridos automaticamente conforme as arestas sao inseridas.
Cada vertice é identificado pelo seu ID, atributo da classe Vertex, com valor inteiro. inicialmente pensado para ser inicialzado com
zero e sendo incrementado conforme a necessidade,. Nesta abordagem, um grafo teria N vertice, itentificados pelos seus IDs [0,N)

* ***void addEdge***: Metodo utilizado para adicionar nova aresta ao grafo parametros:
    * int origin : devera conter o id do vertice de origem, campo obrigatório
    * int destiny : devera conter o id do vertice de destino, campo obrigatório
    * double distance : devera conter o peso da aresta, campo obrigatório
    * bool bidirectional : caso deseja-se criar uma aresta bidirecional, marcar valor como true, valor default false. Caso seja true cria uma aresta inversa a especiiada com distancia igaul
    * bool updateDistance: caso seja true e já exista uma aresta entre origem e destino, o valor da distancia é atualizado
```C++
    #include "graph.h"
    using namespace BaseGraph;
    using namespace std;
    int main(){
        Graph grafo;
        grafo.addEdge(0,1,6); // cria aresta 0->1 com peso 6
        grafo.addEdge(0,1,-1,false,true); // atualiza o peso da aresta 0->1 de 6 para -1
        grafo.addEdge(1,2,1,true,false); // cria a aresta 1<->2 com peso 1
        return 0;
    }
```


* ***Edge \*getEdge***: retorna um ponteiro para a aresta especificada, null caso a aresta nao exista
```C++
    #include "graph.h"
    using namespace BaseGraph;
    using namespace std;
    int main(){
        Graph grafo;
        grafo.addEdge(0,1,6);
        grafo.getEdge(0,1); // retorna ponteiro para a aresta 0->1
        grafo.getEdge(0,2); // retorna null
        return 0;
    }
```
* ***Vertex \*getVertex***: retorna um ponteiro para o vertice especificado, null caso o vertice nao exista. Caso o segundo paramtro seja assinalado como true
    e o vertice nao existir, sera criado um vertice com o id especificado
    ```C++
        #include "graph.h"
        using namespace BaseGraph;
        using namespace std;
        int main(){
            Graph grafo;
            grafo.getVertex(0); // retorna null
            grafo.getVertex(0,true);// retorna um ponteiro para o vertice 0
            return 0;
        }
    ```
* ***void loadFromFile***: Carrega grafo de arquivo. Recebe como paramentro o uma string com o caminho do arquivo. Lança exceção do tipo string, caso o arquivo não seja encontrado
    * Modelo arquivo: composto por N linhas, cada linha contem dois inteiros representando o ID do vertice de origem e de destino, seguido por um double, correspondente ao valor do peso da aresta (distance)
``` 
    0 1 6
    0 2 3
    1 2 1
    2 1 2
    1 3 3
    2 3 7
    2 4 1
    3 4 5
```
    * Usando no metodo:
```C++
        #include "graph.h"
        using namespace BaseGraph;
        using namespace std;
        int main(){
            Graph grafo;
            try{
                grafo.loadFromFile("grafo.txt"); //carrega o grafo
            }
            catch(std::string erro){
                printf("Erro ao carregar arquivo do grafo: \n\t%c\n",erro.c_stc());
            }
            return 0;
        }
``` 
* ***void saveInFile***: Salva o grafo atual em um arquivo. Recebe como parametro uma stringo  com o caminho do arquivo. Lança exceçãi do tipo string caso o arquivo não possa ser acessado ou criado
    * Modelo do arquivo: composto por N linhas, cada linha contem dois inteiros representando o ID do vertice de origem e de destino, seguido por um double, correspondente ao valor do peso da aresta (distance)
    ```C++
        #include "graph.h"
        using namespace BaseGraph;
        using namespace std;
        int main(){
            Graph grafo;
            try{
                grafo.addEdge(0,1,6);
                grafo.addEdge(0,2,3);
                grafo.addEdge(1,2,1);
                grafo.addEdge(2,1,2);
                grafo.addEdge(1,3,3);
                grafo.addEdge(2,3,7);
                grafo.addEdge(2,4,1);
                grafo.addEdge(3,4,5);
                grafo.saveInFile("grafo.txt"); //salva o grafo
            }
            catch(std::string erro){
                printf("Erro ao carregar arquivo do grafo: \n\t%c\n",erro.c_stc());
            }
            return 0;
        }
    ``` 
    * Arquivo Gerado: 

    ``` 
    0 1 6
    0 2 3
    1 2 1
    2 1 2
    1 3 3
    2 3 7
    2 4 1
    3 4 5
    ```