#include <stdio.h>
#define MAX 10
#define INF 99999

int main()
{
    int n, i, j, k, L;
    int p[MAX];             
    int m[MAX][MAX];         
    int s[MAX][MAX];     

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array (size %d): ", n + 1);
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INF;

            for (k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nCost Matrix (m[][]):\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i > j)
                printf("0\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }                                                       

    printf("\nK Matrix (s[][]):\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                printf("0\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }       

    return 0;
}
