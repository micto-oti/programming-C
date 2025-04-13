#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef struct Node {
    int parent;
    int length;
    int child_count;
    int* children;
} Node;

Node tree[MAX_N];
int total_worms = 0;

void process_node(int node_id, int L) {
    int parent = tree[node_id].parent;
    if (parent != -1) {
        int edge_length = tree[node_id].length;
        total_worms += edge_length / L;
    }

    for (int i = 0; i < tree[node_id].child_count; i++) {
        process_node(tree[node_id].children[i], L);
    }
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    // Initialize tree
    for (int i = 0; i < N; i++) {
        tree[i].parent = -1;
        tree[i].child_count = 0;
        tree[i].children = NULL;
    }

    // Read parent information
    for (int i = 1; i < N; i++) {
        int parent;
        scanf("%d", &parent);
        tree[i].parent = parent;

        // Add child to parent's list
        tree[parent].child_count++;
        tree[parent].children = realloc(tree[parent].children, tree[parent].child_count * sizeof(int));
        tree[parent].children[tree[parent].child_count - 1] = i;
    }

    // Read edge lengths
    for (int i = 1; i < N; i++) {
        scanf("%d", &tree[i].length);
    }

    // Process tree starting from root (0)
    process_node(0, L);

    printf("%d\n", total_worms);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        if (tree[i].children != NULL) {
            free(tree[i].children);
        }
    }

    return 0;
}