/*
Write a program to evaluate a polynomial at a given point using horners method.
int input_degree();
float input_x();
void input_coefficients(int n, float a[n]);
float evaluate_polynomial(int n, float a[n], float x);
void out_put(int n, float a[n], float x, float result);
input:
1 1 1
output:
1+1*x + 1*x^2 at 1.000000 is 1.000000
*/

#include <stdio.h>
#include <math.h>

int inputDegree()
{
    int deg;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &deg);
    return deg;
}

float inputX()
{
    float x;
    printf("Enter the value of x: ");
    scanf("%f", &x);
    return x;
}

void inputCoefficients(int length, float* arr)
{
    for (int i = 0; i <= length; i++)
    {
        printf("Enter the value of a%d\n", i);
        scanf("%f", &arr[i]);
    }
}

// p (x) = a0 + a1 * x + a2 * x^2 + ... + an * x^n
float evaluate_polynomial(int length, float* arr, float x)
{
    float res = arr[0];
    for (int i = 1; i <= length; i++)
    {
        res += arr[i] * pow(x, i);
    }
    return res;
}

void output(int length, float* arr, float x, float result)
{
    printf("The Horner' series is:\n");
    printf("p(%0.2f) = %0.2f", x, arr[0]);
    for (int i = 1; i <= length; i++)
    {
        printf(" + %0.2f * %0.2f^%d", arr[i], x, i);
    }
    printf(" = %f\n", result);
}

int main()
{
    int deg = inputDegree();
    float x = inputX();
    float coeff[deg + 1];
    inputCoefficients(deg, coeff);
    float result = evaluate_polynomial(deg, coeff, x);
    output(deg, coeff, x, result);
    return 0;
}
