#include <iostream>
#include <vector>
#include <list>

//ESPEC-1
using uint = unsigned int;
using Vertex = uint;
using Weight = uint;


class GraphAM{
//ESPEC-2
private:
    std::vector<std::vector<Weight>> adj;
    uint num_vertices;
    uint num_edges;

public:
    void add_egde(Vertex u, Vertex v);
    void remove_egde(Vertex u, Vertex v);
    std::list<Weight> get_adj(const Vertex u) const;
    void Print_Adjacency_Matrix(const GraphAM& g ) const;
    uint get_num_vertices() const;
    uint get_num_edges() const;
    std::vector<std::vector<Weight>> get_adj_matrix() const;


    //ESPEC-3
    GraphAM(uint num_vertices){

        this->num_vertices = num_vertices;
        this->num_edges = 0;

        adj = std::vector<std::vector<Weight>>(num_vertices);

        //acho que isso q faz a inicializacao de todos os elementos com 0 do jeito q ele pediur
        for (auto& linha : adj) {
            linha = std::vector<Weight>(num_vertices, 0);
        }
    }

    //ESPEC-4
    ~GraphAM(){
        //prof pediu pra adicionar um comentario falando q a destruicao e automaticar
    }


};

//ESPEC-6
std::list<Weight> GraphAM::get_adj(const Vertex u) const{
    if (u < 0 || u >= num_vertices) {
        throw std::invalid_argument("botou um numero que nao ta na lista");
    }

    std::list<Weight> lista;

    //aq na real ele pediu pra ser o U pra ser usado no loop
    for (int v = 0; v < get_num_vertices() - 1 ; v++) {
        if (adj[u][v] != 0) {
            lista.push_back(v);
        }
    }

    return lista;
}

uint GraphAM::get_num_vertices() const {
    return num_vertices;
}

uint GraphAM::get_num_edges() const{
    return num_edges;
}

//ESPEC-7
std::vector<std::vector<Weight>> GraphAM::get_adj_matrix() const {
    return adj;
}

//ESPEC-5
void GraphAM::add_egde(const Vertex u, const Vertex v){
    if (u < 0 || v < 0 || u >= num_vertices || v >= num_vertices || u == v) {
        throw std::invalid_argument("Um valor eh negativo our um eh maior que numero de vertices our sao imguais");
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
    num_edges++;
}

//conserta ae
void GraphAM::remove_egde(const Vertex u, const Vertex v){
    if (u < 0 || v < 0 || u >= num_vertices || v >= num_vertices || u == v) {
        throw std::invalid_argument("Um valor eh negativo our um eh maior que numero de vertices our sao imguais");
    }
    adj[u].remove(v);
    adj[v].remove(u);
    num_edges--;
}

//ESPEC-8
void GraphAM::Print_Adjacency_Matrix(const GraphAM& g) const{
    std::cout << "num_vertices: " << g.get_num_vertices() << "\n";
    std::cout << "num_edges: " << g.get_num_edges() << "\n";

    uint n = g.get_num_vertices();

    for (uint i = 0; i < n; i++) {
        for (uint j = 0; j < n; j++) {
            std::cout << adj[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


//ESPEC-9
int main(){
    //ordem do grafo
    uint n = 0;

    //numero de arestas que pode adicionar ao grafo aka tamanho
    uint m = 0;

    std::cin >> n >> m;

    GraphAM graph(n);

    uint u, v = 0;

    n = m + 1;

    for(uint i = 0; i < n-1; i++){
        std::cin >> u >> v;
        graph.add_egde(u, v);
    }

    graph.Print_Adjacency_Matrix(graph);

    return 0;
}