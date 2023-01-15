//
// Created by malak on 1/10/2023.
//

#ifndef S_S_A_4_ALGO_H
#define S_S_A_4_ALGO_H

#include "graph.h"

/**
 * @param head: Pointer to the head of the linked list.
 * @return: The maximum node ID. Returns -1 if the list is empty.
*/
int get_max_id(pnode head);

/**
 * Returns the index of the element with the minimum value in the given array, that has not been visited.
 * @param dist: The array of distances.
 * @param visited: The array of visited status.
 * @param len: The length of the arrays.
 * @return: The index of the element with the minimum value. Returns -1 if no such element exists.
 */
int get_min(int *dist, int *visited, int len);

/**
 * Returns true if all elements of the given array are true, false otherwise.
 * @param visited: The array of visited status.
 * @param len: The length of the array.
 * @return: 1 if all elements are true, 0 otherwise.
 */
int isEmpty(int *visited, int len);

/**
 * Finds the shortest path from the source node to the destination node using the Dijkstra algorithm.
 * @param head: Pointer to the head of the linked list.
 * @param source: The starting node for the shortest path.
 * @param dest: The ending node for the shortest path.
 * @return: The shortest path from the source to the destination. Returns -1 if no path exists.
 */
int shortsPath_Dijkstra(pnode head, int source, int dest);

/**
 * Prints the shortest path from the source node to the destination node using the Dijkstra algorithm.
 * The source and destination node are entered by the user.
 * @param head: Pointer to the head of the linked list.
 */
void shortsPath_cmd(pnode head);

/**
* Creates a new array with the given element removed from the original array.
* @param arr: The original array.
* @param len: The length of the original array.
* @param index: The index of the element to be removed.
* @return: The new array with the given element removed.
*/
int *arrayRemoveElement(int *arr, int len, int index);

/**
 * Finds a tour visiting all nodes starting from the source node using the TSP algorithm.
 * @param head: Pointer to the head of the linked list.
 * @param source: The starting node for the tour.
 * @param arr: The array of nodes to be visited in order.
 * @param len: The length of the array.
 * @return: The total distance of the tour.
 */
int tsp(pnode head, int source, int *arr, int len);

/**
 * Prints a tour visiting all nodes starting from the source node using the TSP algorithm.
 * The source node is entered by the user.
 * @param head: Pointer to the head of the linked list.
 */
void TSP_cmd(pnode head);

#endif //S_S_A_4_ALGO_H

