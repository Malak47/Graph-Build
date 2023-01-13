//
// Created by malak on 1/10/2023.
//

#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

/**
 * Insert a new node and its edges to the graph.
 * @param head: Pointer to the head of the linked list
 */
void insert_node_cmd(pnode *head);
/**
 * Delete a node and its edges from the graph.
 * @param head: Pointer to the head of the linked list.
 */
void delete_node_cmd(pnode *head);
/**
 * Print the graph for debugging.
 * @param head: Pointer to the head of the linked list.
 */
void printGraph_cmd(pnode head);
/**
 * Delete the graph and release the memory allocated for it.
 * @param head: Pointer to the head of the linked list.
 */
void deleteGraph_cmd(pnode *head);

/**
 * Find the shortest path between two nodes.
 * @param head: Pointer to the head of the linked list
 */
void build_graph_cmd(pnode *head);

void shortsPath_cmd(pnode head);

void TSP_cmd(pnode head);

#endif

