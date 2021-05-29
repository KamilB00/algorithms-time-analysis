//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include "Edge.h"

inline Edge::Edge() = default;
inline Edge::Edge(Vertex start_vertex, Vertex end_vertex, int weight){
    this->start_vertex = start_vertex;
    this->end_vertex = end_vertex;
    this->weight = weight;
}

inline Vertex Edge::get_start_vertex() {
    return start_vertex;
}

inline Vertex Edge::get_end_vertex() {
    return end_vertex;
}
inline int Edge::get_weight() const {
    return weight;
}

inline void Edge::set_start_vertex(Vertex vertex) {
    this->start_vertex = vertex;
}
inline void Edge::set_end_vertex(Vertex vertex) {
    this->end_vertex = vertex;
}
inline void Edge::set_weight(int edge_weight) {
    this->weight = edge_weight;
}



