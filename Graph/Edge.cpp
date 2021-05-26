//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include "Edge.h"
#include "Vertex.h"

Edge::Edge() {}
Edge::Edge(Vertex start_vertex, Vertex end_vertex, int weight){
    this->start_vertex = start_vertex;
    this->end_vertex = end_vertex;
    this->weight = weight;
}

Vertex Edge::get_start_vertex() {
    return start_vertex;
}

Vertex Edge::get_end_vertex() {
    return end_vertex;
}
int Edge::get_weight() const {
    return weight;
}

void Edge::set_start_vertex(Vertex vertex) {
    this->start_vertex = vertex;
}
void Edge::set_end_vertex(Vertex vertex) {
    this->end_vertex = vertex;
}
void Edge::set_weight(int edge_weight) {
    this->weight = edge_weight;
}



