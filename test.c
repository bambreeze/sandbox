#include <stdio.h>
#include "test.h"

unsigned int global_var[5] = {8};

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
    int i = 0;
    int x = 2;
    int y = 3;
    int result = 0;

    // add
    result = add (x, y);
    printf("The result is: %d\n", result);

    // verify init of global variable
    for (i = 0; i < 5; i++) {
        printf("global variable init, data[%d]: %d\n", i, global_var[i]);
    }

    return 0;
}
