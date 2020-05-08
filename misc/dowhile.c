#include <stdio.h>

int main()
{
    int i = 0;
    int j = 3;

    do {
        printf("i = %d\n", i);
    } while (i--);

    printf("\n\n\n");

    do {
        printf("j = %d\n", j);
    } while (--j);

    return 0;
}
