#include <stdio.h>

int main()
{
    int i = 0;

    for (i = 0; i < 64; i++) {
        printf("i: %d, i << 18: 0x%x\n", i, i << 18);
    }

    return 0;
}
