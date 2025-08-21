#include <iostream>
#include <list>

//ESPEC-1
typedef unsigned int Vertex;
typedef unsigned int uint;

class GraphAL{
private:
    //ESPEC-2 ( Tem que ser ponteiro )
    //mano, tem um problema q tipo
    //o prof quer especificamente q seja adj[]
    //so que usar o [] é foda pq é ultrapassado e dá erro
    //ai eu n sei se a gnt deixa com ou sem []

    std::list<Vertex>* adj;
    uint num_vertices;
    uint num_edges;

public:
    void add_egde(Vertex u, Vertex v);
    void remove_egde(Vertex u, Vertex v);
    std::list<Vertex>& get_adj(Vertex u);
    void Print_Adjancency_List(GraphAL g);

    //ESPEC-3
    GraphAL(uint num_vertices){
        this->num_vertices = num_vertices;
        this->num_edges = 0;

        adj = new std::list<Vertex>[num_vertices];
    }

    //ESPEC-4
    ~GraphAL(){
        delete [] adj;
        adj = nullptr;
    }


};

std::list<Vertex>& GraphAL::get_adj(Vertex u){
    return adj[u];
}

//ESPEC-5
//depois adicionar tratamento de exceção
void GraphAL::add_egde(const Vertex u, const Vertex v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    num_edges++;
}

void GraphAL::remove_egde(const Vertex u, const Vertex v){
    adj[u].remove(v);
    adj[v].remove(u);
    num_edges++;
}

//ESPEC-7
void GraphAL::Print_Adjancency_List(GraphAL g){

}


//ESPEC-8
//Depois colocar tratamento de exceção para quanfo for número negativo e mesma entrada 2 vezes
int main(){
    //ordem do grafo
    uint n = 0;

    //número de arestas que pode adicionar ao grafo aka tamanho
    uint m = 0;

    std::cin >> n >> m;

    GraphAL graph(n);

    uint u, v = 0;

    for(uint i = 0; i < n-1; i++){
        std::cin >> u >> v;
        graph.add_egde(u, v);
    }

    graph.Print_Adjancency_List(graph);

    return 0;
}