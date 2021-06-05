//
// Created by Kamil Bonkowski on 29/05/2021.
//
class PriorityQueue {

    struct Edge_Element{
        int vertexStart;
        int vertexEnd;
        int weight;
    };


    private:
        Edge_Element *heap;
        int heapPosition;

    public:
        explicit PriorityQueue(int);
        ~PriorityQueue();
        Edge_Element front();
        void push(Edge_Element edge);
        void pop();
    };




