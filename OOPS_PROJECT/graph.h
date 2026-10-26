#ifndef g
#define g
#include "vertex.h"
#include "edge.h"
class graph{
    private:
        static const int MAX = 10; //maximum number of vertices allowed, must be constant and static because it is an instance of class, not each individual graph object
        
        vertex vertices[MAX];
        int adjmatrix[MAX][MAX] = {};
        int vertex_count;


    public:
        graph(); //constructor

        ~graph(); //destructor

        bool add_vertex(string ver); // return true if the vertex was successfully added (to make sure it does not go higher than MAX)
        bool add_edge(string source, string dest, int weight = 1);

        void displaygraph(); //print the graph as a 2d array in which each row and coloumn represents a vertex(the matrix will be symmetric because its undirected)
        /* example output:
                A   B   C
            A   0   5   3
            B   5   0   2
            C   3   2   0
        */

        graph operator+(const graph& other) const; //for adding two graphs(idk logic)
        bool operator==(const graph& other) const; //for checking equality of each vertex and edge's weights to determine equality of 2 graphs
        
};
#endif
