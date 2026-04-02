#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

double fitness(double x) {

    return x * sin(x);

}

double rand_double(double min, double max) {

    return min + (double)rand() / RAND_MAX * (max - min);

}

int select_parent(double fit[], int n) {

    int i = rand() % n;

    int j = rand() % n;

    return (fit[i] > fit[j]) ? i : j;

}

double crossover(double p1, double p2, double rate) {

    if ((double)rand() / RAND_MAX < rate)

        return (p1 + p2) / 2;

    return p1;

}

double mutation(double x, double rate) {

    if ((double)rand() / RAND_MAX < rate)

        return x + rand_double(-1, 1);

    return x;

}

int main() {

    int pop_size, max_gen;

    double cross_rate, mut_rate;

    int i, gen;

    printf("Enter Population Size: ");

    scanf("%d", &pop_size);

    printf("Enter Number of Generations: ");

    scanf("%d", &max_gen);

    printf("Enter Crossover Probability (0-1): ");

    scanf("%lf", &cross_rate);

    printf("Enter Mutation Probability (0-1): ");

    scanf("%lf", &mut_rate);

    double pop[pop_size], new_pop[pop_size], fit[pop_size];

    srand(time(0));

    for (i = 0; i < pop_size; i++)

        pop[i] = rand_double(0, 10);

    for (gen = 0; gen < max_gen; gen++) {

        for (i = 0; i < pop_size; i++)

            fit[i] = fitness(pop[i]);

        for (i = 0; i < pop_size; i++) {

            int p1 = select_parent(fit, pop_size);

            int p2 = select_parent(fit, pop_size);

            double child = crossover(pop[p1], pop[p2], cross_rate);

            child = mutation(child, mut_rate);

            new_pop[i] = child;

        }

        for (i = 0; i < pop_size; i++)

            pop[i] = new_pop[i];

    }

    double best = pop[0];

    double best_fit = fitness(best);

    for (i = 1; i < pop_size; i++) {

        if (fitness(pop[i]) > best_fit) {

            best = pop[i];

            best_fit = fitness(pop[i]);

        }

    }

    printf("\nBest Solution: %lf\n", best);

    printf("Best Fitness: %lf\n", best_fit);

    printf("Generations: %d\n", max_gen);

    return 0;

}
 