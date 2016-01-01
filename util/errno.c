#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    int i;
    for(i = 0; i < 140; ++i) {
        errno = i;
        printf("errno %d:\t%s\n", i, strerror(errno));
    }

    return 0;
}
