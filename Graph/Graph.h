//
// Created by Kamil Bonkowski on 25/05/2021.
//

#ifndef ALGORITHMS_TIME_ANALYSIS_GRAPH_H
#define ALGORITHMS_TIME_ANALYSIS_GRAPH_H

#include "../Data Structures/LinkedList/List.h"
#include"Vertex.h"
#include "Edge.h"


class Graph {
private:
    List<Vertex> *vertex_list;
    List<Edge> *edge_list;
    bool is_directed;
public:
    Graph();
    Graph(bool is_directed);
    bool get_is_directed() const;
    List<Vertex> get_vertex_list();
    List<Edge> get_edge_list();




};


#endif //ALGORITHMS_TIME_ANALYSIS_GRAPH_H
