//
// Created by malak on 1/10/2023.
//

#ifndef S_S_A_4_NODES_H
#define S_S_A_4_NODES_H

#include "graph.h"

/**
 * Get a node with a given node number.
 * @param head: Pointer to the head of the linked list
 * @param node_num: The number of the node.
 * @return: A pointer to the node with the given number, or NULL if no such node exists.
 */
pnode get_node(pnode head, int node_num);

/**
 * Create a new node with a given node number.
 * @param node_num: The number of the node.
 * @return: A pointer to the newly created node.
 */
pnode create_node(int node_num);

/**
 * Attach a node to the end of the linked list of nodes.
 * @param head: Pointer to the head of the linked list.
 * @param node: Pointer to the node to be attached.
 */
void attach_node(pnode head, pnode node);
/**
 * Detach a node from the linked list of nodes.
 * @param head: Pointer to the head of the linked list.
 * @param node: Pointer to the node to be detached.
 */
void detach_node(pnode *head, pnode node);
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

#endif //S_S_A_4_NODES_H
