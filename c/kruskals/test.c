#include <stdio.h>
#include "kruskals.h"

void test() {
    AdjacencyMatrix matrix;
    initialize_matrix(&matrix, 5);
    add_edge(&matrix, (Edge){0, 1, 35});
    add_edge(&matrix, (Edge){0, 2, 40});
    add_edge(&matrix, (Edge){1, 2, 25});
    add_edge(&matrix, (Edge){1, 3, 10});
    add_edge(&matrix, (Edge){2, 3, 20});
    add_edge(&matrix, (Edge){2, 4, 15});
    add_edge(&matrix, (Edge){3, 4, 30});

    MinimumSpanningTree* tree = kruskals(matrix);
}

int main() {
    test();
    return 0;
}