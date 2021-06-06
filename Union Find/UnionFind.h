#include "../Data Structures/Priority Queue/Queue.cpp"

struct UnionNode{
    int up;
    int rank;
};

class UnionFind{
private:
    UnionNode *set;
    int numOfVer;
public:
    UnionFind(int n);
    ~UnionFind();
    void makeSet(int v);
    int findSet(int v);
    bool isOneSet();
    void printSet();
    void unionSets(Edge_Element edge);
};
