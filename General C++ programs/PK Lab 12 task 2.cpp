#include<iostream>

using namespace std;

class VertexNode {
public:
    int vertex;
    VertexNode* next;

    VertexNode(int v) {
        this->vertex = v;
        this->next = NULL;
    }
};

class AdjacencyList {
private:
    int totalVertices;
    VertexNode** vertices;

public:
    AdjacencyList(int totalVertices) {
        this->totalVertices = totalVertices;

        vertices = new VertexNode*[totalVertices];
        for (int i = 0; i < totalVertices; ++i) {
            vertices[i] = NULL;
        }
    }

    void addEdge(int source, int destination) {
        VertexNode* newNode = new VertexNode(destination);
        newNode->next = vertices[source];
        vertices[source] = newNode;

        newNode = new VertexNode(source);
        newNode->next = vertices[destination];
        vertices[destination] = newNode;
    }

    void displayAdjacencyList() {
        for (int i = 0; i < totalVertices; ++i) {
            cout << i << " ";
            VertexNode* current = vertices[i];
            while (current != NULL) {
                cout << current->vertex << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int totalVertices = 5;
    int totalEdges = 7;

    int edges[][2] = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};

    AdjacencyList graph(totalVertices);

    for (int i = 0; i < totalVertices; ++i) {
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    cout << endl;
    graph.displayAdjacencyList();

    return 0;
}

