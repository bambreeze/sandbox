#include <stdio.h>

main()
{
    char x;
    char *str=&x;
    strcpy(str,"hello");
    printf(str);
    return 0;

    int a[5]={1,2,3,4,5};
    int *ptr=(int *)(&a+1);

    printf("%d,%d",*(a+1),*(ptr-1));

    printf("sizeof(short): %d\n", sizeof(short));
    printf("sizeof(int): %d\n", sizeof(int));
    printf("sizeof(long): %d\n", sizeof(long));
}
