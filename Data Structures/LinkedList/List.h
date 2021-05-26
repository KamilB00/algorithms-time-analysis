//
// Created by Kamil Bonkowski on 25/05/2021.
//

#ifndef ALGORITHMS_TIME_ANALYSIS_LIST_H
#define ALGORITHMS_TIME_ANALYSIS_LIST_H


#include "Element.h"
#include "Element.cpp"

template <class T>
class List {
private:
    int size;
    Element<T> *first;
    Element<T> *last;

    Element<T> *getPosition(int position) const;

    void setFirst(Element<T> *first);
    void setLast(Element<T> *last);


public:
    List();
    //~List();
    bool contains(T data);

    void add(T data, int index);

    void addFirst(T data);

    void addLast(T data);

    T get(int index);

    void removeAll();

    void remove(int index);

    void removeFirst();

    void removeLast();

    int get_size();
};



#endif //ALGORITHMS_TIME_ANALYSIS_LIST_H
