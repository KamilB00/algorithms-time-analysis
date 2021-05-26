//
// Created by Kamil Bonkowski on 25/05/2021.
//

#ifndef ALGORITHMS_TIME_ANALYSIS_VERTEX_H
#define ALGORITHMS_TIME_ANALYSIS_VERTEX_H


class Vertex {
private:
    int id;

public:
    Vertex();
    explicit Vertex(int id);

    int get_id() const;
};

#endif //ALGORITHMS_TIME_ANALYSIS_VERTEX_H
