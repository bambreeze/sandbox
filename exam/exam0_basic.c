#include <stdio.h>
#include <string.h>

void func1 (void)
{
    printf("sizeof(short): %d\n", sizeof(short));
    printf("sizeof(int): %d\n", sizeof(int));
    printf("sizeof(long): %d\n", sizeof(long));
}

void func2 (void)
{
    char x;
    char *str=&x;
    //FIXME
    //char x[6];
    //char *str=x;
    strcpy(str,"hello");
    printf(str);
}

void func3 (void)
{
    int a[5]={1,2,3,4,5};
    int *ptr=(int *)(&a+1);

    printf("%d,%d",*(a+1),*(ptr-1));
}

int main()
{
    func1();
    func2();
    func3();

    return 0;
}
