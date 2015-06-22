#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    char cmd[256];
    struct stat buf;
    
    if (stat("mymutex", &buf) == 0) {
        printf("file - %s exist\n", "mymutex");
        printf("Warning: DHCP client and DHCP relay on the same switch is not supported!\n");
        return 1;
    }

    snprintf(cmd, 255, "touch mymutex");
    system(cmd);
    printf("file - %s created!\n", "mymutex");

    return 0;
}
