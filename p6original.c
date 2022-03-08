/*
Write a program to count the number of words in a string using strtok ( string.h)
void input_string(char *a);
int count_words(char *string);
void output(char *string, int no_words);
input:
hello world hello
*/

#include <stdio.h>
#include <string.h>

void inputString(char* a)
{
    printf("Enter a string: ");
    fgets(a, 23, stdin);
}

int countWords(const char* string)
{
    char copyOfString[25];
    strcpy(copyOfString, string);
    int count = 0;
    const char* delimeter = " ";
    char* portion = strtok(copyOfString, delimeter);

    while (portion != NULL)
    {
        count++;
        portion = strtok(NULL, delimeter);
    }
    return count;
}

void output(char* string, int count)
{
    printf("The number of words in \"%s\" is %d\n", string, count);
}

int main()
{
    char str[25];
    inputString(str);
    int count = countWords(str);
    output(str, count);
    return 0;
}