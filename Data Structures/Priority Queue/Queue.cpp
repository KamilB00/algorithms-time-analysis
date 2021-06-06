#include "Queue.h"

inline Queue::Queue(int edges){
    heap = new Edge_Element [edges];
    heapPosition = 0;
}

inline Queue::~Queue(){
    delete [] heap;
}

inline Edge_Element Queue::front(){
    return heap[0];
}

inline void Queue::push(Edge_Element edge) {
    int i, j;
    i = heapPosition++;
    j = (i-1) >> 1;


    while(i && (heap[j].weight > edge.weight)){
        heap[i] = heap[j];
        i = j;
        j = (i-1) >> 1;
    }

    heap[i] = edge;
}

inline void Queue::pop(){
    int i, j;
    Edge_Element edge{};

    if(heapPosition){
        edge = heap[--heapPosition];

        i = 0;
        j = 1;

        while(j<heapPosition){
            if((j+1 < heapPosition) && (heap[j+1].weight < heap[j].weight)) j++;
            if(edge.weight <= heap[j].weight) break;

            heap[i] = heap[j];
            i = j;
            j = (j<<1) + 1;
        }
        heap[i] = edge;
    }
}

