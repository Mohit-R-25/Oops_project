#include "vertex.h"
using namespace std;

int Vertex::count = 0;

//Default Constructor when label is not known
Vertex::Vertex(){
	ver = "";
}

//Parameterised Constructor when label is known
Vertex::Vertex(string ver){
	this->ver = ver;
	count++;
}

Vertex::~Vertex(){}

//Fns to return label, count
string Vertex::get_label() const{
	return ver;
}

int Vertex::get_count(){
	return count;
}

//Overloading of == operator
bool Vertex::operator==(const Vertex& other) const {
    return ver == other.ver;
}