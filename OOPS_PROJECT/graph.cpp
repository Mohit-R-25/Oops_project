#include "vertex.h"
#include "edge.h"
#include "graph.h"
using namespace std;

graph::graph(){
    vertex_count = 0;
}

graph::add_vertex(string ver) {

    if(vertex_count > MAX){
        return false;
    }

    vertex v(ver);

    for (int i = 0; i < vertex_count; i++)
    {
        if (vertices[i] == v)
            return false;
    }

    vertices[vertex_count] = v;
    vertex_count++;

    return true;
}

graph::add_edge(string source, string dest, int weight){
    int src = -1, dst = -1;

    for (int i = 0; i < vertex_count; i++)
    {
        if (vertices[i].get_label() == source)
            src = i;

        if (vertices[i].get_label() == dest)
            dst = i;
    }

    if (src == -1 || dst == -1)
        return false;

    adjmatrix[src][dst] = weight;
    adjmatrix[dst][src] = weight;

    return true;
}

graph::displaygraph(){
    cout << "  ";
    for(int i = 0; i < vertex_count; i++){
        cout << vertices.get_label() << " ";
    }
    cout << "\n";

    for(int i = 0; i < vertex_count; i++){
        for(int j = 0; j < vertex_count; j++){
            if(j == 0){
                cout << vertices[i].get_label() << " ";
            }
            cout << adjmatrix[i][j] << " ";

            if(j+1 == vertex_count) {
                cout << "\n";
            }
        }
    }
}

