#include <string>
#include <iostream>
#ifndef VERTEX_H
#define VERTEX_H

using namespace std;
//each object of this class is a vertex of the graph
class vertex{
    private:
        string ver;
        static int count;

    public:
        vertex();

        vertex(string ver); //constructor for creating unique vertex for each instance of class

        ~vertex(); //destructor

        string get_label() const; //just return the ver of the object

        bool operator==(const vertex& other) const; //to check if two objects of vertex class are having the same ver value
        static int get_count();

        friend ostream& operator<<(ostream& os, const vertex& vtx);
        friend istream& operator>>(istream& is, vertex& vtx);

};
#endif
