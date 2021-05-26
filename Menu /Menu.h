//
// Created by Kamil Bonkowski on 25/05/2021.
//

#ifndef ALGORITHMS_TIME_ANALYSIS_MENU_H
#define ALGORITHMS_TIME_ANALYSIS_MENU_H


class Menu {
public:
    Menu();
    int welcome_screen();
    int algorithm_selection_screen();
    int select_option(int upper_bounds);
    void main_screen();
};


#endif //ALGORITHMS_TIME_ANALYSIS_MENU_H
