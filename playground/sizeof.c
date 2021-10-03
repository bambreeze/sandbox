#include "stdio.h"

void UpperCase (char str[])
{
    for (size_t i = 0; i < sizeof(str) /sizeof(str[0]); ++i) {
        if( str[i] >= 'a' && str[i] <= 'z' ) {
            str[i] -= ('a'-'A' ); 
        } 
    }
}

int main() 
{
#if 0
    char str[] = "aBcDe";
    printf("The length is: %d\n", sizeof(str)/sizeof(str[0]));
    UpperCase(str);
    printf("The UpperCase is: %s\n", str);

    int a[5]={1,2,3,4,5};
    int *ptr=(int *)(&a+1);
    printf("%d,%d\n",*(a+1),*(ptr-1));
#endif

    char aa;
    char *str=&aa;
    strcpy(str,"hello");
    printf(str);

    printf("sizeof(short): %d, sizeof(int): %d, sizeof(long): %d\n", sizeof(short), sizeof(int), sizeof(long));

    int x = 3;
    int y = x << 3;
    printf("y: %d\n", y);

    char msg[] = "Hello, Cisco!";
    printf("sizeof(msg): %d, strlen(msg): %d\n", sizeof(msg), strlen(msg));

#define MAX_NUM 100+200
    int nTemp = MAX_NUM*10;
    printf("nTemp: %d\n", nTemp);

    return 0;
} 
