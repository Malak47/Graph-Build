//
// Created by malak on 1/10/2023.
//
#include "graph.h"
#include "nodes.h"
#include <stdio.h>

int main() {
    pnode graph = NULL;
    char input;
    int stop = 1;
    int ask = 0;
    scanf(" %c", &input);
    while (stop) {
        if (ask == 1) {
            scanf(" %c", &input);
        }
        switch (input) {
            case 'A':
                build_graph_cmd(&graph);
                input = n_input(&graph);
                ask = 0;
                break;
            case 'B':
                insert_node_cmd(&graph);
                ask = 1;
                break;
            case 'D':
                delete_node_cmd(&graph);
                ask = 1;
                break;
            case 'P':
                printGraph_cmd(graph);
                ask = 1;
                break;
            case 'S':
                shortsPath_cmd(graph);
                ask = 1;
                break;
            case 'T':
                TSP_cmd(graph);
                ask = 1;
                break;
            default:
                stop = 0;
                deleteGraph_cmd(&graph);
                break;
        }
    }
    deleteGraph_cmd(&graph);
    return 0;
}
