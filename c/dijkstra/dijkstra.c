#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "dijkstra.h"

void dijkstra(Graph* graph, int source) {
    bool visited[graph->order];
    graph->distance = (int*)malloc(sizeof(int) * graph->order);
    graph->previous = (int*)malloc(sizeof(int) * graph->order);
    for (int i = 0; i < graph->order; i++) {
        graph->distance[i] = INT_MAX;
        visited[i] = false;
    }
    graph->source = source;
    graph->distance[source] = 0;

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
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->order = order;
    g->matrix = (int**)malloc(sizeof(int*) * order);
    for (int i = 0; i < order; i++) {
        g->matrix[i] = (int*)malloc(sizeof(int) * order);
        for (int j = 0; j < order; j++) {
            g->matrix[i][j] = INT_MAX;
        }
    }
    return g;
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