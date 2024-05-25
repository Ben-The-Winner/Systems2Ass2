#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjMatrix;
public:
    void loadGraph(vector<vector<int>>);
    void printGraph();
    friend std::ostream& operator<<(std::ostream&, const Graph&)
};

#endif
