#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    int timeout = 0;

    srand((unsigned) time(&t));
    timeout = 2 + (rand() % 4);
    //printf("sleep %ds...\n", timeout);
    sleep(timeout);

    return 1;
}
