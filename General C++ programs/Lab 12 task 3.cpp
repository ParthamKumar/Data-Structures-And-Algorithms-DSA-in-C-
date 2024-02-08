#include<iostream>
using namespace std;

const int V = 3;
const int max_val = 1e9; 

int minIndex;	

int findMinDist(int key[], bool visited[]) {
    int minkey = max_val;
    minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && key[v] < minkey) {
            minkey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int printMST(int parent[], int graph[V][V]) {
    int totalCount = 0;
    for (int i = 1; i < V; ++i) {
        cout << "Edge " << parent[i] << " - " << i << " Weight " << graph[i][parent[i]] << endl;
        totalCount += graph[i][parent[i]];
    }
    cout << "Total Weight of Minimum Spanning Tree: " << totalCount << endl;
    return totalCount;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool visited[V];

    for (int i = 0; i < V; ++i) {
        key[i] = max_val;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinDist(key, visited);
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int totalWeight = printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 1, 5},
        {1, 0, 3},
        {5, 3, 0}
    };

    primMST(graph);

    return 0;
}

