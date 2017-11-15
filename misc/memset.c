#include <stdio.h>

int main()
{
    int data[3];

    printf("data[0]: %d\n", data[0]);
    printf("data[1]: %d\n", data[1]);
    printf("data[2]: %d\n", data[2]);

    printf("sizeof data[3]: %lu\n", sizeof(data));

    return 0;
}
