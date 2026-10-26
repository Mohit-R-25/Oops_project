#include "edge.h"
using namespace std;

edge::edge(vertex source, vertex dest, int weight){
	this->source = source;
	this->dest = dest;
	this->weight = weight;
}

edge::~edge(){}

//Fns to return source, destination, weight of edge
vertex edge::getsource() const{return source;}
vertex edge::getdest() const{return dest;}
int edge::getweight() const{return weight;}

//Overloading of == operator
bool edge::operator ==(const edge& other) const{
	return (source == other.source && dest == other.dest)||(source == other.dest && dest == other.source); // Undirected graph so A-B = B-A
}

ostream& operator<<(ostream& os, const edge& ed){
    os << ed.source << " - " << ed.dest << " (weight " << ed.weight << ")";
    return os;
}

istream& operator>>(istream& is, edge& ed){
    is >> ed.source >> ed.dest >> ed.weight;    // input format: A B 5
    return is;
}
