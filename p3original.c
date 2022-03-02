/*
Write a program find the nCr given n and r.
int input_n_and_r(int *n, int *r)
int ncr(int n, int r);
void output(int n, int r, int result);
*/

#include <stdio.h>

void input_n_and_r(int* n, int* r)
{
    printf("For nCr, enter the value of n and r: ");
    scanf("%d%d", n, r);
}

int fact(int n)
{
    if (n == 2) return n;
    return n * fact(n - 1);
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

void output(int n, int r, int result)
{
    printf("For n = %d and r = %d nCr = %d\n", n, r, result);
}

int main()
{
    int n, r, res;
    input_n_and_r(&n, &r);
    res = nCr(n, r);
    output(n, r, res);
    return 0;
}