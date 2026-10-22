#include edge.cpp
using namespace std;

Edge::Edge(Vertex source, Vertex dest, int weight){
	this->source = source;
	this->dest = dest;
	this->weight = weight;
}

Edge::~Edge(){}

//Fns to return source, destination, weight of edge
Vertex Edge::getsource() const{return source;}
Vertex Edge::getsdest() const{return dest;}
int Edge::getweight() const{return weight;}

//Overloading of == operator
bool Edge::operator ==(const Edge& other) const{
	return (source == other.source && dest == other.dest)||(source == other.dest && dest == other.source); // Undirected graph so A-B = B-A
}