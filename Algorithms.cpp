#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#define INF numeric_limits<int>::max()
using namespace std;
#include "Algorithms.hpp"

bool isConnected(Graph g) {
    vector<bool> visited(g.adjMatrix.size(), false); 
    vector<int> adj;
    stack<int> stack;

    int start = 0;//the first node in the graph
    visited[start] = true; 
    stack.push(start); 

    while (!stack.empty()) {
        int v = stack.top(); 
        stack.pop(); 

        for(int i = 0; i< g.adjMatrix.size(); i++)
        {
            if(g.adjMatrix[v][i] != 0)
                adj.push_back(i);
        }
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true; // Mark the adjacent vertex as visited
                stack.push(u); // Push it onto the stack
            }
        }
    }

    if(visited[g.adjMatrix.size() - 1] == false)//the algorithm haven't gone over all the vertices
        return false;
    else
        return true;

};



vector<int> shortestPath(Graph g, int start, int end) {
    int u, whole_size = g.adjMatrix.size() * g.adjMatrix.size();
    vector<int> dist(whole_size, INF);
    vector<int> pred(whole_size, -1);  
    vector<bool> visited(whole_size, false);

    dist[start] = 0;

    for (int i = 0; i < whole_size - 1; ++i) {
        u = -1;
        for (int j = 0; j < whole_size; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) {
            break;
        }

        visited[u] = true;
        for (int v = 0; v < size; ++v) {
            if (!visited[v] && g.adjMatrix[u][v] && dist[u] != INF && dist[u] + g.adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g.adjMatrix[u][v];
                pred[v] = u;  
        }
    }

    vector<int> path;
    for (int node = end; node != -1; node = pred[node]) {
        path.push_back(node);
    }
    if(path.empty)
    {
        return -1;
    }
    reverse(path.begin(), path.end());  

    for(int i = 0; i< path.size() - 1; i++)
        cout << path[i] << " -> ";
    
    cout << path[path.size() - 1] << endl;
    return path;
  }

}

vector<int> isContainsCycle(Graph g) {
    int whole_size = g.adjMatrix.size() * g.adjMatrix.size();
    vector<bool> visited(whole_size, false);
    queue<int> q; 
    vector<int> paths(whole_size);
    for (int startVertex = 0; startVertex < g.adjMatrix.size(); ++startVertex) {
        if (!visited[startVertex]) {
            visited[startVertex] = true;
            q.push(startVertex);
            paths[startVertex].push_back(startVertex);

            while (!q.empty()) {
                int vertex = q.front();
                q.pop();

                for (int v = 0; v < g.adjMatrix.size(); ++v) {
                    if (g.adjMatrix[vertex][v] && !visited[v]) {
                        visited[v] = true;
                        q.push(v);
                        paths[v] = paths[vertex]; 
                        paths[v].push_back(v); 
                    } else if (visited[v] && find(paths[vertex].begin(), paths[vertex].end(), v) != paths[vertex].end()) {
                        vector<int> cycle(paths[vertex].begin() + distance(paths[vertex].begin(), find(paths[vertex].begin(), paths[vertex].end(), v)), paths[vertex].end());
                        cout << "the cycle is " << cycle;
                        return cycle;
                    }
                }
            }
        }
    }
    cout << "0 (false)" << endl;
    return {0}; 

}

vector<int> isBipartite(Graph g) {
    int size = g.adjMatrix.size();
    vector<int> color(size, -1); 
    queue<int> q;
    vector<int> bipartition1, bipartition2;

    for (int startVertex = 0; startVertex < size; ++startVertex) {
        if (color[startVertex] == -1) { 
            color[startVertex] = 0; 
            bipartition1.push_back(startVertex); 
            q.push(startVertex);

            while (!q.empty()) {
                int vertex = q.front();
                q.pop();

                for (int adjacentVertex = 0; adjacentVertex < size; ++adjacentVertex) {
                    if (g.adjMatrix[vertex][adjacentVertex] != 0) { 
                        if (color[adjacentVertex] == -1) { 
                            color[adjacentVertex] = 1 - color[vertex]; 
                            if (color[adjacentVertex] == 0)
                                bipartition1.push_back(adjacentVertex);
                            else
                                bipartition2.push_back(adjacentVertex);
                            q.push(adjacentVertex);
                        } else if (color[adjacentVertex] == color[vertex]) {
                            return {0}; 
                        }
                    }
                }
            }
        }
    }

    vector<int> result;

    cout <<"A = {";
    for (int vertex : bipartition1){
        cout << vertex << ", ";
        result.push_back(vertex);
    }
    cout << "}, B = {";

    result.push_back(-1); // to seperate them


    for (int vertex : bipartition2) {
        cout << vertex << ", "
        result.push_back(vertex);
    }
    cout << "}." << endl;
    return result;
}




vector<int> negativeCycle(Graph g) {
    int size = g.adjMatrix.size();
    vector<int> dist(size, INF);
    vector<int> pred(size, -1);

    for (int startVertex = 0; startVertex < size; ++startVertex) {
        dist[startVertex] = 0;

        // Relax the edges
        for (int i = 0; i < size - 1; ++i) {
            for (int u = 0; u < size; ++u) {
                for (int v = 0; v < size; ++v) {
                    if (g.adjMatrix[u][v] != 0 && dist[u] != INF && dist[u] + g.adjMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + g.adjMatrix[u][v];
                        pred[v] = u;
                    }
                }
            }
        }

       
        for (int u = 0; u < size; ++u) {
            for (int v = 0; v < size; ++v) {
                if (g.adjMatrix[u][v] != 0 && dist[u] != INF && dist[u] + g.adjMatrix[u][v] < dist[v]) {
                    vector<int> cycle;
                    int cur = v;
                    do {
                        cycle.push_back(cur);
                        cur = pred[cur];
                    } while (cur != v);

                    return cycle;
                }
            }
        }
    }

    cout << "there are no negative cycles here" << endl;
    return {0};
}





