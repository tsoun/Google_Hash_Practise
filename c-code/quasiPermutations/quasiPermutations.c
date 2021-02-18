#include <stdio.h>
#include <stdlib.h>

void perms(int, int, int **, int *);
int calculateSum(int, int *, int *);
int main()
{
    int *x, *coef;
    coef = malloc(sizeof(int) * 4); // coef := the number of pizzas each i-member team would get if it happens to be delivered pizzas
    coef[0] = 2;
    coef[1] = 3;
    coef[2] = 3;
    coef[3] = 4;
    x = malloc(sizeof(int) * 4);
    perms(4, 4, &x, coef);
    return 0;
}

void perms(int n, int t, int **x, int *coef)
{
    for (int i = 0; i < 2; i++)
    {
        *(*x + t - n) = i;
        if (n == 0)
        {
            if (calculateSum(t, *x, coef) == 5)
            {
                printf("Successful combination.\n"); //a successful combination, eg for 1 2 1, then it is
                                                     //2 pizzas for the 2-member team and 3 pizzas for the
                                                     //3-member team (given FIVE pizzas available).
            }
        }
        else
        {
            perms(n - 1, 4, x, coef);
        }
    }
}

int calculateSum(int t, int *x, int *coef)
{
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        sum += *(coef + i) * *(x + i);
    }
    return sum;
}