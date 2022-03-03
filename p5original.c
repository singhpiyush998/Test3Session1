/*
write a program to find the index of the largest number in an array.
int input_size();
void input_array(int n, int a[n]);
int find_largest(int n, int a[n]);
void out_put(int n, int a[n], int largest)
*/
#include <stdio.h>

int inputSize()
{
    int size;
    printf("Enter the length of the array: ");
    scanf("%d", &size);
    return size;
}

void input_array(int length, int* arr)
{
    printf("Enter %d elemets of array seperated by spaces:\n", length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", arr + i);
    }
}

int find_largest(int n, int* a)
{
    int largestNumberIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[largestNumberIndex])
        {
            largestNumberIndex = i;
        }
    }
    return largestNumberIndex;
}

void output(int res)
{
    printf("The Index of largest number of the above array is: %d\n", res);
}

int main()
{
    int length = inputSize();
    int data[length];
    input_array(length, data);
    int largestElementIndex = find_largest(length, data);
    output(largestElementIndex);
    return 0;
}
