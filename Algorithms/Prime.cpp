//
// Created by Kamil Bonkowski on 25/05/2021.
//
#include<iostream>
#include"../../algorithms-time-analysis/Algorithms/BellmanFord.cpp"
#include <algorithm>


class Prime {

    Graph *graph = Graph::getInstance();
    int number_of_vertexes = graph->get_vertex_list().get_size();
    int number_of_edges = graph->get_edge_list().get_size();
    int summary_cost = 0;
    bool *visited;
    Queue *queue;
    ArrayList<Edge_Element> *mst;
    int counter = 0;

public:
    Prime(){

    }

    void primAL(int start_node) {
        mst = new ArrayList<Edge_Element>();
        visited = new bool[number_of_vertexes];
        queue = new Queue(number_of_edges);
        for (int i = 0; i < number_of_vertexes; i++) {
            visited[i] = false;
        }
        visited[start_node] = true;
        int min = start_node;
        for (int i = 0; i < number_of_vertexes - 1; i++) {
            min = min_vertex_AL(min);
        }
        show_MST();
        cout << "Total cost: " << summary_cost << endl;

        delete [] visited;
        delete queue;
        //mst->removeAll();
    }

    void primIM(int start_node) {
        mst = new ArrayList<Edge_Element>();
        visited = new bool[number_of_vertexes];
        queue = new Queue(number_of_edges);
        for (int i = 0; i < number_of_vertexes; i++) {
            visited[i] = false;
        }
        visited[start_node] = true;
        int min = start_node;

        for (int i = 0; i < number_of_vertexes - 1; i++) {
            min = min_vertex_IM(min);
        }
        show_MST();
        cout << "Total cost: " << summary_cost << endl;

        delete [] visited;
        delete queue;
        mst->removeAll();
    }

    int min_vertex_IM(int src_vertex) {
        Edge_Element edge;

        int next_vertex = INT_MAX;
        int value = 0;
        for (int i = 0; i < number_of_edges; i++) {
            for (int j = 0; j < number_of_vertexes; j++) {
                value = graph->get_matrix_value(i, j);
                if (graph->get_matrix_value(i, src_vertex) > 0 && value > 0 && j != src_vertex) {
                    int cost = abs(value);
                    int end_vertex = j;
                    edge.start_vertex = src_vertex;
                    edge.end_vertex = end_vertex;
                    edge.weight = cost;
                    queue->push(edge);
                }
            }
        }
        do {
            edge = queue->front();
            queue->pop();

        } while (visited[edge.end_vertex]);

        visited[edge.end_vertex] = true;
        next_vertex = edge.end_vertex;
        summary_cost += edge.weight;

            mst->addLast(edge);

        return next_vertex;
    }

    int min_vertex_AL(int src_vertex) {

        Edge_Element edge{};
        int next_vertex = INT_MAX;

        ArrayList<List<ArrayList<int>>> adjacency_list = graph->get_adjacency_list();

        int number_of_neighbours = graph->get_adjacency_list().get(src_vertex).get_size();

        for (int j = 0; j < number_of_neighbours; j++) {
            edge.start_vertex = src_vertex;
            edge.end_vertex = adjacency_list.get(src_vertex).get(j).get(0);
            edge.weight = adjacency_list.get(src_vertex).get(j).get(1);
            queue->push(edge);
        }

        do {
            edge = queue->front();
            queue->pop();
        } while (visited[edge.end_vertex]);
        counter++;

        visited[edge.end_vertex] = true;
        next_vertex = edge.end_vertex;
        summary_cost += edge.weight;

        if(counter <= number_of_vertexes) {
            mst->addLast(edge);
            return next_vertex;
        }

        return INT_MAX;
    }

    void show_MST() {

        for (int i = 0; i < number_of_vertexes - 1; i++) {
            cout << mst->get(i).start_vertex << " " << mst->get(i).end_vertex << " $:" << mst->get(i).weight << endl;
        }
    }





};
