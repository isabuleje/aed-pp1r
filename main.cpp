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
    std::list<Vertex>& get_adj(const Vertex u);
    void Print_Adjancency_List(const GraphAL g );
    uint get_num_vertices() const;
    uint get_num_edges() const;


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

std::list<Vertex>& GraphAL::get_adj(const Vertex u){
    return adj[u];
}

uint GraphAL::get_num_vertices() const {
    return num_vertices;
}

uint GraphAL::get_num_edges() const{
    return num_edges;
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
    num_edges--;
}

//ESPEC-7
void GraphAL::Print_Adjancency_List(const GraphAL g) {
    std::cout << "num_vertices: " << get_num_vertices() << "\n";
    std::cout << "num_edges: " << get_num_edges() << "\n";

    //mano, outro ngc é q ele pede que seja num_vertices - 1
    //so q quando coloca -1 ele n imprime todos
    for (uint u = 0; u < get_num_vertices() ; u++) {
        std::cout << u << ": ";

        const std::list<Vertex>& l = get_adj(u);

        for (auto v: l) {
            std::cout << v << ", ";
        }
        std::cout << "\n";
    }
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

    //OUTRO ngc é q ele pede q seja n-1
    //sendo que so roda corretamente quando é m
    for(uint i = 0; i < m; i++){
        std::cin >> u >> v;
        graph.add_egde(u, v);
    }

    graph.Print_Adjancency_List(graph);

    return 0;
}