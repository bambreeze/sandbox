#include <stdio.h>

int main()
{
    union a { int i; char c[2]; } u1;
    int bs;

    u1.i = 0;
    u1.c[0]=10; 
    u1.c[1]=1; 
    bs = u1.i; 

    //expected output 266 
    printf("Union test: 0x%x, %d\n", u1.i, bs);
    printf("The result is: %d\n", ((int *)(0)+5));

    return 0;
}
