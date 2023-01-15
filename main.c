int main() {
    pnode graph = NULL;

    char input;
    while (1) {
        int input_result = scanf(" %c", &input);
        if (input_result != 1) {
            break;
        }

        switch (input) {
            case 'A':
                input = build_graph_cmd(&graph);
                break;

            case 'B':
                insert_node_cmd(&graph);
                break;

            case 'D':
                delete_node_cmd(&graph);
                break;

            case 'P':
                printGraph_cmd(graph);
                break;

            case 'S':
                shortsPath_cmd(graph);
                break;

            case 'T':
                TSP_cmd(graph);
                break;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
    deleteGraph_cmd(&graph);

    return 0;
}
