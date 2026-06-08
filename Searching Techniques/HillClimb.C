#include <stdio.h>

// Function definition
int f(int x)
{
    return x*x + 2*x + 8;
}

int hillClimbing(int start)
{
    int current = start;
    int neighbor;
    int step = 1;
    if(f(current+1)<f(current-1))
    {
        step = -1;
    }
    while (1)
    {
        neighbor = current + step;

        // If neighbor gives better value, move there
        if (f(neighbor) < f(current))
        {
            current = neighbor;
        }
        else
        {
            break; // stop when no better neighbor
        }
    }

    return current;
}

int main()
{
    int start;

    printf("Enter starting value of x: ");
    scanf("%d", &start);

    int max_x = hillClimbing(start);

    printf("\nMaximum value found at x = %d\n", max_x);
    printf("Maximum value of function f(x) = %d\n", f(max_x));

    return 0;
}