#include <string>
#include <iostream>
#ifndef vertex_H
#define vertex_H

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

        friend ostream& operator<<(ostream& os, const vertex& ver);
        friend istream& operator>>(istream& is, vertex& ver)

};
#endif
