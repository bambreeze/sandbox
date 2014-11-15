#include <stdio.h>

int main()
{
    int *poison = NULL;

    //poison = malloc(sizeof(int));
    //*poison = 0x5A5AA5A5;
    poison = 0xa94000e0;
    printf("Address: 0x%08x, Value: 0x%08x\n", (int)poison, *poison);

    return 0;
}
