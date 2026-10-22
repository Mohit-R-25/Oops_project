#ifndef v
#define v

//each object of this class is a vertex of the graph
class Vertex{
    private:
        string ver;
        static int count;

    public:
        Vertex();

        Vertex(string ver); //constructor for creating unique vertex for each instance of class

        ~Vertex(); //destructor

        string get_label(); //just return the ver of the object

        bool operator==(const Vertex& v) const; //to check if two objects of vertex class are having the same ver value
        static int get_count();

};
#endif
