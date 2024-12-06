#ifndef KRUSKALS_H
#define KRUSKALS_H

#include <stdbool.h>

typedef struct {
    int** matrix;
    int vertices;
    bool labeled;
} AdjacencyMatrix;

typedef struct {
    int u;
    int v;
    int weight; // If unweighted, -1.
} Edge;

typedef struct node {
    Edge edge;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int weight;
} MinimumSpanningTree;

void initialize_matrix(AdjacencyMatrix* matrix, int vertices);
void add_edge(AdjacencyMatrix* matrix, Edge edge);
Node* sort_edges(AdjacencyMatrix matrix);
MinimumSpanningTree* kruskals(AdjacencyMatrix matrix);
int find_representative(int parent[], int index);
void merge_set(int parent[], int index1, int index2);

#endif