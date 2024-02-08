#include<iostream>
#include<limits>

using namespace std;

const int V = 6;
const int max_val = numeric_limits<int>::max();

int findMinDist(int dist[], bool visited[]) {
    int minkey = max_val;
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] < minkey) {
            minkey = dist[v];
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
    c(parent, dest);
    cout << endl;
}

void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; ++i) {
        dist[i] = max_val;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinDist(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != max_val && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, parent, src, dest);
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 5, 0, 0},
        {0, 0, 2, 2, 1, 0},
        {0, 0, 0, 0, 3, 1},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0}
    };

    int src = 0;
    int dest = 5; 

    dijkstra(graph, src, dest);

    return 0;
}

