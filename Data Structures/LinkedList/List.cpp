//
// Created by Kamil Bonkowski on 25/05/2021.
//

#include <iostream>
#include "List.h"

using namespace std;

template <class T>
List<T>::List() {
    size = 0;
    first = last = nullptr;
}

template <class T>
Element<T> *List<T>::getPosition(int position) const {
    if (position < 0 || position > size)
        return nullptr;

    else if (position >= size / 2) {
        Element<T> *tmp = last;
        for (int i = size - 1; i > position; i--)
            tmp = tmp->getPrevious();

        return tmp;
    } else {
        Element<T> *tmp = first;
        for (int i = 0; i < position; i++)
            tmp = tmp->getNext();

        return tmp;
    }
}

template <class T>
void List<T>::add(T data, int index) {
    //incorrect index
    if (index < 0 || index > size)
        cout << "incorrect index" << endl;
        //adding to empty list or adding at the beginning
    else if (first == nullptr || index == 0)
        addFirst(data);
        //adding at the end
    else if (index == size)
        addLast(data);

        //adding in the middle
    else {
        auto *element = new Element<T>(data);
        Element<T> *tmp = getPosition(index);
        Element<T> *before = getPosition(index - 1);
        before->setNext(element);
        element->setPrevious(before);
        tmp->setPrevious(element);
        element->setNext(tmp);

        size++;
    }
}
template <class T>
void List<T>::addFirst(T data) {
    auto *element = new Element<T>(data);
    if (first == nullptr) {
        setFirst(element);
        setLast(element);
    } else {
        first->setPrevious(element);
        element->setNext(first);
        setFirst(element);
    }
    size++;
}
template <class T>
void List<T>::addLast(T data) {
    if (last != nullptr) {
        auto *element = new Element<T>(data);
        last->setNext(element);
        element->setPrevious(this->last);
        setLast(element);
        size++;
    } else addFirst(data);

}
template <class T>
void List<T>::setFirst(Element<T> *first) {
    List::first = first;
    first->setPrevious(nullptr);
}

template <class T>
void List<T>::setLast(Element<T> *last) {
    List::last = last;
    last->setNext(nullptr);
}

template <class T>
T List<T>::get(int index) {
    auto *tmp = first;

    for(int i = 0;i<index;i++){
        tmp = tmp->getNext();
    }
    return tmp->getData();
}

template <class T>
void List<T>::remove(int index) {
    //empty list
    if (first == nullptr && last == nullptr)
        cout << "List is empty" << endl;

        //incorrect index
    else if (index < 0 || index >= size)
        cout << "Incorrect deleting index" << endl;

        //removing one left value from list
    else if (size == 1 || index == 0)
        removeFirst();

        //removing last
    else if (index == size - 1)
        removeLast();

        //removing from the middle
    else {
        auto *tmp = getPosition(index);
        tmp->getPrevious()->setNext(tmp->getNext());
        tmp->getNext()->setPrevious(tmp->getPrevious());
        delete tmp;
        size--;
    }
}

template <class T>
void List<T>::removeAll() {
    while (size > 0) {
        remove(size - 1);
    }
}

template <class T>
void List<T>::removeFirst() {
    if (first == nullptr && last == nullptr) {
        cout << "List is empty" << endl;
        return;
    } else if (first->getNext() == nullptr) {
        delete first;
        first = last = nullptr;
    } else {
        Element<T> *tmp = first;
        setFirst(first->getNext());
        first->setPrevious(nullptr);
        delete tmp;
    }
    size--;
}

template <class T>
void List<T>::removeLast() {
    if (first == nullptr && last == nullptr) {
        cout << "Lista pusta!" << endl;
        return;
    } else if (last->getPrevious() == nullptr)
        removeFirst();
    else {
        Element<T> *tmp = last;
        last->getPrevious()->setNext(nullptr);
        last = last->getPrevious();
        delete tmp;
    }
    size--;
}

template <class T>
bool List<T>::contains(T data) {
    Element<T> *tmp = first;
    while (tmp != nullptr) {
        if (tmp->getData() == data)
            return true;
        tmp = tmp->getNext();
    }
    return false;
}
template <class T>
int List<T>::get_size(){
    return size;
}




