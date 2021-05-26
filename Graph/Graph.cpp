//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include "Graph.h"
#include "../../algorithms-time-analysis/Data Structures/mystl.h"


Graph::Graph(bool is_directed) {
    this->vertex_list = new List<Vertex>();
    this->edge_list = new List<Edge>();
    this->is_directed = is_directed;
}
List<Edge> Graph::get_edge_list() {
    return *edge_list;
}
List<Vertex> Graph::get_vertex_list() {
    return *vertex_list;
}

bool Graph::get_is_directed() const {
    return is_directed;
}