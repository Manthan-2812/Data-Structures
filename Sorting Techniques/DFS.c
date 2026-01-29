#include <stdio.h>
#define N 6

int maze[N][N] = {
 {0,1,0,0,1,0},
 {0,1,0,1,0,0},
 {0,0,0,1,0,1},
 {1,1,0,0,0,1},
 {0,0,1,1,0,0},
 {1,0,0,0,1,0}
};

// Directions: Up, Down, Left, Right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int sx, int sy, int gx, int gy) {
    int stkX[36], stkY[36], top = -1; // The Stack
    int visited[N][N] = {0}, count = 0;

    // 1. Push Start onto Stack
    stkX[++top] = sx;
    stkY[top] = sy;

    while (top >= 0) { // While Stack is NOT empty
        // 2. Pop the TOP item
        int x = stkX[top];
        int y = stkY[top];
        top--;

        // Skip if already visited
        if (visited[x][y]) continue;

        // 3. Mark Visited
        visited[x][y] = 1;
        count++;

        // 4. Check Goal
        if (x == gx && y == gy) {
            printf("\nDFS Found Goal!");
            printf("\nNodes Explored: %d\n", count);
            return;
        }

        // 5. Look at Neighbors
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            // Check boundaries, walls, and visited
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && 
                maze[nx][ny] == 0 && !visited[nx][ny]) {
                
                // Push neighbor onto Stack
                stkX[++top] = nx;
                stkY[top] = ny;
            }
        }
    }
    printf("\nGoal not reachable.\n");
}

int main() {
    dfs(0, 0, 5, 5);
    return 0;
}
