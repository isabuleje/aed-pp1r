#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <optional>
#include <limits>

using uint = unsigned int;
using Vertex = uint;
using Weight = float;
using VertexWeightPair = std::pair<Vertex, Weight>;

class WeightedGraphAM{
//ESPEC-2
private:
    std::vector<std::vector<Weight>> adj;
    uint num_vertices;
    uint num_edges;

public:
    void add_edge(Vertex u, Vertex v, Weight w);
    void remove_edge(Vertex u, Vertex v, Weight w);
    std::list<uint> get_adj(const Vertex u) const;
    std::vector<std::vector<Weight>> get_adj_matrix();
    std::optional<uint> get_weight(const Vertex u, const Vertex v);
    uint get_num_vertices() const;
    uint get_num_edges() const;
    std::vector<std::vector<Weight>> get_adj() const;
    void Print_Adjacency_Matrix(const WeightedGraphAM& g) const;


    WeightedGraphAM(uint num_vertices){

        this->num_vertices = num_vertices;
        this->num_edges = 0;
        adj.resize(num_vertices);
        for (int i = 0; i < num_vertices; i++) {
            adj[i].resize(num_vertices);
            for (int j = 0; j < num_vertices; j++) {
                adj[i][j] = std::numeric_limits<Weight>::infinity();
//o professor sugeriu inicializar a lista com valores infinitos mas tem que ser
//declarado fora do construtor e inicializado dentro entao n da
//e n da pra ser const
            }
        }
    }

    ~WeightedGraphAM(){
        //nada
    }


};

std::list<uint> WeightedGraphAM::get_adj(const Vertex u) const{
    if (u >= num_vertices) {
        throw std::invalid_argument("botou um numero que nao ta na lista");
    }
    std::list<Vertex> adjacentes = std::list<Vertex>();

    uint n = num_vertices + 1; //"Utilize uma repeticao fazendo uma variavel v ir de 0 ate n - 1"
    for (int v = 0; v < n - 1; v++) {
//a lista pede pra verificar se os valores sao nulos mas nenhum valor e nulo se todos sao infinitos
//acho que ele quis dizer verificar se o valor e infinito
        if (adj[u][v] != std::numeric_limits<Weight>::infinity()) {
            adjacentes.push_back(v);
        }
    }
    return adjacentes;
}

std::vector<std::vector<Weight>> WeightedGraphAM::get_adj_matrix() {
    return adj;
}

std::optional<uint> WeightedGraphAM::get_weight(const Vertex u, const Vertex v) {
    if (u >= num_vertices) {
        //por ser unsiged int nao precisa checar se e negativo ja q n da pra ser negtivo
        throw std::invalid_argument("botou um numero que nao ta na lista");
    }
    return adj[u][v];
}

uint WeightedGraphAM::get_num_vertices() const {
    return num_vertices;
}

uint WeightedGraphAM::get_num_edges() const{
    return num_edges;
}

void WeightedGraphAM::add_edge(const Vertex u, const Vertex v, const Weight w){
    if (u >= num_vertices || v >= num_vertices || u == v) {
        throw std::invalid_argument("Um valor eh negativo our um eh maior que numero de vertices our sao imguais");
    }
    adj[u][v] = w;
    adj[v][u] = w;
    num_edges++;
}

/*
void WeightedGraphAM::remove_egde(const Vertex u, const Vertex v){
    if (u < 0 || v < 0 || u >= num_vertices || v >= num_vertices || u == v) {
        throw std::invalid_argument("Um valor eh negativo our um eh maior que numero de vertices our sao imguais");
    }
    adj[u][v] = 0;
    adj[v][u] = 0;
    num_edges--;
}
*/

void WeightedGraphAM::Print_Adjacency_Matrix(const WeightedGraphAM
& g) const{
    std::cout << "num_vertices: " << g.get_num_vertices() << "\n";
    std::cout << "num_edges: " << g.get_num_edges() << "\n";

    uint n = g.get_num_vertices() + 1;
/*
"Na saida, apos uma virgula sempre ha exatamente um espaco em branco."
que espaco em branco??
*/
    for (uint i = 0; i < n - 1; i++) {
        for (uint j = 0; j < n - 1; j++) {
            std::cout << adj[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}


int main(){
    //ordem do grafo
    uint n = 0;

    //numero de arestas que pode adicionar ao grafo aka tamanho
    uint m = 0;

    std::cin >> n >> m;

    WeightedGraphAM
 graph(n);

    uint u, v = 0;
    Weight w = 0;

    m++;

    for(uint i = 0; i < m-1; i++){
        std::cin >> u >> v >> w;
        graph.add_edge(u, v, w);
    }

    graph.Print_Adjacency_Matrix(graph);

    return 0;
}