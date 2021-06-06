struct Edge_Element{
    int start_vertex;
    int end_vertex;
    int weight;
};

class Queue{
private:
    Edge_Element *heap; //heap with the edges
    int heapPosition;
public:
    Queue(int);
    ~Queue();
    Edge_Element front();
    void pop();
    void push(Edge_Element edge);
};

