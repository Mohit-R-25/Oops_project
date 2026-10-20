#ifndef g
#define g
#include "Vertex.h"
#include "Edge.h"
class Graph{
    private:
        static const int MAX = 10; //maximum number of vertices allowed, must be constant and static because it is an instance of class, not each individual graph object
        
        Vertex vertices[MAX];
        int adjmatrix[MAX];
        int vertex_count;


    public:
        Graph(); //constructor

        ~Graph(); //destructor

        bool add_vertex(char ver); // return true if the vertex was successfully added (to make sure it does not go higher than MAX)
        bool add_edge(char source, char dest, int weight = 1);

        void displaygraph(); //print the graph as a 2d array in which each row and coloumn represents a vertex(the matrix will be symmetric because its undirected)
        /* example output:
                A   B   C
            A   0   5   3
            B   5   0   2
            C   3   2   0
        */

        Graph operator+(const Graph& other) const; //for adding two graphs(idk logic)
        bool operator==(const Graph& other) const; //for checking equality of each vertex and edge's weights to determine equality of 2 graphs
        
};
#endif