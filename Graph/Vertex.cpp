//
// Created by Kamil Bonkowski on 25/05/2021.
//
#include "Vertex.h"

Vertex::Vertex() = default;

Vertex::Vertex(int id) {
    this->id = id;
}

int Vertex::get_id() const  {
    return id;
}

