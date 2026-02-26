#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int n;

// Depth Limited Search
int DLS(int current, int goal, int limit, int visited[], int path[], int depth) {

    visited[current] = 1;
    path[depth] = current;

    if (current == goal)
        return depth;   // return depth if found

    if (limit <= 0)
        return -1;

    for (int i = 1; i <= n; i++) {
        if (graph[current][i] && !visited[i]) {
            int result = DLS(i, goal, limit - 1, visited, path, depth + 1);
            if (result != -1)
                return result;
        }
    }

    visited[current] = 0;   // backtrack
    return -1;
}

// IDDFS Function
void IDDFS(int start, int goal, int maxDepth) {

    for (int depth = 0; depth <= maxDepth; depth++) {

        int visited[MAX] = {0};
        int path[MAX];

        int result = DLS(start, goal, depth, visited, path, 0);

        if (result != -1) {
            printf("\nGoal found at depth %d\n", depth);
            printf("Path: ");
            for (int i = 0; i <= result; i++)
                printf("%d ", path[i]);
            printf("\n");
            return;
        }
    }

    printf("Goal not found within depth limit.\n");
}

int main() {

    int edges;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;   // remove if directed
    }

    int start, goal, maxDepth;

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);

    printf("Enter maximum depth: ");
    scanf("%d", &maxDepth);

    IDDFS(start, goal, maxDepth);

    return 0;
}