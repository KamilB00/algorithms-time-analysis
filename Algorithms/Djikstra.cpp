//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include<iostream>
#include<climits>
#include <cmath>
#include"Prime.cpp"

using namespace std;


class Djikstra {

    int *length;
    int *previous;
    bool *visited;
    Graph *graph = Graph::getInstance();
    int number_of_edges = graph->get_edge_list().get_size();
    int number_of_vertexes = graph->get_vertex_list().get_size();

    int min_next_vertex_AL(int src_node) {

        int min_vertex = INT_MAX;
        int min_length = INT_MAX;
        int number_of_neighbours = graph->get_adjacency_list().get(src_node).get_size();

        for (int i = 0; i < number_of_neighbours; i++) {

            int current_vertex = graph->get_adjacency_list().get(src_node).get(i).get(0);
            int current_length = graph->get_adjacency_list().get(src_node).get(i).get(1);

            if (!visited[current_vertex]) {
                visited[current_vertex] = true;

                if (length[src_node] + current_length < length[current_vertex]) {
                    previous[current_vertex] = src_node;
                    length[current_vertex] = length[src_node] + current_length;
                }
            }

            if (current_length < min_length) {
                min_length = current_length;
                min_vertex = current_vertex;
            }
        }
        return min_vertex;
    }

    int min_next_vertex_IM(int src_node) {
        int min_vertex = INT_MAX;
        int min_length = INT_MAX;

        int value = 0;
        for (int i = 0; i < number_of_edges; i++) {
            for (int j = 0; j < number_of_vertexes; j++) {
                value = graph->get_matrix_value(i, j);
                if (graph->get_matrix_value(i, src_node) > 0 && value < 0) {
                    int current_length = abs(value);
                    int current_vertex = j;

                    if (!visited[current_vertex]) {
                        visited[current_vertex] = true;

                        if (length[src_node] + current_length < length[current_vertex]) {
                            previous[current_vertex] = src_node;
                            length[current_vertex] = length[src_node] + current_length;
                        }
                    }
                    if (current_length < min_length) {
                        min_length = current_length;
                        min_vertex = current_vertex;
                    }
                }
            }
        }
        return min_vertex;

    }

public:
    Djikstra() {
        length = new int[number_of_vertexes];
        previous = new int[number_of_vertexes];
        visited = new bool[number_of_vertexes];
    }

    void djikstra_incidence_matrix(int start_node, int end_node, bool show_result) {

        for (int i = 0; i < number_of_vertexes; i++) {
            length[i] = INT_MAX;
            visited[i] = false;
            previous[i] = -1;
        }

        length[start_node] = 0;
        int min_vertex = start_node;
        visited[start_node] = true;

        for (int i = 0; i < number_of_vertexes; i++) {
            min_vertex = min_next_vertex_IM(min_vertex);
        }

        if (show_result) {
            show_path(start_node, end_node);
        }
    }

    void djikstra_adjacency_list(int start_node, int end_node, bool show_result) {

        if (number_of_vertexes == 0) {
            cout << "Graph is empty !" << endl;
            return;
        }
        length = new int[number_of_vertexes];
        previous = new int[number_of_vertexes];
        visited = new bool[number_of_vertexes];

        for (int i = 0; i < number_of_vertexes; i++) {
            length[i] = INT_MAX;
            visited[i] = false;
            previous[i] = -1;
        }

        length[start_node] = 0;
        int min_vertex = start_node;
        visited[start_node] = true;

        for (int i = 0; i < number_of_vertexes; i++) {
            min_vertex = min_next_vertex_AL(min_vertex);
        }
        if (show_result) {
            show_path(start_node, end_node);
        }
    }

    void show_path(int start_node, int end_node) {
        if (length[end_node] != INT_MAX) {
            int node = end_node;
            cout << "Path: ";
            while (node != start_node) {
                node = show_previous(node);
            }
            cout << start_node << " ";
            cout << endl;
            cout << "Cost :" << length[end_node] << endl;
            show_arrays();
        } else {
            cout << "This connection does not exist !" << endl;
        }
    }

    int show_previous(int node) {
        cout << node << " ";
        return previous[node];
    }

    void show_arrays() {
        cout << "previous :";
        for (int i = 0; i < number_of_vertexes; i++) {
            cout << Djikstra::previous[i] << " ";
        }
        cout << endl;

        cout << "length :";
        for (int i = 0; i < number_of_vertexes; i++) {
            int dist = Djikstra::length[i];

            if (dist != INT_MAX) {
                cout << dist << " ";
            } else {
                cout << "inf ";
            }
        }
        cout << endl;

        cout << "visited: ";
        for (int i = 0; i < number_of_vertexes; i++) {
            cout << Djikstra::visited[i] << " ";
        }
        cout << endl;
    }

    ~Djikstra() {
        delete[] visited;
        delete[] length;
        delete[] previous;
    }

};
