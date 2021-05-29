//
// Created by Kamil Bonkowski on 25/05/2021.
//
#include "ArrayList.h"
#include <iostream>

using namespace std;

template <class T>
ArrayList<T>::ArrayList() {
    size = 0;
    array = nullptr;
}

//template <class T>
//ArrayList<T>::~ArrayList() {
//    delete [] array;
//    array = nullptr;
//    size = 0;
//}

template <class T>
void ArrayList<T>::addFirst(T data) {
    size++;
    //adding to empty array
    if (array == nullptr || size == 1) {
        array = new T[size];
        array[0] = data;
    }
        //adding to not empty array
    else {
        T *tmp = new T[size];
        tmp[0] = data;
        for (int i = 1; i < size; i++)
            tmp[i] = array[i - 1];
        delete array;
        array = tmp;
    }
}
template <class T>
void ArrayList<T>::addLast(T data) {
    //adding to empty array
    if (array == nullptr || size == 0)
        addFirst(data);
        //adding to not array
    else {
        T *tmp = new T[size + 1];
        for (int i = 0; i < size; i++)
            tmp[i] = array[i];
        tmp[size] = data;
        size++;
        delete array;
        array = tmp;
    }
}

template <class T>
void ArrayList<T>::add(T data, int index) {
    //incorrect index
    if (index < 0 || index > size)
        cout << "Incorrect index while adding." << endl;
        //adding at the beginning
    else if (array == nullptr || index == 0)
        addFirst(data);
        //adding at the end
    else if (index == size)
        addLast(data);
    else {
        size++;
        T *tmp = new T[size];
        tmp[index] = data;
        //part before index
        for (int i = 0; i < index; i++)
            tmp[i] = array[i];
        //part after index
        for (int i = index + 1; i < size; i++)
            tmp[i] = array[i - 1];
        delete array;
        array = tmp;
    }
}

template <class T>
bool ArrayList<T>::contains(T data) {
    int *tmp = array;
    for (int i = 0; i < size; i++)
        if (tmp[i] == data)
            return true;
    return false;
}

template <class T>
void ArrayList<T>::removeFirst() {
    //empty array
    if (size == 0 || array == nullptr)
        cout << "Array is empty" << endl;
        //list contains only one element
    else if (size == 1) {
        size--;
        delete[] array;
        array = nullptr;
    }
        //list contains more than one element
    else {
        size--;
        T *tmp = new T[size];
        for (int i = 1; i < size + 1; i++)
            tmp[i - 1] = array[i];
        delete[]array;
        array = tmp;
    }
}

template <class T>
void ArrayList<T>::removeLast() {
    //array is empty or contains one element
    if (size < 2)
        removeFirst();
        //array contains more than one element
    else {
        size--;
        T *tmp = new T[size];
        for (int i = 0; i < size; i++)
            tmp[i] = array[i];
        delete array;
        array = tmp;
    }
}

template <class T>
void ArrayList<T>::remove(int index) {
    //incorrect index
    if (index < 0 || index >= size)
        cout << "Incorrect index while deleting" << endl;
        //remove the first element
    else if (array == nullptr || index == 0)
        removeFirst();
        //remove the last element
    else if (index == size - 1)
        removeLast();
    else {
        size--;
        T *tmp = new T[size];
        //part before index
        for (int i = 0; i < index; i++)
            tmp[i] = array[i];
        //part after index
        for (int i = index + 1; i < size + 1; i++)
            tmp[i - 1] = array[i];
        delete[] array;
        array = tmp;
    }
}

template <class T>
T ArrayList<T>::get(int index){
    if(index >= 0 && index < size) {
        return array[index];
    }
    else {
        cout<<"Index out of bounds"<<endl;
    }
}

template <class T>
int ArrayList<T>::get_size(){
    return size;
}

template <class T>
void ArrayList<T>::show() {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

template <class T>
void ArrayList<T>::removeAll() {
    while (size > 0)
        removeFirst();
}

template <class T>
void ArrayList<T>::setArray(T *tmp) {
    ArrayList<T>::array = tmp;
}

template <class T>
ArrayList<T>::ArrayList(T *tmp, int size) {
    this->array = new T[size];
    for (int i = 0; i < size; i++) {
        array[i] = tmp[i];
    }
    this->size = size;
}
