#include<iostream>
#include<climits>

using namespace std;

class ShortestPath {
    int numVertices, numEdges;
    int* distances;

public:
    ShortestPath(int vertices, int edges) {
        numVertices = vertices;
        numEdges = edges;
        distances = new int[vertices];
    }

    void findShortestPath(int graph[50][3], int source) {
        for (int i = 0; i < numVertices; ++i) {
            distances[i] = INT_MAX;
        }
        distances[source] = 0;

        for (int i = 0; i < numVertices - 1; ++i) {
            for (int j = 0; j < numEdges; ++j) {
                int u = graph[j][0];
                int v = graph[j][1];
                int weight = graph[j][2];

                if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }

        for (int i = 0; i < numEdges; ++i) {
            int u = graph[i][0];
            int v = graph[i][1];
            int weight = graph[i][2];

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                cout << -1;
                return;
            }
        }

        for (int i = 0; i < numVertices; ++i) {
            if (distances[i] == INT_MAX) {
                cout << 10e8 << " ";
            } else {
                cout << distances[i] << " ";
            }
        }
    }
};

int main() {
    int vertices = 3;
    int edges = 4;

    int weightedGraph[50][3] = {{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};
    int source = 2;

    ShortestPath shortestPath(vertices, edges);
    shortestPath.findShortestPath(weightedGraph, source);

    return 0;
}

