/*
Write a program to find the smallest of three fractions.
struct _fraction
{
int num,den;
};
typedef _fraction Fraction
Fraction input_fraction();
Fraction Largest_fraction(Fraction f1, Fraction f2, Fraction f3)
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

Fraction Largest_fraction(Fraction f1, Fraction f2, Fraction f3)
{
    Fraction largest = f1;
    if ((float)largest.num / largest.den < (float)f2.num / f2.den)
        largest = f2;
    if ((float)largest.num / largest.den < (float)f3.num / f3.den)
        largest = f3;
    return largest;
}

void output(Fraction a, Fraction b, Fraction c, Fraction large)
{
    printf("The largest of %d / %d , %d / %d and %d / %d is %d / %d\n", a.num, a.den, b.num, b.den, c.num, c.den, large.num, large.den);
}

int main()
{
    Fraction f1, f2, f3, large;
    f1 = input_fraction();
    f2 = input_fraction();
    f3 = input_fraction();
    large = Largest_fraction(f1, f2, f3);
    output(f1, f2, f3, large);
    return 0;
}