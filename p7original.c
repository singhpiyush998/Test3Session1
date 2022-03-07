/*
Write a program to add two fractions.
struct _fraction
{
int num,den;
};
typedef _fraction Fraction;
int find_gcd(int a, int b);
Fraction input_fraction();
Fraction add_fractions(Fraction f1, Fraction f2)
void output(Fraction f1, Fraction f2, Fraction f3, Fraction su
*/

#include <stdio.h>

typedef struct fraction
{
    int num, den;
} Fraction;

Fraction input_fraction()
{
    Fraction f;
    printf("Enter a fraction like: NUM DEN\n");
    scanf("%d%d", &f.num, &f.den);
    return f;
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
    int factor = find_gcd(res.num, res.den);
    res.num /= factor;
    res.den /= factor;
    return res;
}

void output(Fraction f1, Fraction f2, Fraction sum)
{
    printf("%d/%d + %d/%d is %d/%d\n", f1.num, f1.den, f2.num, f2.den, sum.num, sum.den);
}

int main()
{
    Fraction f1, f2, sum;
    f1 = input_fraction();
    f2 = input_fraction();
    sum = add_fractions(f1, f2);
    output(f1, f2, sum);
    return 0;
}
