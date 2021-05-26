//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include <iostream>
#include "Menu.h"


using namespace std;


Menu::Menu() {

}

void Menu::main_screen(){
    int welcome_choice = welcome_screen();
   do {
       switch (welcome_choice) {
           case 0: {
               exit(1);
           }
           case 1: {
               //TODO wczytaj graf z pliku
               break;
           }
           case 2: {
               //TODO wygeneruj losowy graf
               break;
           }
           case 3: {
               //TODO wyświetl graf w postaci listy sąsiedztwa
               break;
           }
           case 4: {
               //TODO wyświetl graf w postaci macierzy incydencji
               break;
           }
           case 5: {
               //TODO wykonywanie algorytmów na grafie
               break;
           }

       }
   } while(welcome_choice = welcome_screen());

}

int Menu::select_option(int upper_bounds) {
    int choice;
    do{
    cout << "Wybierz opcje : ";
    cin >> choice;
    }while(!(choice >= 0 && choice <= upper_bounds));

    return choice;
}

int Menu::algorithm_selection_screen() {
    cout << "1. Algorytm Prima (listowo)" << endl;
    cout << "2. Algorytm Prima (macierzowo)" << endl;
    cout << "3. Algorytm Kruskala (listowo)" << endl;
    cout << "4. Algorytm Kruskala (macierzowo)" << endl;
    cout << "5. Algorytm Djiksry (listowo)" << endl;
    cout << "6. Algorytm Djiksry (macierzowo)" << endl;
    cout << "7. Algorytm Bellmana-Forda (listowo)" << endl;
    cout << "8. Algorytm Bellmana-Forda (macierzowo)" << endl;
    cout << "Press 0 to return" << endl;
    return select_option(8);
}

int Menu::welcome_screen() {
    cout<<endl;
    cout<<" ------------------ Menu ---------------------- "<<endl;
    cout << "1. Wczytaj graf z pliku   " << endl;
    cout << "2. Wygeneruj graf losowo  " << endl;
    cout << "3. Wyświetl graf w postacji listy sąsiedztwa" << endl;
    cout << "4. Wyświetl graf w postacji macierzy incydencji" << endl;
    cout << "5. Algorytmy" << endl;
    cout<<endl;
    cout << "Press 0 to exit           " << endl;
    cout<<"----------------------------------------------- "<<endl;
   return select_option(5);
}





