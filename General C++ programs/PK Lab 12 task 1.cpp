#include<iostream>
#include<limits>

using namespace std;

const int NumVertices = 6;
const int MaxValue = numeric_limits<int>::max();

int findMinimumDistance(int distance[], bool visited[]) {
    int minKey = MaxValue;
    int minIndex = -1;

    for (int v = 0; v < NumVertices; ++v) {
        if (!visited[v] && distance[v] < minKey) {
            minKey = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << j << " ";
}

void printSolution(int distance[], int parent[], int source, int destination) {
    cout << "Shortest Path from " << source << " to " << destination << " with distance " << distance[destination] << " : ";
    printPath(parent, destination);
    cout << endl;
}

void dijkstra(int graph[NumVertices][NumVertices], int source, int destination) {
    int distance[NumVertices];
    bool visited[NumVertices];
    int parent[NumVertices];

    for (int i = 0; i < NumVertices; ++i) {
        distance[i] = MaxValue;
        visited[i] = false;
        parent[i] = -1;
    }
    distance[source] = 0;

    for (int count = 0; count < NumVertices - 1; ++count) {
        int u = findMinimumDistance(distance, visited);
        visited[u] = true;

        for (int v = 0; v < NumVertices; ++v) {
            if (!visited[v] && graph[u][v] && distance[u] != MaxValue) {
                if (distance[u] + graph[u][v] < distance[v]) {
                    parent[v] = u;
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }
    printSolution(distance, parent, source, destination);
}

int main() {
    int weightGraph[NumVertices][NumVertices] = {
        {0, 1, 0, 5, 0, 0},
        {0, 0, 2, 2, 1, 0},
        {0, 0, 0, 0, 3, 1},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0}
    };

    int sourceNode = 0;
    int destinationNode = 5;

    dijkstra(weightGraph, sourceNode, destinationNode);

    return 0;
}

