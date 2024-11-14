#ifndef DIJKSTRA_H
#define DIJKSTRA_H

typedef struct {
    int** matrix;
    int order;
    int source;
    int* distance;
    int* previous;
} Graph;

void dijkstra(Graph* graph, int source);
Graph* _initialize(int order);
void _add_arc(Graph* graph, int tail, int head, int weight);
void _print_matrix(Graph* graph);
void _print_output(Graph* graph);

#endif