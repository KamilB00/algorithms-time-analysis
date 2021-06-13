#include "UnionFind.h"
#include<iostream>

using namespace std;

inline UnionFind::UnionFind(int n){
    set = new UnionNode[n];
    this->numOfVer = n;
}

inline UnionFind::~UnionFind(){
    delete [] set;
}

inline void UnionFind::makeSet(int v){
    set[v].up = v;
    set[v].rank = 0;
}

inline int UnionFind::findSet(int v){
    if(set[v].up != v){
        set[v].up = findSet(set[v].up);
    }
    return set[v].up;
}

inline void UnionFind::unionSets(Edge_Element edge){
    int rootX, rootY;

    rootX = findSet(edge.start_vertex);
    rootY = findSet(edge.end_vertex);

    if(rootX != rootY){
        if(set[rootX].rank > set[rootY].rank){
            set[rootY].up = rootX;
        }
        else{
            set[rootX].up = rootY;
            if(set[rootX].rank == set[rootY].rank){
                set[rootY].rank++;
            }
        }
    }
}
