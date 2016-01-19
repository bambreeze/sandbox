#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    FILE *file;
    unsigned long filesize1 = -1;
    unsigned long filesize = -1;
    struct stat statbuff;
    char cmds[100];
    char cmds1[100];
    char cmds2[100];

    memset(cmds, 0, 100);
    memset(cmds1, 0, 100);
    memset(cmds2, 0, 100);

    if ((file = fopen("a.conf", "r")) == NULL)
        return -1;

    if (stat("a.conf", &statbuff) < 0) {
        return -1;
    } else {
        filesize1 = statbuff.st_size;
    }

    if (fread(cmds1, 1, filesize1, file) <= 0) {
        fclose(file);
        return -1;
    }
    fclose(file);

    printf("a.conf filesize: %d\n", filesize1);
    strncpy(cmds, cmds1, filesize1);
    //cmds[filesize1] ='\r\n';
    cmds[filesize1] ='\0';

    if ((file = fopen("b.conf", "r")) == NULL)
        return -1;

    if (stat("b.conf", &statbuff) < 0) {
        return -1;
    } else {
        filesize = statbuff.st_size;
    }

    if (fread(cmds2, 1, filesize, file) <= 0) {
        fclose(file);
        return -1;
    }
    fclose(file);

    printf("b.conf filesize: %d\n", filesize);
    strncpy(cmds+filesize1, cmds2, filesize);

    //printf("cmd: %s\n", cmds);
    int i = 0;
    for (i = 0; i < 20; i++) {
        printf("%x ", cmds[i]);
    }

    return 0;
}
