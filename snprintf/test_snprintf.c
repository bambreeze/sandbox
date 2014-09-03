#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    //char str[10] = {0,};
    char str[10];
    char *path = "/var/tmp";

    for (i = 0; i < 10; i++)
        printf("%c ", str[i]);
    printf("\n");

    printf("%s\n", str);
    snprintf(str, sizeof(str), "%s", path);
    printf("%s\n", str);

    return 0;
}
