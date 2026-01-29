#include <stdio.h>

#define SIZE 6

int grid[SIZE][SIZE] = {
 {0,1,0,0,1,0},
 {0,1,0,1,0,0},
 {0,0,0,1,0,1},
 {1,1,0,0,0,1},
 {0,0,1,1,0,0},
 {1,0,0,0,1,0}
};

int moveX[4] = {-1, 1, 0, 0};
int moveY[4] = {0, 0, -1, 1};

int is_safe(int r, int c, int visited[SIZE][SIZE]) {
    if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) return 0; // Boundary check
    if (grid[r][c] == 1 || visited[r][c] == 1) return 0;   // Wall or already visited check
    return 1;
}

void solve_maze_dfs(int startR, int startC, int goalR, int goalC) {
    int stackX[36], stackY[36], top = -1;
    int visited[SIZE][SIZE] = {0}, expanded_count = 0;

    // Push starting point onto stack
    stackX[++top] = startR; 
    stackY[top] = startC;

    while (top >= 0) {
        // Pop current cell
        int currR = stackX[top];
        int currC = stackY[top];
        top--;

        // Skip if this cell was already processed
        if (visited[currR][currC]) continue;

        // Mark as visited and count it
        visited[currR][currC] = 1;
        expanded_count++;

        // Check if goal is reached
        if (currR == goalR && currC == goalC) {
            printf("\nDFS Path Found!");
            printf("\nTotal Cells Explored: %d\n", expanded_count);
            return;
        }

        // Add neighbors to stack (Up, Down, Left, Right)
        for (int i = 0; i < 4; i++) {
            int nextR = currR + moveX[i];
            int nextC = currC + moveY[i];

            if (is_safe(nextR, nextC, visited)) {
                stackX[++top] = nextR;
                stackY[top] = nextC;
            }
        }
    }
    printf("\nNo path exists to the goal.\n");
}

int main() {
    solve_maze_dfs(0, 0, 5, 5);
    return 0;
}
