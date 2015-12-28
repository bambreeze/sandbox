#include <stdio.h>
#include <stdlib.h>

main (void)
{
    int intvar = 100;
    char str[16];

    snprintf(str, sizeof(str), "%d", intvar);
    printf("num: %d, str: %s\n", intvar, str);
}
