#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

//ESPEC-1
typedef unsigned int Vertex;
typedef unsigned int uint;

class GraphAL{
private:
    //ESPEC-2 ( Tem que ser ponteiro )
    std::list<Vertex> adj*[];

    uint num_vertices;
    uint num_edges;

public:
    //ESPEC-3
    GraphAL::Constructor(uint num_vertices){
        this->num_vertices = num_vertices;
        this->num_edges = 0;

    }

    //ESPEC-4
    ~GraphAL(){
        delete [] adj;
        adj = nullptr;
    }
}

//ESPEC-8
//Depois colocar tratamento de exceção para quanfo for número negativo e mesma entrada 2 vezes
int main(){
    //ordem do grafo
    uint n = 0;

    //número de arestas que pode adicionar ao grafo aka tamanho
    uint m = 0;

    cin >> n >> m;

    GraphAL graph(n,m);

    uint u, v = 0;

    for(uint i = 0; i < n-1; i++){
        cin >> u >> v;
        //dps adicionar {u,v} para graph com um método especifico
    }

    //dps chamar metodo pra printar o graph


}