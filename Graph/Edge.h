//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include "Vertex.cpp"
class Edge {
private:
    Vertex start_vertex;
    Vertex end_vertex;
    int weight{};
public:
    Edge();
    Edge(Vertex start_vertex, Vertex end_vertex, int edge_weight);
    void set_start_vertex(Vertex vertex);
    void set_end_vertex(Vertex vertex);
    void set_weight (int edge_weight);
    Vertex get_start_vertex();
    Vertex get_end_vertex();
    int get_weight() const;
};


