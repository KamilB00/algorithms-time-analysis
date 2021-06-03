//
// Created by Kamil Bonkowski on 25/05/2021.
//
#include "Vertex.h"

inline Vertex::Vertex() = default;

inline Vertex::Vertex(int id) {
    this->id = id;
}

inline int Vertex::get_id() const {
    return id;
}

