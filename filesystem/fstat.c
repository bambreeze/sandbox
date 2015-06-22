#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    int i = 0;
    char cmd[256];
    char fname[256];
    struct stat buf;
    FILE *fp = NULL;
    int sz = 0;
    char ver[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int version = 0;
    
    for (i = 0; i < 3; i++) {
        snprintf(cmd, 255, "touch blank%d", i);
        system(cmd);
    }

    snprintf(cmd, 255, "echo 18 > version.txt");
    system(cmd);

    for (i = 0; i < 8; i++) {
        snprintf(fname, 255, "blank%d", i);
        if (stat(fname, &buf) == 0)
            printf("file - %s exist\n", fname);
    }

    fp = fopen("version.txt", "r");
    if (!fp) {
        printf("version.txt doesn't exist!\n");
        return 1;
    }

    sz = fread(ver, sizeof(char), 8, fp);
    if (sz <= 0) {
        printf("read version fail!\n");
        return 1;
    }

    for (i = 0; i < sz - 1; i++) {
        if (ver[i] < '0' || ver[i] > '9')
            break;
        version = (version * 10) + (ver[i] - '0');
    }

    printf("version is: %d\n", version);

    return 0;
}
