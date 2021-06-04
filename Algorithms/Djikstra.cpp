//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include<iostream>
#include<climits>
#include"../../algorithms-time-analysis/Graph/Graph.cpp"

using namespace std;


class Djikstra {

    int *length;
    int *previous;
    bool *visited;

    int min_next_vertex_AL(int src_node) {
        Graph *graph = Graph::getInstance();
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

public:
    Djikstra() {

    }

    void djikstra_adjacency_list(int start_node, int end_node) {
        Graph *graph = Graph::getInstance();

        int number_of_vertexes = graph->get_adjacency_list().get_size();
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

        show_path(start_node,end_node);
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
        } else {
            cout << "This connection does not exist !" << endl;
        }
        delete [] visited;
        delete [] length;
        delete [] previous;
    }

    int show_previous(int node) {
        cout << node << " ";
        return previous[node];
    }

    void show_arrays(int number_of_vertexes) {
        cout << "previous :";
        for (int i = 0; i < number_of_vertexes; i++) {
            cout << Djikstra::previous[i] << " ";
        }
        cout << endl;

        cout << "length :";
        for (int i = 0; i < number_of_vertexes; i++) {
            cout << Djikstra::length[i] << " ";
        }
        cout << endl;

        cout << "visited: ";
        for (int i = 0; i < number_of_vertexes; i++) {
            cout << Djikstra::visited[i] << " ";
        }
        cout << endl;
    }

};
