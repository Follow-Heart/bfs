//
// Created by Yingnan Zhao on 7/12/19.
//
#include "head.h"

#ifndef BFS_BFS_H
#define BFS_BFS_H

struct graph;

struct solution
{
    int* distances;
};

struct vertex_set {
    int  count;
    int  alloc_count;
    int* present;
};


//void bfs_bottom_up(graph* graph, solution* sol);
void bfs_top_down(graph* graph, solution* sol);
//void bfs_hybrid(graph* graph, solution* sol);
void top_down_step(graph* g, vertex_set* frontier, int* distances, int iteration);

#endif //BFS_BFS_H
