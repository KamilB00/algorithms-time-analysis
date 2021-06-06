//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include"../../algorithms-time-analysis/Algorithms/Kruskal.cpp"
#include <climits>
#include <iostream>

using namespace std;


class BellmanFord {

    Graph *graph = Graph::getInstance();
    int number_of_vertexes = graph->get_vertex_list().get_size();
    int number_of_edges = graph->get_edge_list().get_size();
    int *distance;
    int *previous;
    bool stop_condition;

    ArrayList<List<ArrayList<int>>> adjacency_list;


    void show_path(int start_node, int end_node) {
        if (distance[end_node] != INT_MAX) {
            int node = end_node;
            cout << "Path: ";
            while (node != start_node) {
                node = show_previous(node);
            }
            cout << start_node << " ";
            cout << endl;
            cout << "Cost :" << distance[end_node] << endl;
            show_arrays();
        } else {
            cout << "This connection does not exist !" << endl;
        }
    }

    void show_arrays() {
        cout << "previous :";
        for (int i = 0; i < number_of_vertexes; i++) {
            cout << BellmanFord::previous[i] << " ";
        }
        cout << endl;

        cout << "length :";
        for (int i = 0; i < number_of_vertexes; i++) {
            int dist = BellmanFord::distance[i];
            if (dist != INT_MAX) {
                cout << dist << " ";
            } else {
                cout << "inf ";
            }
        }
        cout << endl;

    }

    int show_previous(int node) {
        cout << node << " ";
        return previous[node];
    }

public:
    void bellmanFordAL(int src_node, int end_node) {
        adjacency_list = graph->get_adjacency_list();

        distance = new int[number_of_vertexes];
        previous = new int[number_of_vertexes];

        for (int i = 0; i < number_of_vertexes; i++) {
            distance[i] = INT_MAX;
            previous[i] = -1;
        }

        distance[src_node] = 0;


        for (int i = 0; i < number_of_vertexes - 1; i++) {
            stop_condition = true;
            for (int j = 0; j < number_of_vertexes; j++) {
                int number_of_neighbours = adjacency_list.get(j).get_size();
                for (int k = 0; k < number_of_neighbours; k++) {
                    int current_vertex = adjacency_list.get(j).get(k).get(0);
                    int current_weight = adjacency_list.get(j).get(k).get(1);
                    if ((distance[j] != INT_MAX) && (distance[current_vertex] > distance[j] + current_weight)) {
                        distance[current_vertex] = distance[j] + current_weight;
                        previous[current_vertex] = j;
                        stop_condition = false;
                    }
                }
            }
            if (stop_condition) break;
        }

       show_path(src_node, end_node);

        delete[] distance;
        delete[] previous;
    }

    void bellmanFordIM(int src_node, int end_node) {
        adjacency_list = graph->get_adjacency_list();

        distance = new int[number_of_vertexes];
        previous = new int[number_of_vertexes];

        for (int i = 0; i < number_of_vertexes; i++) {
            distance[i] = INT_MAX;
            previous[i] = -1;
        }

        distance[src_node] = 0;
        int weight;
        int start_vertex;
        int end_vertex;
        int value;
        int it_1 = INT_MAX;
        int it_2 = INT_MAX;


        for(int k=0 ;k< number_of_vertexes -1; k++) {

            for (int i = 0; i < number_of_edges; i++) {
                for (int j = 0; j < number_of_vertexes; j++) {

                    value = graph->get_matrix_value(i, j);

                    if (value > 0) {
                        start_vertex = j;
                        weight = abs(value);
                        it_1 = i;
                    }
                    if (value < 0) {
                        end_vertex = j;
                        it_2 = i;
                    }
                    if (it_1 == it_2) {
                        if (distance[start_vertex] != INT_MAX && distance[end_vertex] > distance[start_vertex]+ weight){
                            distance[end_vertex] = distance[start_vertex] + weight;
                            previous[end_vertex] = start_vertex;
                        }
                    }
                }
            }
        }

        show_path(src_node, end_node);

        delete[] distance;
        delete[] previous;
    }

};