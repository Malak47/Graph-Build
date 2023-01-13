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
 * Delete the edge between two nodes.
 * @param source: The tail of the edge.
 * @param dest: The head of the edge.
 */
void delete_edge(pnode source, pnode dest);

/**
 * Deletes all the edges of a given node.
 * @param node: The node to delete it's edges.
 */
void delete_all_edges(pnode node);

#endif //S_S_A_4_EDGES_H
