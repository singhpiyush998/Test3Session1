/*
Write program to add n fractions
struct _fraction
{
int num,den;
};
typedef _fraction Fraction;
int find_gcd(int a, int b);
Fraction input_fraction();
void input_in_fractions(int n, Fraction f[n]);
Fraction add_fractions(Fraction f1, Fraction f2);
Fraction add_n_fractions(int n,Fraction f[n]);
void output(int n, Fraction f[n], Fraction sum);
*/
#include <stdio.h>

typedef struct fraction
{
    int num, den;
} Fraction;

int input_n()
{
    int n;
    printf("Enter the number of fractions you want to add: ");
    scanf("%d", &n);
    return n;
}

Fraction input_fraction()
{
    Fraction f;
    printf("Enter a fraction like: NUM DEN\n");
    scanf("%d%d", &f.num, &f.den);
    return f;
}

void input_n_fractions(int n, Fraction* arr)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = input_fraction();
    }
}

int find_gcd(int a, int b)
{
    if (a == 0) return b;
    return find_gcd(b % a, a);
}

Fraction add_fractions(Fraction f1, Fraction f2)
{
    Fraction res;
    res.num = f1.num * f2.den + f2.num * f1.den;
    res.den = f1.den * f2.den;
    return res;
}

Fraction add_n_fractions(int n, Fraction* arr)
{
    Fraction sum;
    sum.num = arr[0].num, sum.den = arr[0].den;
    for (int i = 1; i < n; i++)
    {
        sum = add_fractions(sum, arr[i]);
    }
    int factor = find_gcd(sum.num, sum.den);
    sum.num /= factor;
    sum.den /= factor;
    return sum;
}

void output(int n, Fraction* f, Fraction sum)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d/%d + ", f[i].num, f[i].den);
    }
    printf("%d/%d is %d/%d\n", f[n - 1].num, f[n - 1].den, sum.num, sum.den);
}

int main()
{
    int length = input_n();
    Fraction arr[length];
    input_n_fractions(length, arr);
    Fraction sum = add_n_fractions(length, arr);
    output(length, arr, sum);
    return 0;
}
