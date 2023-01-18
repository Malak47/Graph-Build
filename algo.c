//
// Created by malak on 1/10/2023.
//
#include "graph.h"
#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_min(int *dist, int *visited, int len) {
    int min = -1;
    int i = 0;
    while (i < len) {
        if (min == -1) {
            if (INT_MAX != *(dist + i) && !*(visited + i))
                min = i;
        } else if (INT_MAX != *(dist + i) && *(dist + i) < *(dist + min) && !*(visited + i))
            min = i;
        i++;
    }
    return min;
}

int get_max(pnode head) {
    if (head == NULL) {
        return -1;
    }
    int max = head->node_num;
    while (NULL != head) {
        if (head->node_num > max) {
            max = head->node_num;
        }
        head = head->next;
    }
    return max;
}

int is_empty(int *visited, int len) {
    int i = 0;
    while (i < len) {
        if (!*(visited + i)) {
            return 0;
        }
        i++;
    }
    return 1;
}

int *array_remove_element(int *arr, int len, int index) {
    int *new_arr = (int *) malloc(sizeof(int) * len - 1);
    int i = 0;
    int j = 0;
    while (i < len) {
        if (i != index) {
            *(new_arr + j) = *(arr + i);
            j++;
        }
        i++;
    }
    return new_arr;
}

int shortest_path_dijkstra(pnode head, int source, int dest) {
    if (NULL == head)
        return -1;

    int dist_len = get_max(head) + 1;
    int *visited = (int *) malloc(sizeof(int) * dist_len);
    int *dist = (int *) malloc(sizeof(int) * dist_len);

    int i = 0;
    while (i < dist_len) {
        *(visited + i) = 0;
        if (NULL == get_node(head, i)) {
            *(visited + i) = 1;
        }
        i++;
    }
    i = 0;
    while (i < dist_len) {
        *(dist + i) = INT_MAX;
        i++;
    }
    *(dist + source) = 0;

    int min;
    while (!is_empty(visited, dist_len) && (min = get_min(dist, visited, dist_len)) != -1) {
        pnode node = get_node(head, min);
        pedge edge = node->edges;
        while (NULL != edge) {
            if (!*(visited + edge->endpoint->node_num)) {
                if (INT_MAX != *(dist + node->node_num) &&
                    *(dist + node->node_num) + edge->weight < *(dist + edge->endpoint->node_num)) {
                    *(dist + edge->endpoint->node_num) = *(dist + node->node_num) + edge->weight;
                }
            }
            edge = edge->next;
        }
        *(visited + min) = 1;
    }
    free(visited);

    if (INT_MAX == *(dist + dest)) {
        free(dist);
        return -1;
    }
    int x = *(dist + dest);
    free(dist);
    return x;
}

int tsp(pnode head, int source, int *arr, int len) {
    if (NULL == head || NULL == arr) {
        return -1;
    }
    if (len == 1)
        return shortest_path_dijkstra(head, source, *arr);

    int min = INT_MAX;

    int i = 0;
    while (i < len) {
        if (i != source) {
            int *removed = array_remove_element(arr, len, i);
            int short_path = shortest_path_dijkstra(head, source, *(arr + i));
            int result = tsp(head, *(arr + i), removed, len - 1);

            if (short_path != -1 && result != -1 && result + short_path < min) {
                min = result + short_path;
            }
            free(removed);
        }
        i++;
    }

    if (INT_MAX == min) {
        return -1;
    }
    return min;
}

void shortsPath_cmd(pnode head) {
    if (NULL == head)
        return;

    int source, dest;
    scanf("%d %d", &source, &dest);

    int result = shortest_path_dijkstra(head, source, dest);

    if (result == -1) {
        printf("Dijsktra shortest path: -1 \n");
        return;
    }
    printf("Dijsktra shortest path: %d \n", result);
}

void TSP_cmd(pnode head) {
    int size;
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);

    int i = 0;
    while (i < size) {
        scanf("%d", &*(arr + i));
        i++;
    }

    int min = INT_MAX;

    i = 0;
    while (i < size) {
        int *removed = array_remove_element(arr, size, i);
        int dist = tsp(head, *(arr + i), removed, size - 1);
        if (dist != -1 && min > dist) {
            min = dist;
        }
        free(removed);
        i++;
    }
    if (INT_MAX == min) {
        printf("TSP shortest path: -1 \n");
    } else {
        printf("TSP shortest path: %d \n", min);
    }
    free(arr);
}