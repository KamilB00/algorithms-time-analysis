//
// Created by Kamil Bonkowski on 25/05/2021.
//

#ifndef ALGORITHMS_TIME_ANALYSIS_ELEMENT_H
#define ALGORITHMS_TIME_ANALYSIS_ELEMENT_H


template <class T>
class Element {

private:
    T data;
    Element<T> *next;
    Element<T> *previous;
public:
    explicit Element<T>(T& data);

    Element<T> *getNext() const;

    void setNext(Element *next);

    Element<T> *getPrevious() const;

    void setPrevious(Element *previous);

    T getData();
};


#endif //ALGORITHMS_TIME_ANALYSIS_ELEMENT_H
