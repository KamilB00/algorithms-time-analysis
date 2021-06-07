#include <iostream>
#include "Menu.h"
#include "../../algorithms-time-analysis/Algorithms/Djikstra.cpp"
#include"../../algorithms-time-analysis/Timer/Timer.cpp"
#include <string>


using namespace std;

inline int Menu::algorithm_representation_screen() {
    cout << "--- Solve problem using: ---" << endl;
    cout << "1. adjacency list" << endl;
    cout << "2. incidence matrix" << endl;
    cout << endl;
    cout << "Press 0 to return" << endl;
    return select_option(2);
}

inline int Menu::choose_graph_property_screen() {
    cout << "1. directed" << endl;
    cout << "2. undirected" << endl;

    return select_option(2);
}

inline int Menu::select_option(int upper_bounds) {
    int choice;
    do {
        cout << "Choose option : ";
        cin >> choice;
    } while (!(choice >= 0 && choice <= upper_bounds));

    return choice;
}

inline int Menu::mode_selection_screen() {
    cout << "1. Presentation mode" << endl;
    cout << "2. Experimental mode" << endl;
    cout << endl;
    cout << "Press 0 to exit" << endl;
    return select_option(2);
}

inline int Menu::welcome_screen() {
    cout << endl;
    cout << " ------------------ Menu --------------------- " << endl;
    cout << "1. Read Graph from file   " << endl;
    cout << "2. Generate Random Graph  " << endl;
    cout << "3. Display Graph as Adjacency List" << endl;
    cout << "4. Display Graph as Incidence Matrix" << endl;
    cout << "5. Prim's algorithm" << endl;
    cout << "6. Kruskal's algorithm" << endl;
    cout << "7. Djiksra" << endl;
    cout << "8. Bellman-Ford" << endl;
    cout << "9. Delete graph" << endl;
    cout << endl;
    cout << "Press 0 to return           " << endl;
    cout << "----------------------------------------------- " << endl;
    return select_option(9);
}

inline int Menu::expertimental_screen() {
    cout << " ------------- Experimental Menu -------------- " << endl;
    cout << "1. Generate Random Graph  " << endl;
    cout << "2. Show Generated Graph  " << endl;
    cout << "3. Prim's algorithm" << endl;
    cout << "4. Kruskal's algorithm" << endl;
    cout << "5. Djiksra" << endl;
    cout << "6. Bellman-Ford" << endl;
    cout << "7. Delete graph" << endl;
    cout << endl;
    cout << "Press 0 to return           " << endl;
    cout << "----------------------------------------------- " << endl;

    return select_option(7);
}

inline Menu::Menu() = default;

