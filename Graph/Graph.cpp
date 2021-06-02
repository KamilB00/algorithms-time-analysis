//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include "../../algorithms-time-analysis/Data Structures/LinkedList/List.cpp"
#include "../../algorithms-time-analysis/Data Structures/ArrayList/ArrayList.cpp"
#include "Edge.cpp"
#include<fstream>
#include<cmath>

using namespace std;

class Graph {

private:
    List<Vertex> *vertex_list = nullptr;
    List<Edge> *edge_list = nullptr;
    bool is_directed;
    int **incidence_matrix = nullptr;
    ArrayList<List<ArrayList<int>>> *adjacency_list = nullptr;

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

    inline void create_adjacency_list(){
        int number_of_vertexes = vertex_list->get_size();
        int number_of_edges = edge_list->get_size();
        auto *adj_list = new ArrayList<List<ArrayList<int>>>();

        for(int i=0; i<number_of_vertexes; i++){
            auto *list = new List<ArrayList<int>>();
            for(int j=0; j<number_of_edges;j++){
                if(is_directed){
                    if(edge_list->get(j).get_start_vertex().get_id() == i) {
                        auto *array_list = new ArrayList<int>();
                        array_list->addLast(edge_list->get(j).get_end_vertex().get_id());
                        array_list->addLast(edge_list->get(j).get_weight());
                        list->addLast(*array_list);
                    }
                }
                else if(!is_directed){
                    if(edge_list->get(j).get_start_vertex().get_id() == i){
                        auto *array_list = new ArrayList<int>();
                        array_list->addLast(edge_list->get(j).get_end_vertex().get_id());
                        array_list->addLast(edge_list->get(j).get_weight());

                        list->addLast(*array_list);
                    }
                    if(edge_list->get(j).get_end_vertex().get_id() == i){
                        auto *array_list = new ArrayList<int>();
                        array_list->addLast(edge_list->get(j).get_start_vertex().get_id());
                        array_list->addLast(edge_list->get(j).get_weight());
                        list->addLast(*array_list);
                    }
                }
            }
            adj_list->addLast(*list);
        }
        adjacency_list = adj_list;
    }

   inline void show_adjacency_list(){

        for(int i=0;i<adjacency_list->get_size();i++){
            cout<<"["<<i<<"]: ";
            for(int j=0; j<adjacency_list->get(i).get_size();j++){
                adjacency_list->get(i).get(j).show();
               cout<<"  ";
            }
            cout<<endl;
        }
    }

   inline void show_incidence_matrix() {
        for (int i = 0; i < edge_list->get_size(); i++) {
            for (int j = 0; j < vertex_list->get_size(); j++) {
                cout << incidence_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    inline void delete_adjacency_list(){
        for(int i=0;i<adjacency_list->get_size(); i++){
           for(int j=0; j<adjacency_list->get(i).get_size(); j++){
               adjacency_list->get(i).get(j).removeAll();
           }
            adjacency_list->get(i).removeAll();
        }
        adjacency_list = nullptr;
    }

    inline void delete_incidence_matrix(){
        for(int i =0; i<edge_list->get_size(); i++){
            delete [] incidence_matrix[i];
        }
        delete [] incidence_matrix;
        incidence_matrix = nullptr;
    }

    inline void delete_graph(){
        if(edge_list->get_size()>0){
            delete_incidence_matrix();
            delete_adjacency_list();
        }
        vertex_list->removeAll();
        edge_list->removeAll();
    }

    inline int calculate_edges(int density, int number_of_vertexes, bool directed){ // returns number of edges needed in the graph
        int difference = 0;
        int max_edges_number = 0;
        int possible_density = 0;

        max_edges_number = (int)(number_of_vertexes*(number_of_vertexes-1))/2;

        int approx_edges = (int)(((float)density/100.0)*(float)max_edges_number);
        int approx_density = (int)(approx_edges*100/max_edges_number);

        int number_of_edges = 0;
        int min_difference = 100;

        for(int i = approx_edges-1; i<max_edges_number; i++){
            possible_density = (int)(i*100)/max_edges_number;
            difference = abs(density-possible_density);
            if(difference < min_difference){
                min_difference = difference;
                number_of_edges = i;
            }
        }
        if(directed){
           number_of_edges = 2*number_of_edges;
        }

        cout<<"Nearest available density: "<<(int)(number_of_edges*100/max_edges_number)<<endl;
        return number_of_edges;
    }

    inline void generate_new_graph(bool directed){
        int number_of_vertexes = 0;
        int density = 0;
        int number_of_edges = 0;


        cout<<"Number of vertexes :";
        cin>>number_of_vertexes;

        int minimum_number_of_edges = number_of_vertexes - 1; // to make graph connected


        do {
            cout << "Density: ";
            cin >> density;
        }while(density < minimum_number_of_edges/(number_of_vertexes*(number_of_vertexes-1))/2);


        number_of_edges = calculate_edges(density,number_of_vertexes, directed);
        cout<<"Number of edges: "<<number_of_edges<<endl;

       //adding vertexes to Vertex List
//       for(int i=0;i<number_of_vertexes;i++){
//           auto *vertex = new Vertex(i);
//           get_vertex_list().addLast(*vertex);
//       }



    }


};
