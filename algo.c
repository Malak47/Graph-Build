//
// Created by malak on 1/10/2023.
//
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "nodes.h"

int get_max_id(pnode head) {
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

int isEmpty(int *visited, int len) {
    int i = 0;
    while (i < len) {
        if (!*(visited + i)) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Dijkstra Algorithm
int shortsPath_Dijkstra(pnode head, int source, int dest) {
    if (NULL == head)
        return -1;

    int distLen = get_max_id(head) + 1;
    int *visited = (int *) malloc(sizeof(int) * distLen);
    int *dist = (int *) malloc(sizeof(int) * distLen);

    // init dist
    int i = 0;
    while (i < distLen) {
        *(visited + i) = 0;
        if (get_node(head, i) == NULL) {
            *(visited + i) = 1;
        }
        i++;
    }
    i = 0;
    while (i < distLen) {
        *(dist + i) = INT_MAX;
        i++;
    }
    *(dist + source) = 0;

    int min;
    while (!isEmpty(visited, distLen) && (min = get_min(dist, visited, distLen)) != -1) {
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

// Dijkstra Algorithm
void shortsPath_cmd(pnode head) {
    if (NULL == head)
        return;

    int source, dest;
    scanf("%d %d", &source, &dest);

    int res = shortsPath_Dijkstra(head, source, dest);

    if (res == -1) {
        printf("Dijsktra shortest path: -1 \n");
        return;
    }
    printf("Dijsktra shortest path: %d \n", res);
}

int *arrayRemoveElement(int *arr, int len, int k) {
    int *newArr = (int *) malloc(sizeof(int) * len - 1);
    int i = 0;
    int j = 0;
    while (i < len) {
        if (i != k) {
            *(newArr + j) = *(arr + i);
            j++;
        }
        i++;
    }
    return newArr;
}

int tsp(pnode head, int source, int *arr, int len) {
    if (NULL == head || NULL == arr) {
        return -1;
    }
    if (len == 1)
        return shortsPath_Dijkstra(head, source, *arr);

    int min = INT_MAX;

    int i = 0;
    while (i < len) {
        if (i != source) {
            int *s = arrayRemoveElement(arr, len, i);
            int sh = shortsPath_Dijkstra(head, source, *(arr + i));
            int res = tsp(head, *(arr + i), s, len - 1);

            if (sh != -1 && res != -1 && res + sh < min) {
                min = res + sh;
            }
            free(s);
        }
        i++;
    }

    if (INT_MAX == min) {
        return -1;
    }
    return min;
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
        int *s = arrayRemoveElement(arr, size, i);
        int x = tsp(head, *(arr + i), s, size - 1);
        if (x != -1 && min > x) {
            min = x;
        }
        free(s);
        i++;
    }
    if (INT_MAX == min) {
        printf("TSP shortest path: -1 \n");
    } else {
        printf("TSP shortest path: %d \n", min);
    }
    free(arr);
}