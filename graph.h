//
// Created by Yingnan Zhao on 7/9/19.
//
#include "head.h"

#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

struct graph
{
    int num_edges;
    int num_nodes;

    // The node reached by vertex i's first outgoing edge is given by
    // outgoing_edges[outgoing_starts[i]].  To iterate over all
    // outgoing edges, please see the top-down bfs implementation.
    int* outgoing_starts;
    int* outgoing_edges;
};

void load_graph_binary(string filename, graph* graph);
//void store_graph_binary(const char* filename, graph* graph);

#endif //BFS_GRAPH_H
