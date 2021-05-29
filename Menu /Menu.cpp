//
// Created by Kamil Bonkowski on 25/05/2021.
//


#include <iostream>
#include "../../algorithms-time-analysis/Graph/Graph.cpp"
#include "Menu.h"


using namespace std;

inline int Menu::algorithm_representation_screen() {
    cout << "--- Solve problem using: ---" << endl;
    cout << "1. adjacency list" << endl;
    cout << "2. incidence matrix" << endl;
    cout << endl;
    cout << "Press 0 to return" << endl;
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
    cout << endl;
    cout << "Press 0 to return           " << endl;
    cout << "----------------------------------------------- " << endl;
    return select_option(8);
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
                            //TODO wczytaj graf z pliku

                            Graph *graph = Graph::getInstance();
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
                            //TODO wygeneruj losowy graf
                            break;
                        }
                        case 3: {
                            //TODO wyświetl graf w postaci listy sąsiedztwa
                            Graph *graph = Graph::getInstance();
                            graph->show_adjacency_list();
                            break;
                        }
                        case 4: {
                            //TODO wyświetl graf w postaci macierzy incydencji
                            Graph *graph = Graph::getInstance();
                            graph->show_incidence_matrix();
                            break;
                        }
                        case 5: {
                            //PRIME'S ALGORITHM
                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1: {
                                        //TODO: Prime as a list
                                        cout << "Prime as a list" << endl;
                                        break;
                                    }
                                    case 2: {
                                        //TODO: Prime as a matrix
                                        cout << "Prime as a matrix" << endl;
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
                                        //TODO: Kruskal as a list
                                        cout << "Kruskal as a list" << endl;
                                        break;
                                    }
                                    case 2: {
                                        //TODO: Kruskal as a matrix
                                        cout << "Kruskal as a matrix" << endl;
                                        break;
                                    }
                                }
                            } while (representation = algorithm_representation_screen());
                            break;
                        }
                        case 7: {
                            //DJIKSTRA ALGORITHM
                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1: {
                                        //TODO: Djikstra as a list
                                        cout << "Djikstra as a list" << endl;
                                        break;
                                    }
                                    case 2: {
                                        //TODO: Djikstra as a matrix
                                        cout << "Djikstra as a matrix" << endl;
                                        break;
                                    }
                                }
                            } while (representation = algorithm_representation_screen());
                            break;
                        }
                        case 8: {
                            //BELLMAN-FORD ALGORITHM
                            int representation = algorithm_representation_screen();
                            do {
                                switch (representation) {
                                    case 1: {
                                        //TODO: Bellman-Ford as a list
                                        cout << "Bellman-Ford as a list" << endl;
                                        break;
                                    }
                                    case 2: {
                                        //TODO: Bellman-Ford as a matrix
                                        cout << "Bellman-Ford as a matrix" << endl;
                                        break;
                                    }
                                }
                            } while (representation = algorithm_representation_screen());
                            break;
                        }
                    }
                } while (welcome_choice = welcome_screen());
                break;
            }
            case 2: { //Experimental mode

                //TODO:Experimental mode
                cout << "THIS IS Experimental MODE" << endl;

                break;
            }
        }
    } while (mode = mode_selection_screen());
}
