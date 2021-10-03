#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int prime(int num)
{
    int tgt = 0, j = 0;
    for (tgt = 3; tgt <= num; tgt++) {
        for (j = 2; j < tgt; j++) {
            if (tgt % j == 0) {
                break;
            }
        }

        if (j == tgt) {
            printf("%d  ", tgt);
        }
    }

    return 0;
}

int main (void)
{
    int i;

    prime(20);

    return 0;
}
