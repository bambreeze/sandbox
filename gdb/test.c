#include <stdio.h>

int add (int a, int b)
{
    int aa = 0;
    int bb = 0;
    int sum = 0;

    aa = a;
    bb = b;
    sum = aa + bb;

    return sum;
}

int main (void)
{
    int x = 2;
    int y = 3;
    int result = 0;

    result = add (x, y);

    printf("The result is: %d\n", result);
}
