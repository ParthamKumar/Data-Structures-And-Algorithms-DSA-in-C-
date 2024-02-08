#include <iostream>
#include <limits>

using namespace std;

const int V = 6; // Number of vertices
const int INF = numeric_limits<int>::max(); // A large constant value to represent infinity

int findMinKey(int key[], bool mstSet[]) {
    int minKey = INF, minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
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

void printSolution(int dist[], int parent[], int src, int dest) {
    cout << "Shortest Path from " << src << " to " << dest << " with distance " << dist[dest] << " : ";
    printPath(parent, dest);
    cout << endl;
}

void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];
    int parent[V];
    bool mstSet[V];

    for (int i = 0; i < V; ++i) {
        dist[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(dist, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!mstSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, parent, src, dest);
}

int main() {
    int graph[V][V] = {
        {0,1,0,5,0,0},
        {0,0,2,2,1,0},
        {0,0,0,0,3,1},
        {0,0,0,0,2,0},
        {0,0,0,0,0,2},
        {0,0,0,0,0,0}
    };

    int src = 0; // Starting node (1-based index)
    int dest = 2	; // Ending node (1-based index)

    dijkstra(graph, src, dest);

    return 0;
}

