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
    int root1, root2;

    root1 = findSet(edge.start_vertex);
    root2 = findSet(edge.end_vertex);

    if(root1 != root2){
        if(set[root1].rank > set[root2].rank){
            set[root2].up = root1;
        }
        else{
            set[root1].up = root2;
            if(set[root1].rank == set[root2].rank){
                set[root2].rank++;
            }
        }
    }
}

inline bool UnionFind::isOneSet(){
    int firstParent = findSet(0);

    for(int i = 1; i < this->numOfVer; i++){
        if(firstParent != findSet(i)) return false;
    }
    return true;
}

inline void UnionFind::printSet(){
    cout<<"Set: ";
    for(int i = 0; i < this->numOfVer; i++){
        cout<<findSet(i)<<" ";
    }
    cout<<endl;
}