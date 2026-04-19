#include <stdio.h>
#define INF 999
#define MAX 10
void printMatrix(int n, int a[MAX][MAX], int step) {
    printf("\nA%d Matrix:\n", step);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    int a[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printMatrix(n, a, 0);
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
        printMatrix(n, a, k + 1);
    }
    printf("\nFinal Shortest Path Matrix:\n");
    printMatrix(n, a, n);
    return 0;
}
