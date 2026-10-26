#include<iostream>
#include<string>
#include "graph.h"
using namespace std;

graph::graph(){
    vertex_count = 0;
}
graph::~graph()
{
}

bool graph::add_vertex(string ver) {

    if(vertex_count >= MAX){
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

bool graph::add_edge(string source, string dest, int weight){
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

void graph::displaygraph(){
    cout << "  ";
    // Print column labels
    for(int i = 0; i < vertex_count; i++){
        cout << vertices[i].get_label() << " ";
    }
    cout << "\n";

    // Print row labels and adjacency matrix
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

// Output: prints the adjacency matrix
ostream& operator<<(ostream& os, const graph& gr){
    os << "  ";
    for(int i = 0; i < gr.vertex_count; i++)
        os << gr.vertices[i] << " ";
    os << "\n";

    for(int i = 0; i < gr.vertex_count; i++){
        os << gr.vertices[i] << " ";
        for(int j = 0; j < gr.vertex_count; j++)
            os << gr.adjmatrix[i][j] << " ";
        os << "\n";
    }
    return os;
}

// Input format:
//   n
//   label1 label2 ... labeln
//   m
//   src dest weight     (m lines)
istream& operator>>(istream& is, graph& gr){
    gr = graph();                       // start from an empty graph
    int n, m;

    if(!(is >> n)) return is;
    for(int i = 0; i < n; i++){
        string label;
        if(!(is >> label)) return is;
        if(!gr.add_vertex(label)){      // duplicate or too many
            is.setstate(ios::failbit);
            return is;
        }
    }

    if(!(is >> m)) return is;
    for(int i = 0; i < m; i++){
        string s, d;
        int w;
        if(!(is >> s >> d >> w)) return is;
        if(!gr.add_edge(s, d, w)){      // unknown vertex
            is.setstate(ios::failbit);
            return is;
        }
    }
    return is;
}
