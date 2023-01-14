//
// Created by malak on 1/10/2023.
//
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void print_edges(pnode node) {
    if (NULL == node) {
        printf("Failed with [print_edges] :: Node is NULL.\n");
        return;
    }
    pedge current_edge = node->edges;
    printf("Node[%d] edges:\n", node->node_num);
    while (NULL != current_edge) {
        printf("Node[%d] -- Weight[%d] --> Node[%d]\n", node->node_num, current_edge->weight,
               current_edge->endpoint->node_num);
        current_edge = current_edge->next;
    }
}

void print_all_edges(pnode head) {
    if (NULL == head) {
        printf("Failed with [print_all_edges] :: Node is NULL.\n");
        return;
    }
    pnode current_node = head;
    while (NULL != current_node) {
        printf("Node[%d] edges:\n", current_node->node_num);
        pedge current_edge = current_node->edges;
        while (NULL != current_edge) {
            printf("Node[%d] -- Weight[%d] --> Node[%d]\n", current_node->node_num, current_edge->weight,
                   current_edge->endpoint->node_num);
            current_edge = current_edge->next;
        }
        current_node = current_node->next;
    }
}

void insert_edge(pnode source, pnode dest, int weight) {
    if (NULL == source || NULL == dest) {
        printf("Failed with [insert_edge] :: One or two of the nodes are NULL.\n");
        return;
    }
    pedge new_edge = (pedge) malloc(sizeof(edge));
    if (NULL == new_edge) {
        printf("Error: Failed to allocate memory for edge between[%d,%d].\n", source->node_num, dest->node_num);
        return;
    }
    new_edge->weight = weight;
    new_edge->endpoint = dest;
    new_edge->next = source->edges;
    source->edges = new_edge;
}

void delete_outer_edges(pnode node) {
    if (NULL == node) {
        printf("Failed with [delete_outer_edges] :: Node is NULL.\n");
        return;
    }
    pedge current_edge = node->edges;
    pedge previous_edge;

    while (NULL != current_edge) {
        previous_edge = current_edge;
        current_edge = current_edge->next;
        free(previous_edge);
    }
    node->edges = NULL;
}

void delete_inner_edges(pnode head, pnode node) {
    if (NULL == node) {
        printf("Failed with [delete_inner_edges] :: Node is NULL.\n");
        return;
    }
    while (NULL != head) {
        pedge current_edge = head->edges;
        pedge previous_edge = NULL;
        while (NULL != current_edge) {
            if (current_edge->endpoint == node) {
                if (NULL == previous_edge) {
                    head->edges = current_edge->next;
                } else {
                    previous_edge->next = current_edge->next;
                }
                free(current_edge);
                break;
            }
            previous_edge = current_edge;
            current_edge = current_edge->next;
        }
        head = head->next;
    }
}

void delete_all_edges(pnode head) {
    if (NULL == head) {
        printf("Failed with [delete_all_edges] :: Graph is Empty.\n");
        return;
    }
    pnode current_node = head;
    while (NULL != current_node) {
        delete_outer_edges(current_node);
        delete_inner_edges(head, current_node);
        current_node = current_node->next;
    }
}



