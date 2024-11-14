#include "dijkstra.h"

void test() {
    // https://www.researchgate.net/figure/An-example-of-a-directed-graph-with-9-nodes_fig1_220863116
    Graph* g = _initialize(9);
    _add_arc(g, 0, 1, 8);
    _add_arc(g, 0, 2, 3);
    _add_arc(g, 0, 5, 13);
    _add_arc(g, 1, 2, 2);
    _add_arc(g, 1, 3, 1);
    _add_arc(g, 2, 1, 3);
    _add_arc(g, 2, 3, 9);
    _add_arc(g, 2, 4, 2);
    _add_arc(g, 3, 4, 4);
    _add_arc(g, 3, 6, 6);
    _add_arc(g, 3, 7, 2);
    _add_arc(g, 4, 0, 5);
    _add_arc(g, 4, 3, 6);
    _add_arc(g, 4, 5, 5);
    _add_arc(g, 4, 8, 4);
    _add_arc(g, 5, 6, 1);
    _add_arc(g, 5, 8, 7);
    _add_arc(g, 6, 4, 3);
    _add_arc(g, 6, 7, 4);
    _add_arc(g, 7, 8, 1);
    _add_arc(g, 8, 6, 5);
    _print_matrix(g);
    dijkstra(g, 0);
    _print_output(g);
}

int main() {
    test();
    return 0;
}