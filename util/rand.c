#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
    int i;
    time_t t;
    srand((unsigned) time(&t));
    printf("Ten random numbers from 0 to 99\n\n");
    for(i=0; i<10; i++)
        printf("%d\n", rand() % 100);
    return 0;
}
