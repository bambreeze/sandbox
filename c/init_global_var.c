#include <stdio.h>

unsigned int global_var[5] = {8};

int main()
{
    int i = 0;

    for (i = 0; i < 5; i++) {
        printf("data[%d]: %d\n", i, global_var[i]);
    }

    return 0;
}
