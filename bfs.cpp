#include "bfs.h"
#include "graph.h"

#define ROOT_NODE_ID 0
#define NOT_VISITED_MARKER -1
#define PADDING 16
#define BOTTOMUP_NOT_VISITED_MARKER 0

void vertex_set_clear(vertex_set* list) {
    list->count = 0;
}

void vertex_set_init(vertex_set* list, int count) {
    list->alloc_count = count;
    list->present = (int *) malloc(sizeof(int) * list->alloc_count);
    vertex_set_clear(list);
}

void top_down_step(graph* g, vertex_set* frontier, int* distances, int iteration)
{

    int local_count = 0;
    int padding[15];

#pragma omp parallel
    {
#pragma omp for reduction(+ : local_count)
        for (int i=0; i < g->num_nodes; i++)
        {
            if (frontier->present[i] == iteration)
            {
                int start_edge = g->outgoing_starts[i];
                int end_edge = (i == g->num_nodes-1) ? g->num_edges : g->outgoing_starts[i+1];

                // attempt to add all neighbors to the new frontier
                for (int neighbor=start_edge; neighbor<end_edge; neighbor++)
                {
                    int outgoing = g->outgoing_edges[neighbor];

                    if(frontier->present[outgoing] == BOTTOMUP_NOT_VISITED_MARKER)
                    {
                        // if(__sync_bool_compare_and_swap(&frontier->present[outgoing], BOTTOMUP_NOT_VISITED_MARKER, iteration + 1)) {
                        distances[outgoing] = distances[i] + 1;
                        local_count ++;
                        frontier->present[outgoing] = iteration + 1;
                    }
                }
            }
        }

        // #pragma omp atomic
        //     frontier->count += local_count;
    }

    frontier->count = local_count;
}

void bfs_top_down(graph* graph, solution* sol)
{
    vertex_set list1;

    vertex_set_init(&list1, graph->num_nodes);

    int iteration = 1;

    vertex_set *frontier = &list1;

    memset(frontier->present, 0, sizeof(int) * graph->num_nodes);

    frontier->present[frontier->count++] = 1;

    // set the root distance with 0
    sol->distances[ROOT_NODE_ID] = 0;

    // just like pop the queue
    while (frontier->count != 0)
    {
        cout<<frontier->count<<endl;
        frontier->count = 0;

        top_down_step(graph, frontier, sol->distances, iteration);

        iteration++;
    }
}
