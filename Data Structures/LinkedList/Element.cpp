//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include "Element.h"

template<class T>
Element<T>::Element(T& data) : next(nullptr),data(data), previous(nullptr){}

template<class T>
Element<T> *Element<T>::getNext() const {
    return next;
}

template<class T>
void Element<T>::setNext(Element *next) {
    this->next = next;
}

template<class T>
Element<T> *Element<T>::getPrevious() const {
    return previous;
}

template<class T>
void Element<T>::setPrevious(Element *previous) {
    this->previous = previous;
}

template<class T>
T Element<T>::getData(){
    return data;
}
