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
    //so que usar o [] e foda pq e ultrapassado e da erro
    //ai eu n sei se a gnt deixa com ou sem []

/*   /|\
      |
acho que isso pode ser pq o uml la da classe GraphAl tava escrito
adj[]: std::list<Vertex> nao pq tem que declarar como adj[] mas pq mais pra frente vai usar esse ponteiro pra
armazenar uma lista e essa lista vai ter o []
acho que deve ser isso*/

    std::list<Vertex>* adj;
    uint num_vertices;
    uint num_edges;

public:
    void add_egde(Vertex u, Vertex v);
    void remove_egde(Vertex u, Vertex v);
    std::list<Vertex>& get_adj(const Vertex u) const;
    void Print_Adjancency_List(const GraphAL& g ) const;
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

std::list<Vertex>& GraphAL::get_adj(const Vertex u) const{
    if (u < 0 || u >= num_vertices) {
        throw std::invalid_argument("botou um numero que nao ta na lista");
    }
    return adj[u];
}

uint GraphAL::get_num_vertices() const {
    return num_vertices;
}

uint GraphAL::get_num_edges() const{
    return num_edges;
}

//ESPEC-5
/*olhando o exercicio e as especificacoes na verdade em nenhum ponto ta escrito que precisa
tratar as excecoes, so tava especificado que precisa lancar uma excecao quando for invalido
entao nada de try catch apenas throw
tem ate uma observacao na especificacao 8 que fala sobre pensar no que teria que ser feito pra
fazer o codigo poderia ter pra lidar melhor com esses erros e tal mas era sobre pensar como
seria se fizesse e nao tava pedindo pra fazer*/
void GraphAL::add_egde(const Vertex u, const Vertex v){
    if (u < 0 || v < 0 || u >= num_vertices || v >= num_vertices || u == v) {
        throw std::invalid_argument("mano tem algum valor ai que nao faz sentido");
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
    num_edges++;
}


/*nao sei pq esse aqui existe
nao tava pedindo em nenhuma parte pra ter um remove_edge e o metodo acaba nunca sendo usado no
fim das contas
vou deixar mesmo assim pra parecer mais q a gente ta caprichando*/
void GraphAL::remove_egde(const Vertex u, const Vertex v){
    if (u < 0 || v < 0 || u >= num_vertices || v >= num_vertices || u == v) {
        throw std::invalid_argument("mano tem algum valor ai que nao faz sentido");
    }
    adj[u].remove(v);
    adj[v].remove(u);
    num_edges--;
}

//ESPEC-7
void GraphAL::Print_Adjancency_List(const GraphAL& g) const{
    std::cout << "num_vertices: " << g.get_num_vertices() << "\n";
    std::cout << "num_edges: " << g.get_num_edges() << "\n";

    //mano, outro ngc e q ele pede que seja num_vertices - 1
    //so q quando coloca -1 ele n imprime todos
/*       /|\
          |
pensei numa solucao pra isso aqui*/
    uint n = g.get_num_vertices() + 1;
/*sinceramente achei brilhante*/

    for (uint u = 0; u < n-1 ; u++) {
        std::cout << u << ": ";

        const std::list<Vertex>& l = g.get_adj(u);

        for (auto v: l) {
            std::cout << v << ", ";
        }
        std::cout << "\n";
    }
}


//ESPEC-8

int main(){
    //ordem do grafo
    uint n = 0;

    //numero de arestas que pode adicionar ao grafo aka tamanho
    uint m = 0;

    std::cin >> n >> m;

    GraphAL graph(n);

    uint u, v = 0;

    //OUTRO ngc e q ele pede q seja n-1
    //sendo que so roda corretamente quando e m
/*    /|\
       |
pensei numa solucao melhor ainda pra esse tambem olha*/
    n = m + 1;
/*gostou?*/

    for(uint i = 0; i < n-1; i++){
        std::cin >> u >> v;
        graph.add_egde(u, v);
    }

    graph.Print_Adjancency_List(graph);

    return 0;
}