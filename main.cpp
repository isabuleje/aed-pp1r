#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <optional>


using uint = unsigned int;
using Vertex = uint;
using Weight = float;
using VertexWeightPair = std::pair<Vertex, Weight>;

class WeightedGraphAL{
//ESPEC-2
private:
    std::list<VertexWeightPair>* adj;
    uint num_vertices;
    uint num_edges;

public:
    void add_edge(Vertex u, Vertex v, Weight w);
    void remove_edge(Vertex u, Vertex v, Weight w);
    std::list<VertexWeightPair> get_adj(const Vertex u) const;
    std::optional<uint> get_weight(const Vertex u, const Vertex v);
    uint get_num_vertices() const;
    uint get_num_edges() const;
    std::vector<std::vector<Weight>> get_adj() const;
    void Print_Adjacency_List(const WeightedGraphAL& g) const;
    void remove_egde(const Vertex u, const Vertex v, const Weight w);


    WeightedGraphAL(uint num_vertices){

        this->num_vertices = num_vertices;
        this->num_edges = 0;

        adj = new std::list<VertexWeightPair>[num_vertices];
    }

    //ESPEC-C4
    ~WeightedGraphAL(){
        delete[] adj;
        adj = nullptr;
    }


};

//ESPEC-C6
std::list<VertexWeightPair> WeightedGraphAL::get_adj(const Vertex u) const{
    if (u >= num_vertices) {
        throw std::invalid_argument("botou um numero que nao ta na lista");
    }

    return adj[u];
}

//ESPEC-C7
std::optional<uint> WeightedGraphAL::get_weight(const Vertex u, const Vertex v) {
    const std::list<VertexWeightPair>& pares_vw = adj[u];

    for (const auto& p : pares_vw) {
        if (p.first == v) {
            return p.second;
        }
    }

    return std::nullopt;
}

uint WeightedGraphAL::get_num_vertices() const {
    return num_vertices;
}

uint WeightedGraphAL::get_num_edges() const{
    return num_edges;
}

//ESPEC-C5
void WeightedGraphAL::add_edge(const Vertex u, const Vertex v, const Weight w){
    if (u >= num_vertices || v >= num_vertices || u == v || u < 0 || v < 0) {
        throw std::invalid_argument("Um valor eh negativo our um eh maior que numero de vertices our sao imguais");
    }
    adj[u].push_back(VertexWeightPair(v, w));
    adj[v].push_back(VertexWeightPair(u, w));
    num_edges++;
}


void WeightedGraphAL::remove_egde(const Vertex u, const Vertex v, const Weight w){
    if (u < 0 || v < 0 || u >= num_vertices || v >= num_vertices || u == v) {
        throw std::invalid_argument("Um valor eh negativo our um eh maior que numero de vertices our sao imguais");
    }

    for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        if (i->first == v && i->second == w) { adj[u].erase(i); break; }

    for (auto j = adj[v].begin(); j != adj[v].end(); j++)
        if (j->first == u && j->second == w) { adj[v].erase(j); break; }
    num_edges--;
}


void WeightedGraphAL::Print_Adjacency_List(const WeightedGraphAL& g) const{
    std::cout << "num_vertices: " << g.get_num_vertices() << "\n";
    std::cout << "num_edges: " << g.get_num_edges() << "\n";

    uint n = g.get_num_vertices() + 1;

    for (uint u = 0; u < n - 1; u++) {
        std::list<VertexWeightPair> l = get_adj(u);
        std::cout << u << ": ";
        while (l.size() != 0) {
            std::cout << "(" << l.front().first << ", " << l.front().second << "), ";
            l.pop_front();            
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


int main(){
    //ordem do grafo
    uint n = 0;

    //numero de arestas que pode adicionar ao grafo aka tamanho
    uint m = 0;

    std::cin >> n >> m;

    WeightedGraphAL graph(n);

    uint u, v = 0;
    Weight w = 0;

    m++;

    for(uint i = 0; i < m-1; i++){
        std::cin >> u >> v >> w;
        graph.add_edge(u, v, w);
    }

    graph.Print_Adjacency_List(graph);

    return 0;
}