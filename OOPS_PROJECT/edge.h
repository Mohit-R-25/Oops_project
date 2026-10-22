#ifndef edge_H
#define edge_H
#include "vertex.h"

//each object of this class refers to a pair of vertices, thus an edge of the graph
class edge{
    private:
        vertex source; 
        vertex dest;
        int weight; //weight of the edge object just created(can be any integer)

    public:
        edge(vertex source, vertex dest, int weight = 1); //constructor with a default value for weight as 1

        ~edge();  //destructor

        vertex getsource() const; //just return source vertex variable

        vertex getdest() const; //return destination vertex

        int getweight() const; //return the weight of the edge object

        bool operator==(const edge &other)const; //to check whether 2 objects of edge class are the same by checking equality of their corresponding source and dest vertices
        

};
#endif
