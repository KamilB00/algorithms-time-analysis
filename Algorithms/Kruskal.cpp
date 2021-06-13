#include<iostream>
#include"../../algorithms-time-analysis/Graph/Graph.cpp"
#include"../../algorithms-time-analysis/Union Find/UnionFind.cpp"

using namespace std;

class Kruskal {
    Graph *graph = Graph::getInstance();
    int number_of_vertexes = graph->get_vertex_list().get_size();
    int number_of_edges = graph->get_edge_list().get_size();
    List<Edge_Element> *mst = new List<Edge_Element>();
    int summary_cost = 0;

    void show() {
        for (int i = 0; i < mst->get_size(); i++) {
            cout << mst->get(i).start_vertex << " " << mst->get(i).end_vertex << " $:" << mst->get(i).weight << endl;
        }
        cout<<"Cost: "<<summary_cost<<endl;
    }

public:
    void kruskalAL(bool show_result) {
        ArrayList<List<ArrayList<int>>> adjacency_list = graph->get_adjacency_list();

        Edge_Element edge{};
        UnionFind set(number_of_vertexes);
        auto *queue = new Queue(2 * number_of_edges);

        for (int i = 0; i < number_of_vertexes; i++) {
            set.makeSet(i);
        }

        for (int i = 0; i < number_of_vertexes; i++) {
            int number_of_neighbours = adjacency_list.get(i).get_size();
            for (int j = 0; j < number_of_neighbours; j++) {
                int end_vertex = adjacency_list.get(i).get(j).get(0);
                int weight = adjacency_list.get(i).get(j).get(1);

                edge.start_vertex = i;
                edge.end_vertex = end_vertex;
                edge.weight = weight;
                queue->push(edge);
            }
        }
        for (int i = 0; i < number_of_vertexes - 1; i++) {
            do {
                edge = queue->get_first();
                queue->pop();
            } while (set.findSet(edge.start_vertex) == set.findSet(edge.end_vertex));
            summary_cost += edge.weight;

            mst->addLast(edge);
            set.unionSets(edge);
        }
        if(show_result) {
            show();
        }
        delete queue;
    }

    void kruskalIM(bool show_result) {
        Edge_Element edge{};
        UnionFind set(number_of_vertexes);
        auto *queue = new Queue(2 * number_of_edges);


        int weight;
        int start_vertex;
        int end_vertex;
        int value;
        int last_i = INT_MAX;
        int last_j = INT_MAX;

        for (int i = 0; i < number_of_vertexes; i++) {
            set.makeSet(i);
        }

        for (int i = 0; i < number_of_edges; i++) {
            for (int j = 0; j < number_of_vertexes; j++) {

                value = graph->get_matrix_value(i, j);

                if (value > 0) {
                    if (i == last_i && j != last_j) {
                        start_vertex = last_j;
                        end_vertex = j;
                        weight = value;
                        edge.start_vertex = start_vertex;
                        edge.end_vertex = end_vertex;
                        edge.weight = weight;
                        queue->push(edge);
                    } else {
                        last_i = i;
                        last_j = j;
                    }
                }
            }
        }

        for (int i = 0; i < number_of_vertexes - 1; i++) {
            do {
                edge = queue->get_first();
                queue->pop();
            } while (set.findSet(edge.start_vertex) == set.findSet(edge.end_vertex));
            summary_cost += edge.weight;

            mst->addLast(edge);
            set.unionSets(edge);
        }
        if(show_result) {
            show();
        }
        delete queue;
    }
};
