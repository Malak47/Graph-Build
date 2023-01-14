//
// Created by malak on 1/10/2023.
//

#ifndef S_S_A_4_EDGES_H
#define S_S_A_4_EDGES_H

/**
 * Add edge between two nodes.
 * @param source: The tail of the edge.
 * @param dest: The head of the edge.
 * @param weight: The weight of the edge.
 */
void insert_edge(pnode source, pnode dest, int weight);

/**
 * Delete all the edges of node (inner and outer).
 * @param head:  Pointer to the head of the linked list.
 */
void delete_all_edges(pnode head);

/**
 * Delete the outer edges of node.
 * @param node: The node to delete from.
 */
void delete_outer_edges(pnode node);

/**
 * Delete the inner edges of node.
 * @param head: Pointer to the head of the linked list.
 * @param node: The node to delete from.
 */
void delete_inner_edges(pnode head,pnode node);

/**
 * Prints out all the nodes with its edges and weights.
 * @param head: Pointer to the head of the linked list.
 */
void print_all_edges(pnode head);

/**
 * Prints out node with its edges and weights.
 * @param head: Pointer to the node to be printed.
 */
void print_edges(pnode node);

#endif //S_S_A_4_EDGES_H
