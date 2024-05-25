#include <iostream>
using namespace std;
#include "Graph.hpp"

void Graph::loadGraph(int* matrix) {
  adjMatrix = new int[matrix.size()][matrix.size()];
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix.size(); ++j) {
        adjMatrix[i][j] = matrix[i][j];
  }
}

void Graph::printGraph() {
  int countEdges = 0;
  
  for(int i = 0; i < g.adjMatrix.size(); i++) 
  {
    for(int j = 0; j < g.adjMatrix.size(); j++) 
    {
      if(g.adjMatrix[i][j] != 0)
        countEdges++;
    }
  }

  cout << "the number of vertices is " << g.adjMatrix.size() << endl;
  cout << "the number of edges is " << countEdges << endl;

}

friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (const auto& row : graph.adjMatrix) {
            for (int value : row) {
                os << value << " ";
            }
            os << std::endl;
        }
        return os;
    }
};