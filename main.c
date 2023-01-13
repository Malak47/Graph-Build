#include <stdio.h>

int main() {
    //Directed Graph.
    //read from the user graph with unknown length.
    //A -> stands for new graph, if older graph exists, remove it.
    //number -> stands for a number of the nodes.
    //after entering the number of the nodes, we got AT LEAST 3 inputs //
        // [int,int,int] which is: the curr node, the dest node, the wight.
    //n -> to switch between the nodes.

    //B -> stands for a new node followed by [int] for it's number //
        // and [int,int,...] for the dest nodes + it's wights.
    // if the node is already exists, REMOVE all the directions that is OUT FROM IT.

    //D -> deletes a node with its wights and directions.

    //S [int,int] -> returns the wight between the given nodes (return -1 if not exists)

    //P [int,int] -> returns the shortest path between the given nodes

    //T [int_len, int, int, ... , int] -> input: T with length and length numbers.
    return 0;
}
