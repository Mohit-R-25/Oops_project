#include "vertex.h"
using namespace std;

int vertex::count = 0;

//Default Constructor when label is not known
vertex::vertex(){
	ver = "";
	count++;
}

//Parameterised Constructor when label is known
vertex::vertex(string ver){
	this->ver = ver;
	count++;
}

vertex::~vertex(){
	count--;
}

//Fns to return label, count
string vertex::get_label() const{
	return ver;
}

int vertex::get_count(){
	return count;
}

ostream& operator<<(ostream& os, const vertex& vtx){
    os << vtx.ver;
    return os;
}

istream& operator>>(istream& is, vertex& vtx){
    is >> vtx.ver;
    return is;
}

//Overloading of == operator
bool vertex::operator==(const vertex& other) const {
    return ver == other.ver;
}
