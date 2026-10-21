#ifndef e
#define e
#include "Vertex.h"

//each object of this class refers to a pair of vertices, thus an edge of the graph
class Edge{
    private:
        Vertex source; 
        Vertex dest;
        int weight; //weight of the edge object just created(can be any integer)

    public:
        Edge(Vertex source, Vertex dest, int weight = 1); //constructor with a default value for weight as 1

        ~Edge();  //destructor

        Vertex getsource(); //just return source vertex variable

        Vertex getdest(); //return destination vertex

        int getweight(); //return the weight of the edge object

        bool operator==(const Edge &e)const; //to check whether 2 objects of edge class are the same by checking equality of their corresponding source and dest vertices
        

};
#endif
