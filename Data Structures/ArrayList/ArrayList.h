//
// Created by Kamil Bonkowski on 25/05/2021.
//

#ifndef ALGORITHMS_TIME_ANALYSIS_ARRAYLIST_H
#define ALGORITHMS_TIME_ANALYSIS_ARRAYLIST_H


template <class T>

class ArrayList {
private:
    //size of the array
    int size{};
    //dynamic-sized array
    T * array;
public:

    ArrayList<T>();

    ArrayList<T>(T *tmp, int size);

    virtual ~ArrayList();

    void addFirst(T data);

    void addLast(T data);

    void add(T data, int index);

    bool contains(T data);

    void removeFirst();

    void removeLast();

    void remove(int index);

    void removeAll();

    void show();

    void setArray(T *tmp);

    T get(int index);
};



#endif //ALGORITHMS_TIME_ANALYSIS_ARRAYLIST_H
