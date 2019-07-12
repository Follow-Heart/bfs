#include "head.h"
#include "graph.h"
#include "bfs.h"

int main() {

    int num_threads = 10;
    string graph_filename = "data.txt";
    int opt;

    graph g;

    printf("Loading graph (this can take some time for the bigger graphs)...\n");
    load_graph_binary(graph_filename, &g);

    printf("Graph stats:\n");
    printf("  Edges: %d\n", g.num_edges);
    printf("  Nodes: %d\n", g.num_nodes);

    solution sol1;
    sol1.distances = (int*)malloc(sizeof(int) * g.num_nodes);

    clock_t startTime, endTime;
    startTime = clock();
    bfs_top_down(&g, &sol1);
    endTime = clock();
    cout<<"The running time is : "<<(double)(endTime - startTime) / CLOCKS_PER_SEC<<endl;

    return 0;
}