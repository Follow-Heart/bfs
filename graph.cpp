#include "graph.h"

void load_graph_binary(string filename, graph* graph) {

    ifstream input = ifstream(filename);

    if (!input) {
        cout<<"Could not open data file : "<<filename<<endl;
        exit(1);
    }

    string str;
    getline(input, str);
    istringstream s(str);
    s>>graph->num_nodes;
    s>>graph->num_edges;

    int* scratch = (int*) malloc(sizeof(int) * (graph->num_nodes + graph->num_edges));
    int index = 0;

    while(getline(input, str))
    {
        stringstream parse(str);
        parse>>scratch[index];
        index++;
    }

    graph->outgoing_starts = (int*)malloc(sizeof(int) * graph->num_nodes);
    graph->outgoing_edges = (int*)malloc(sizeof(int) * graph->num_edges);

    int num_nodes = graph->num_nodes;
    int num_edges = graph->num_edges;

    for(int i = 0; i < num_nodes; i++)
    {
        graph->outgoing_starts[i] = scratch[i];
        cout<< graph->outgoing_starts[i]<<" ";
    }

    cout<<endl;

    for(int i = 0; i < num_edges; i++)
    {
        graph->outgoing_edges[i] = scratch[num_nodes + i];
        cout<<graph->outgoing_edges[i]<<" ";
    }
    cout<<endl;

    input.close();
}

