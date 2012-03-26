#include <stdio.h>
#include <stdlib.h>

void do_something_firstly()
{
    char *str = NULL;

    str = malloc(100);
    free(str);
}

void do_something_finally()
{
    printf("Bingo!\n");
}

int main()
{
    printf("Hello, call tree :-)\n");

    do_something_firstly();
    do_something_finally();

    return 0;
}
