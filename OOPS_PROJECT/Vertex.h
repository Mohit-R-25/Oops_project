#ifndef v
#define v

//each object of this class is a vertex of the graph
class Vertex{
    private:
        char ver;

    public:
        Vertex(char ver = 'A'); //constructor with default label value as 'A'

        ~Vertex(); //destructor

        char get_label(); //just return the ver of the object

        bool operator==(const Vertex& v) const; //to check if two objects of vertex class are having the same ver value

};
#endif