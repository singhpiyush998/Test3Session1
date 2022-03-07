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

// nCr = (nCr-1 * n - r + 1) / r
int find_nCr(int n, int r)
{
    if (r == 1) return n;
    return ((n - r + 1) * find_nCr(n, r - 1)) / r;
}

void output(int n, int r, int result)
{
    printf("For n = %d and r = %d nCr = %d\n", n, r, result);
}

int main()
{
    int n, r, res;
    input_n_and_r(&n, &r);
    res = find_nCr(n, r);
    output(n, r, res);
    return 0;
}