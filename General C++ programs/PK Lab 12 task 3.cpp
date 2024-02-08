#include<iostream>

using namespace std;

const int NumVertices = 3;
const int MaxValue = 1e9;

int minIndex;

int findMinimumKey(int key[], bool visited[]) {
    int minKey = MaxValue;
    minIndex = -1;

    for (int vertex = 0; vertex < NumVertices; ++vertex) {
        if (!visited[vertex] && key[vertex] < minKey) {
            minKey = key[vertex];
            minIndex = vertex;
        }
    }
    return minIndex;
}

int printMinimumSpanningTree(int parent[], int graph[NumVertices][NumVertices]) {
    int totalWeight = 0;
    for (int i = 1; i < NumVertices; ++i) {
        cout << "Edge " << parent[i] << " - " << i << " Weight " << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << endl;
    return totalWeight;
}

void primMinimumSpanningTree(int graph[NumVertices][NumVertices]) {
    int parent[NumVertices];
    int key[NumVertices];
    bool visited[NumVertices];

    for (int i = 0; i < NumVertices; ++i) {
        key[i] = MaxValue;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < NumVertices - 1; ++count) {
        int u = findMinimumKey(key, visited);
        visited[u] = true;

        for (int v = 0; v < NumVertices; ++v) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int totalWeight = printMinimumSpanningTree(parent, graph);
}

int main() {
    int weightedGraph[NumVertices][NumVertices] = {
        {0, 1, 5},
        {1, 0, 3},
        {5, 3, 0}
    };

    primMinimumSpanningTree(weightedGraph);

    return 0;
}

