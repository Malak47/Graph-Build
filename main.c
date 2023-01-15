//
// Created by malak on 1/10/2023.
//
#include "graph.h"
#include "nodes.h"
#include <stdio.h>

int main() {
    pnode graph = NULL;
    char input;
    int ask = 1;
    while (1) {
        if (ask) {
            int input_result = scanf(" %c", &input);
            if (input_result == -1 || input_result == 0) {
                break;
            }
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
                break;
        }
    }
    deleteGraph_cmd(&graph);
    return 0;
}

