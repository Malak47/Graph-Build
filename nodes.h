//
// Created by malak on 1/10/2023.
//

#ifndef S_S_A_4_NODES_H
#define S_S_A_4_NODES_H

#include "graph.h"

pnode get_node(pnode head, int node_num);

pnode create_node(int node_num);

void attach_node(pnode head, pnode node);

void detach_node(pnode *head, pnode node);

void insert_node_cmd(pnode *head);

void delete_node_cmd(pnode *head);

void printGraph_cmd(pnode head);

void deleteGraph_cmd(pnode *head);

void build_graph_cmd(pnode *head);

#endif //S_S_A_4_NODES_H
