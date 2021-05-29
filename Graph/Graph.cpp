//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include "../../algorithms-time-analysis/Data Structures/LinkedList/List.cpp"
#include "Edge.cpp"
#include<fstream>

using namespace std;

class Graph {

private:
    List<Vertex> *vertex_list;
    List<Edge> *edge_list;
    bool is_directed;
    int **incidence_matrix = nullptr;


    inline Graph() {
        this->vertex_list = new List<Vertex>();
        this->edge_list = new List<Edge>();
        this->is_directed = true;
    }

    inline static Graph *instance;


public:
    inline void set_is_directed(bool isDirected) {
        this->is_directed = isDirected;
    }

    inline List<Edge> get_edge_list() {
        return *edge_list;
    }

    inline List<Vertex> get_vertex_list() {
        return *vertex_list;
    }

    inline bool get_is_directed() const {
        return is_directed;
    }

    inline static Graph *getInstance() {
        if (!instance)
            instance = new Graph;
        return instance;
    }

    inline void fill_the_graph() {

        fstream in;
        in.open("/Users/kamilbonkowski/CLionProjects/algorithms-time-analysis/graf.txt", ios::in);
        if (!in.good()) in.open("/Users/kamilbonkowski/CLionProjects/algorithms-time-analysis/graf.txt", ios::in);

        if (in.good()) {
            int number_of_edges, number_of_vertexes;
            in >> number_of_edges >> number_of_vertexes;

            for (int i = 0; i < number_of_vertexes; i++) {
                auto *vertex = new Vertex(i);
                vertex_list->addLast(*vertex);
            }

            int vertex_start, vertex_end, weight;

            for (int i = 0; i < number_of_edges; i++) {
                in >> vertex_start >> vertex_end >> weight;
                auto *edge = new Edge(vertex_list->get(vertex_start), vertex_list->get(vertex_end), weight);
                edge_list->addLast(*edge);
            }

            in.close();
        } else {
            cout << "File can not be find " << endl;
        }
    }

    inline void show_the_graph() {

        for (int i = 0; i < edge_list->get_size(); i++) {
            cout << "start vertex: " << edge_list->get(i).get_start_vertex().get_id();
            cout << " end vertex: " << edge_list->get(i).get_end_vertex().get_id();
            cout << " weight: " << edge_list->get(i).get_weight() << endl;
        }
    }

    inline void **create_incidence_matrix() {
        int number_of_vertexes = vertex_list->get_size();
        int number_of_edges = edge_list->get_size();

        int **matrix = new int *[number_of_edges];
        for (int i = 0; i < number_of_edges; i++) {
            matrix[i] = new int[number_of_vertexes];
            for (int j = 0; j < number_of_vertexes; j++) {
                if (!is_directed) {
                    if (edge_list->get(i).get_start_vertex().get_id() == j ||
                        edge_list->get(i).get_end_vertex().get_id() == j) {
                        matrix[i][j] = edge_list->get(i).get_weight();
                    } else {
                        matrix[i][j] = 0;
                    }

                } else if (is_directed) {
                    if (edge_list->get(i).get_start_vertex().get_id() == j) {
                        matrix[i][j] = edge_list->get(i).get_weight();
                    } else if (edge_list->get(i).get_end_vertex().get_id() == j) {
                        matrix[i][j] = (-1) * edge_list->get(i).get_weight();
                    } else {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        incidence_matrix = matrix;
    }

    void show_graph_as_incidence_matrix() {
        for (int i = 0; i < edge_list->get_size(); i++) {
            for (int j = 0; j < vertex_list->get_size(); j++) {
                cout << incidence_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

};
