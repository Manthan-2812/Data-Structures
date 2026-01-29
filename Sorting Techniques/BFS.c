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
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
// This is to  check whether my mouse in within the box or not 
int valid(int x,int y,int v[N][N]) {
 if(x<0 || x>=N || y<0 || y>=N)
 { 
    return 0;
 }
 if(maze[x][y]==1 || v[x][y]==1) 
 {
    return 0;
 }
 return 1;
}
void bfs(int sx,int sy,int gx,int gy) {
 int qx[36], qy[36], f=0, r=0;
 int v[N][N]={0}, c=0; // c checks the no. of nodes visited
 qx[r]=sx; qy[r]=sy; r++;
 v[sx][sy]=1; // This tells that the tile is visited 
 while(f<r) {
 int x=qx[f], y=qy[f];
 f++; c++;
 if(x==gx && y==gy) {
 printf("\nBFS Found Goal");
 printf("\nNodes Expanded: %d\n",c);
 return;
 }
 for(int i=0;i<4;i++) {
 int nx=x+dx[i], ny=y+dy[i];
 if(valid(nx,ny,v)) {
 v[nx][ny]=1;
 qx[r]=nx; qy[r]=ny; r++;
 }
 }
 }
 printf("\nBFS Goal Not Found\n");
}

int main() {
    int startX = 0, startY = 0; // Starting point (0,0)
    int goalX = 5, goalY = 5;  // Goal point (5,5)
    
    printf("Starting BFS from (%d,%d) to (%d,%d)...\n", startX, startY, goalX, goalY);
    bfs(startX, startY, goalX, goalY);
    
    return 0;
}