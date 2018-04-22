#include "graph.h"
BaseGraph::Graph::Graph()
{
    clear();
}

void BaseGraph::Graph::addEdge(Vertex* origin, Vertex* destiny, double distance, bool updateDistance)
{
    Edge add;
    add.setOrigin(origin);
    add.setDestiny(destiny);
    add.setDistance(distance);
    addEdge(add, updateDistance);
}

void BaseGraph::Graph::addVertex(int id)
{
    for(int i = 0; i < (int)vertex.size(); i++){
        if(vertex[i]->getId() == id)return;
    }
    vertex.push_back(new Vertex(id));
}

BaseGraph::Vertex *BaseGraph::Graph::getVertex(int id, bool add)
{
    for(int i = 0; i<(int)vertex.size(); i++){
        if(id == vertex[i]->getId()){/*vertex ja existe*/
            return vertex[i];
        }
    }
    if(add){
        Vertex* add = new Vertex(id);
        vertex.push_back(add);
        return add;
    }else{
        return 0;
    }
}

void BaseGraph::Graph::addEdge(int origin, int destiny, double distance, bool bidirectional, bool updateDistance)
{
    addEdge(getVertex(origin, true), getVertex(destiny, true), distance,updateDistance);
    if(bidirectional)
        addEdge(getVertex(destiny, true), getVertex(origin, true), distance,updateDistance);
}

void BaseGraph::Graph::addEdge(Edge value, bool updateDistance){
    Edge* val = getEdge(value.getOrigin()->getId(), value.getDestiny()->getId());
    if (!val){//insert
        addVertex(value.getOrigin()->getId());
        addVertex(value.getDestiny()->getId());
        edges.push_back(value);
    }
    if (val && updateDistance) val->setDistance(value.getDistance());//update distance
}

void BaseGraph::Graph::clear(){
    for(int i = 0; i < (int)vertex.size(); i++){
        delete [] vertex[i];
    }
    vertex.clear();
    edges.clear();
}

void BaseGraph::Graph::loadFromFile(std::string source){
    FILE* arq = fopen(source.c_str(), "r");
    if(arq == 0) throw std::string("Source ["+source+"] not found");
    int origin, destiny;
    double distance;
    while(fscanf(arq, "%d %d %lf",&origin,&destiny,&distance)!=-1){
        this->addEdge(origin,destiny,distance);
    }
    fclose(arq);
}

void BaseGraph::Graph::saveInFile(std::string source){
    FILE* arq = fopen(source.c_str(), "w");
    if(arq == 0) throw std::string("Source ["+source+"] not found");
    std::vector<Edge>::iterator it = edges.begin();
    for(;it != edges.end(); it++){
        int origin, destiny;
        double distance;
        origin = it->getOrigin()->getId();
        destiny = it->getDestiny()->getId();
        distance = it->getDistance();
        fprintf(arq, "%d %d %lf\n",origin,destiny,distance);
    }
    fclose(arq);
}

BaseGraph::Edge* BaseGraph::Graph::getEdge(int origin, int destiny)
{
    std::vector<Edge>::iterator it = edges.begin();
    for(;it != edges.end(); it++){
        if(origin == it->getOrigin()->getId() && destiny == it->getDestiny()->getId()){
            return &(*it);
        }
    }
    return 0;
}

BaseGraph::Edge* BaseGraph::Graph::getEdge(Vertex origin, Vertex destiny)
{
    return getEdge(origin.getId(), destiny.getId());
}

BaseGraph::Edge *BaseGraph::Graph::getEdge(int index)
{
    std::vector<BaseGraph::Edge>::iterator it = edges.begin();
    for(int i = 0;it != edges.end();i++, it++){
        if(i == index)
            return &(*it);
    }
    return 0;
}

BaseGraph::Vertex *BaseGraph::Graph::getVertexIndex(int index)
{
    std::vector<BaseGraph::Vertex*>::iterator it = vertex.begin();
    for(int i = 0;it != vertex.end(); it++, i++){
        if(i == index) return (*it);
    }
    return 0;
}

int BaseGraph::Graph::getNumEdge()
{
    return edges.size();
}

int BaseGraph::Graph::getNumVertex()
{
    return vertex.size();
}

double **BaseGraph::Graph::getMatrix()
{
    std::vector<Edge>::iterator it = edges.begin();
    double ** ret = new double*[vertex.size()];
    for(int i = 0;i < (int)vertex.size();i++) ret[i] = new double[vertex.size()];
    for(int i = 0;i<(int)vertex.size();i++)
        for(int j = 0; j<(int)vertex.size();j++)
            ret[i][j] = std::numeric_limits<double>::max();
    for(; it != edges.end(); it++){
        ret[it->getOrigin()->getId()][it->getDestiny()->getId()] = it->getDistance();
    }
    return ret;
}
