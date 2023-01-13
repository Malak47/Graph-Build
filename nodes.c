//
// Created by malak on 1/10/2023.
//
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "edges.h"

pnode get_node(pnode head, int node_num) {
    while (NULL != head && head->node_num != node_num) {
        head = head->next;
    }
    return head;
}

pnode create_node(int node_num) {
    pnode new_node = (pnode) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory for node number[%d].\n", node_num);
        return NULL;
    }
    new_node->node_num = node_num;
    new_node->edges = NULL;
    new_node->next = NULL;
    return new_node;
}

void attach_node(pnode head, pnode node) {
    pnode p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = node;
}

void detach_node(pnode *head, pnode node) {
    if (NULL == *head) {
        printf("Failed with [detach_node] :: Graph is empty.\n");
        return;
    }
    if (NULL == node) {
        printf("Failed with [detach_node] :: Node number[%d] does not exists.\n", node->node_num);
        return;
    }
    if (*head == node) {
        *head = node->next;
    } else {
        pnode current = *head;
        while (current->next != NULL) {
            if (current->next == node) {
                current->next = node->next;
                break;
            }
            current = current->next;
        }
    }
    // Remove edges from the node
    delete_all_edges(node);
    free(node);
}

void insert_node_cmd(pnode *head) {
    if (NULL == *head) {
        printf("Failed with [insert_node_cmd] :: Graph is empty.\n");
        return;
    }
    int node_num;
    if (scanf("%d", &node_num) != 1) {
        printf("Failed with [insert_node_cmd] :: Invalid Input.\n");
        return;
    }
    pnode new_node = get_node(*head, node_num);

    if (NULL == new_node) {
        new_node = create_node(node_num);

    } else {
        delete_all_edges(new_node);
    }

    int weight;
    int dest_node_number;

    while (scanf("%d", &dest_node_number) > 0) {
        pnode dest_node = get_node(*head, dest_node_number);
        if (NULL == dest_node) {
            printf("Node number[%d] does not exists.\n", dest_node_number);
            printf("Create the node? [Y/N]\n");
            int create;
            create = getchar();
            if (create != 'Y') {
                return;
            }
            dest_node = create_node(dest_node_number);
            attach_node(*head, dest_node);
        }
        scanf("%d", &weight);
        insert_edge(new_node, dest_node, weight);
    }
    attach_node(*head, new_node);
}

void delete_node_cmd(pnode *head) {
    if (NULL == *head) {
        printf("Failed with [delete_node_cmd] :: Graph is empty.\n");
        return;
    }
    int delete_node;
    if (scanf("%d", &delete_node) != 1) {
        printf("Failed with [delete_node_cmd] :: Invalid Input.\n");
        return;
    }
    pnode ifExists = get_node(*head, delete_node);
    if (ifExists == NULL) {
        printf("Failed with [delete_node_cmd] :: Node number[%d] does not exists.\n", delete_node);
        return;
    }
    detach_node(head, ifExists);
}

void printGraph_cmd(pnode head) {
    while (NULL != head) {
        printf("[%d]\t", head->node_num);
        print_edges(head);
        printf("\n");
        head = head->next;
    }

} //for self debug
void deleteGraph_cmd(pnode *head) {
    pnode current = *head;
    while (NULL != current) {
        delete_all_edges(current);
        pnode temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void build_graph_cmd(pnode *head) {
    if (NULL != *head) {
        deleteGraph_cmd(head);
    }
    int number_nodes;
    scanf("%d", &number_nodes);

    pnode *current = head;
    for (int i = 0; i < number_nodes; i++) {
        pnode new_node = create_node(i);
        *current = new_node;
        current = &(*current)->next;
    }
    int ch = getchar();
    while (ch > 0) {
        if (ch == 'n') {
            int source_number, dest_number, weight;
            scanf("%d", &source_number);
            pnode source_node = get_node(*head, source_number);
            while (scanf("%d", &dest_number) > 0) {
                scanf("%d", &weight);
                insert_edge(source_node, get_node(*head, dest_number), weight);
            }
        } else {
            break;
        }
    }
}