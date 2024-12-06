#include <stdlib.h>
#include <limits.h>
#include "kruskals.h"

void initialize_matrix(AdjacencyMatrix* matrix, int vertices) {
    matrix->vertices = vertices;
    matrix->matrix = (int**)malloc(sizeof(int*) * vertices);
    for (int i = 0; i < vertices; i++) {
        matrix->matrix[i] = (int*)malloc(sizeof(int) * vertices);
        for (int j = 0; j < vertices; j++) {
            matrix->matrix[i][j] = INT_MAX;
        }
    }
}

void add_edge(AdjacencyMatrix* matrix, Edge edge) {
    if (edge.u < matrix->vertices && edge.v < matrix->vertices) {
        matrix->matrix[edge.u][edge.v] = edge.weight;
        matrix->matrix[edge.v][edge.u] = edge.weight;
    }
}

Node* sort_edges(AdjacencyMatrix matrix) {
    Node* head = NULL;
    Node** current;
    for (int u = 0; u < matrix.vertices; u++) {
        for (int v = u + 1; v < matrix.vertices; v++) {
            if (matrix.matrix[u][v] != INT_MAX) {
                Node* node = (Node*)malloc(sizeof(Node));
                node->edge.u = u;
                node->edge.v = v;
                node->edge.weight = matrix.matrix[u][v];
                for (current = &head; *current != NULL && (*current)->edge.weight < node->edge.weight; current = &(*current)->next);
                node->next = *current;
                *current = node;
            }
        }
    }
    return head;
}

// Given the index of a vertex, find its representative vertex of the disjoint set it belongs to
int find_representative(int parent[], int index) {
    if (parent[index] == index) return index;
    return find_representative(parent, parent[index]);
}

// Given the indices of two vertex, merge the disjoint sets each belongs to
void merge_set(int parent[], int index1, int index2) {
    int i = find_representative(parent, index2);
    parent[i] = index1;
}

MinimumSpanningTree* kruskals(AdjacencyMatrix matrix) {
    // Initialize the resulting tree
    MinimumSpanningTree* tree = (MinimumSpanningTree*)malloc(sizeof(MinimumSpanningTree));
    tree->head = NULL;
    tree->weight = 0;

    // Initialize all vertices to be disjoint sets by setting its parent to be itself
    int parent[matrix.vertices];
    for (int i = 0; i < matrix.vertices; i++) {
        parent[i] = i;
    }

    // Create a linked list of edges arranged in ascending order based on their weights
    Node* current = sort_edges(matrix);

    // Iterate until one less than the total number of vertices have been added
    for (int i = 1; i < matrix.vertices; current = current->next) {
        // If the vertices of the current edge do not belong to the same set
        if (find_representative(parent, current->edge.u) != find_representative(parent, current->edge.v)) {
            // Merge the two disjoint sets each vertices belong to
            merge_set(parent, current->edge.u, current->edge.v);

            // Record the weight of the current edge
            tree->weight += current->edge.weight;

            // Make a new node from the current edge and add it to the list of edges of the tree
            Node* node = (Node*)malloc(sizeof(Node));
            node->edge = current->edge;
            node->next = tree->head;
            tree->head = node;

            // Increment the number of vertices added
            i++;
        }
    }

    return tree;
}