inline void Menu::main_screen() {
    int mode = mode_selection_screen();
    do {
        switch (mode) {
            case 0: {
                exit(1);
            }

            case 1: { //Presentation mode

                int welcome_choice = welcome_screen();
                do {
                    switch (welcome_choice) {
                        case 0: {
                            mode_selection_screen();
                            break;
                        }
                        case 1: {
                            //wczytaj graf z pliku
                            Graph *graph = Graph::getInstance();

                            int isDirected;
                            isDirected = choose_graph_property_screen();
                            switch (isDirected) {
                                case 1: {
                                    graph->set_is_directed(true);
                                    break;
                                }
                                case 2: {
                                    graph->set_is_directed(false);
                                    break;
                                }
                                default:
                                    graph->set_is_directed(true);
                                    break;
                            }

                            if (graph->get_edge_list().get_size() > 0) {
                                cout << "Graph already exists !" << endl;
                            } else {
                                graph->fill_the_graph();
                            }
                            graph->create_incidence_matrix();
                            graph->create_adjacency_list();

                            break;
                        }
                        case 2: {
                            //wygeneruj losowy graf
                            cout << "Only in experimental mode " << endl;

                        }
                        case 3: {
                            //wyświetl graf w postaci listy sąsiedztwa
                            Graph *graph = Graph::getInstance();
                            if (graph->get_edge_list().get_size() > 0) {
                                graph->show_adjacency_list();
                            } else {
                                cout << "No graph loaded !" << endl;
                            }
                            break;
                        }
                        case 4: {
                            //wyświetl graf w postaci macierzy incydencji
                            Graph *graph = Graph::getInstance();
                            if (graph->get_edge_list().get_size() > 0) {
                                graph->show_incidence_matrix();
                            } else {
                                cout << "No graph loaded !" << endl;
                            }
                            break;
                        }
                        case 5: {
                            //PRIME'S ALGORITHM

                            int representation = algorithm_representation_screen();

                            do {
                                switch (representation) {
                                    //algorytm prima lista sąsiedztwa
                                    case 1: {
                                        Graph *graph = Graph::getInstance();
                                        auto *prime = new Prime();
                                        int start_vertex;
                                        int number_of_vertexes = graph->get_vertex_list().get_size();
                                        cout << "start vertex: ";
                                        cin >> start_vertex;
                                        if (start_vertex >= 0 && start_vertex < number_of_vertexes) {
                                            prime->primAL(start_vertex, true);
                                        }
                                        break;
                                    }
                                    case 2: {
                                        //algorytm prima macierz incydencji
                                        Graph *graph = Graph::getInstance();
                                        auto *prime = new Prime();
                                        int start_vertex;
                                        int number_of_vertexes = graph->get_vertex_list().get_size();
                                        cout << "start vertex: ";
                                        cin >> start_vertex;
                                        if (start_vertex >= 0 && start_vertex < number_of_vertexes) {
                                            prime->primIM(start_vertex, true);
                                        }
                                        break;
                                    }
                                }

                            } while (representation = algorithm_representation_screen());

                            break;
                        }
                        case 6: {
                            //KRUSKAL'S ALGORITHM
                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1: {
                                        auto *kruskal = new Kruskal();
                                        kruskal->kruskalAL(true);

                                        break;
                                    }
                                    case 2: {
                                        auto *kruskal = new Kruskal();
                                        kruskal->kruskalIM(true);

                                        break;
                                    }
                                }
                            } while (representation = algorithm_representation_screen());
                            break;
                        }
                        case 7: {
                            //DJIKSTRA ALGORITHM
                            int representation = algorithm_representation_screen();
                            switch (representation) {
                                case 1: {

                                    auto *graph = Graph::getInstance();
                                    auto *djikstra = new Djikstra();
                                    int start_vertex;
                                    int end_vertex;

                                    int number_of_vertexes = graph->get_vertex_list().get_size();
                                    cout << "start vertex: ";
                                    cin >> start_vertex;

                                    cout << "end vertex: ";
                                    cin >> end_vertex;
                                    if ((start_vertex >= 0 && start_vertex < number_of_vertexes) &&
                                        (end_vertex >= 0 && end_vertex < number_of_vertexes)) {
                                        djikstra->djikstra_adjacency_list(start_vertex, end_vertex, true);
                                    }
                                    delete djikstra;
                                    break;
                                }
                                case 2: {

                                    cout << "Djikstra as a matrix" << endl;
                                    auto *graph = Graph::getInstance();
                                    auto *djikstra = new Djikstra();
                                    int start_vertex;
                                    int end_vertex;

                                    int number_of_vertexes = graph->get_vertex_list().get_size();
                                    cout << "start vertex: ";
                                    cin >> start_vertex;

                                    cout << "end vertex: ";
                                    cin >> end_vertex;
                                    if ((start_vertex >= 0 && start_vertex < number_of_vertexes) &&
                                        (end_vertex >= 0 && end_vertex < number_of_vertexes)) {
                                        djikstra->djikstra_incidence_matrix(start_vertex, end_vertex, true);
                                    }
                                    delete djikstra;
                                    break;
                                }
                            }
                            break;
                        }
                        case 8: {
                            //BELLMAN-FORD ALGORITHM
                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1: {
                                        // Bellman-Ford as a incidence list
                                        int start_vertex;
                                        int end_vertex;
                                        Graph *graph = Graph::getInstance();
                                        auto *bellmanFord = new BellmanFord();
                                        int number_of_vertexes = graph->get_vertex_list().get_size();
                                        cout << "start vertex: ";
                                        cin >> start_vertex;

                                        cout << "end vertex: ";
                                        cin >> end_vertex;
                                        if ((start_vertex >= 0 && start_vertex < number_of_vertexes) &&
                                            (end_vertex >= 0 && end_vertex < number_of_vertexes)) {

                                            bellmanFord->bellmanFordAL(start_vertex, end_vertex, true);
                                        }
                                        delete bellmanFord;
                                        break;
                                    }
                                    case 2: {
                                        // Bellman-Ford as a matrix
                                        int start_vertex;
                                        int end_vertex;
                                        Graph *graph = Graph::getInstance();
                                        auto *bellmanFord = new BellmanFord();
                                        int number_of_vertexes = graph->get_vertex_list().get_size();
                                        cout << "start vertex: ";
                                        cin >> start_vertex;

                                        cout << "end vertex: ";
                                        cin >> end_vertex;
                                        if ((start_vertex >= 0 && start_vertex < number_of_vertexes) &&
                                            (end_vertex >= 0 && end_vertex < number_of_vertexes)) {

                                            bellmanFord->bellmanFordIM(start_vertex, end_vertex, true);
                                        }
                                        delete bellmanFord;
                                        break;
                                    }
                                }
                            } while (representation = algorithm_representation_screen());
                            break;
                        }
                        case 9: {
                            //Delete Graph
                            Graph *graph = Graph::getInstance();

                            if (graph->get_edge_list().get_size() > 0) {
                                graph->delete_graph();
                            }
                        }
                    }
                } while (welcome_choice = welcome_screen());
                break;
            }
            case 2: { // TODO: Experimental mode
                float summary_time = 0;
                int choice = expertimental_screen();
                Graph *graph = Graph::getInstance();
                float unitFactor = 1000000000.0f;
                string string_unitFactor = " [ns]";
                int times = 0;
                cout << "How many times should time be measured: ";
                cin >> times;

                do {
                    switch (choice) {
                        case 0: {
                            mode_selection_screen();
                            break;
                        }
                        case 1: {


                            if (graph->get_edge_list().get_size() == 0) {
                                int representation = choose_graph_property_screen();

                                switch (representation) {
                                    case 0: {
                                        welcome_screen();
                                        break;
                                    }
                                    case 1: {
                                        // Directed Graph
                                        graph->set_is_directed(true);
                                        graph->generate_new_graph(graph->get_is_directed());
                                        graph->create_incidence_matrix();
                                        graph->create_adjacency_list();
                                        break;
                                    }

                                    case 2: {
                                        // Undirected Graph
                                        graph->set_is_directed(false);
                                        graph->generate_new_graph(graph->get_is_directed());
                                        graph->create_incidence_matrix();
                                        graph->create_adjacency_list();
                                        break;
                                    }
                                }
                            } else {
                                cout << "Delete graph to generate another !" << endl;
                            }
                            break;
                        }
                        case 2: {
                            graph->show_the_graph();
                            break;
                        }
                        case 3: {
                            // Prime experiment

                            int representation = algorithm_representation_screen();

                            do {
                                switch (representation) {
                                    //algorytm prima lista sąsiedztwa TEST
                                    case 1: {
                                        for (int i = 0; i < times; i++) {
                                            auto *prime = new Prime();
                                            auto *timer = new Timer();
                                            prime->primAL(0, false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete prime;
                                            delete timer;
                                        }

                                        cout << "Prim's (adjacency list) average time: " << summary_time / (float) times
                                             << string_unitFactor<<endl;
                                        summary_time = 0;
                                        break;
                                    }
                                    case 2: {
                                        //algorytm prima macierz incydencji TEST
                                        for (int i = 0; i < times; i++) {
                                            auto *prime = new Prime();
                                            auto *timer = new Timer();
                                            prime->primIM(0, false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete prime;
                                            delete timer;
                                        }
                                        cout << "Prim's (incidence matrix) average time: " << summary_time / (float) times
                                             << string_unitFactor << endl;
                                        summary_time = 0;

                                        break;
                                    }
                                }

                            } while (representation = algorithm_representation_screen());

                            break;

                        }
                        case 4: {
                            // TODO: Kruskal experiment

                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1:
                                    {
                                        for(int i=0;i<times; i++) {
                                            auto *kruskal = new Kruskal();
                                            auto *timer = new Timer();
                                            kruskal->kruskalAL(false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete timer;
                                            delete kruskal;

                                        }
                                        cout << "Kruskal's (adjacency list) average time: " << summary_time / (float) times
                                             << string_unitFactor << endl;
                                        summary_time = 0;

                                        break;
                                    }
                                    case 2:
                                    {
                                        for(int i=0;i<times; i++) {
                                            auto *kruskal = new Kruskal();
                                            auto *timer = new Timer();
                                            kruskal->kruskalIM(false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete timer;
                                            delete kruskal;
                                        }
                                        cout << "Kruskal's (incidence matrix) average time: " << summary_time / (float) times
                                             << string_unitFactor << endl;
                                        summary_time = 0;

                                        break;
                                    }
                                }
                            }while (representation = algorithm_representation_screen());

                            break;
                        }
                        case 5: {

                            int end_vertex = graph->get_vertex_list().get_size()-1;

                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1: {
                                        for(int i=0;i<times; i++) {
                                            auto *djikstra = new Djikstra();
                                            auto *timer = new Timer();
                                            djikstra->djikstra_adjacency_list(0, end_vertex, false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete djikstra;
                                            delete timer;
                                        }
                                        cout << "Djikstra (adjacency list) average time: " << summary_time / (float) times
                                             << string_unitFactor << endl;
                                        summary_time = 0;

                                        break;
                                    }
                                    case 2: {

                                        for(int i=0;i<times; i++) {
                                            auto *djikstra = new Djikstra();
                                            auto *timer = new Timer();
                                            djikstra->djikstra_incidence_matrix(0, end_vertex, false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete djikstra;
                                            delete timer;
                                        }
                                        cout << "Djikstra (incidence matrix) average time: " << summary_time / (float) times
                                             << string_unitFactor << endl;
                                        summary_time = 0;
                                        break;
                                    }
                                }
                            }while (representation = algorithm_representation_screen());

                            break;
                        }
                        case 6: {
                            // TODO: Bellman ford experiment
                            int end_vertex = graph->get_vertex_list().get_size()/2;

                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1: {
                                        for (int i = 0; i < times; i++) {
                                            auto *bellmanFord = new BellmanFord();
                                            auto *timer = new Timer();
                                            bellmanFord->bellmanFordAL(0, end_vertex, false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete bellmanFord;
                                            delete timer;
                                        }
                                        cout << "Bellman Ford (adjacency list) average time: " << summary_time / (float) times
                                             << string_unitFactor << endl;
                                        summary_time = 0;
                                        break;
                                    }

                                    case 2:
                                    {
                                        for (int i = 0; i < times; i++) {
                                            auto *bellmanFord = new BellmanFord();
                                            auto *timer = new Timer();
                                            bellmanFord->bellmanFordIM(0, end_vertex, false);
                                            summary_time = summary_time + timer->getTime().count() * unitFactor;

                                            delete bellmanFord;
                                            delete timer;
                                        }
                                        cout << "Bellman Ford (incidence matrix) average time: " << summary_time / (float) times
                                             << string_unitFactor << endl;
                                        summary_time = 0;
                                        break;
                                    }
                                }
                            }while (representation = algorithm_representation_screen());

                            break;
                        }
                        case 7: {
                            if (graph->get_edge_list().get_size() > 0) {
                                graph->delete_graph();
                            }
                            break;
                        }

                    }
                } while (choice = expertimental_screen());

                break;
            }
        }
    } while (mode = mode_selection_screen());
}
