#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "dijkstra.h"

void dijkstra(Graph* graph, int source) {
    graph->source = source;

    // Define distance of all vertices to maximum integer value.
    bool visited[graph->order];
    for (int i = 0; i < graph->order; i++) {
        graph->distance[i] = INT_MAX;
        visited[i] = false;
    }

    // Define distance of source vertex to zero.
    graph->distance[source] = 0;

    // Repeat by the number of vertices in the graph minus one.
    // We can skip the last vertex, since it would have zero unvisited neighbors.
    // Hence, i = 1
    for (int i = 1; i < graph->order; i++) {
        int current = INT_MAX;
        int u;
        for (int j = 0; j < graph->order; j++) {
            if (visited[j] == false) {
                if (graph->distance[j] < current) {
                    current = graph->distance[j];
                    u = j;
                }
            }
        }
        visited[u] = true;

        for (int v = 0; v < graph->order; v++) {
            if (visited[v] == false && graph->matrix[u][v] != INT_MAX && graph->distance[u] + graph->matrix[u][v] < graph->distance[v]) {
                graph->distance[v] = graph->distance[u] + graph->matrix[u][v];
                graph->previous[v] = u;
            }
        }
    }
}

Graph* _initialize(int order) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->order = order;
    graph->distance = (int*)malloc(sizeof(int) * order);
    graph->previous = (int*)malloc(sizeof(int) * order);
    graph->matrix = (int**)malloc(sizeof(int*) * order);
    for (int i = 0; i < order; i++) {
        graph->matrix[i] = (int*)malloc(sizeof(int) * order);
        for (int j = 0; j < order; j++) {
            graph->matrix[i][j] = INT_MAX;
        }
    }
    return graph;
}

void _add_arc(Graph* graph, int tail, int head, int weight) {
    if (tail < graph->order && head < graph->order) {
        graph->matrix[tail][head] = weight;
    }
}

void _print_matrix(Graph* graph) {
    for (int i = 0; i < graph->order; i++) {
        for (int j = 0; j < graph->order; j++) {
            if (graph->matrix[i][j] == INT_MAX) {
                printf("-- ");
            }
            else {
                printf("%2d ", graph->matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void _print_output(Graph* graph) {
    for (int i = 0; i < graph->order; i++) {
        printf("%2d %2d %2d\n", i + 1, graph->distance[i], graph->previous[i] + 1);
    }
}