#include "stdio.h"
#include <sys/socket.h>

int netmask2len (const char *network)
{
    int i = 0;
    int n = 0;

    inet_pton(AF_INET, network, &n);
    while (n > 0) {
        n = n >> 1;
        i++;
    }

    return i;
}

int main(void)
{
    int len = 0;
    char *mask = NULL;
    
    mask = "0.0.0.0";
    len = netmask2len (mask);
    printf("network = %s, suffix = %d\n", mask, len);

    mask = "255.0.0.0";
    len = netmask2len (mask);
    printf("network = %s, suffix = %d\n", mask, len);

    mask = "255.255.0.0";
    len = netmask2len (mask);
    printf("network = %s, suffix = %d\n", mask, len);

    mask = "255.255.255.0";
    len = netmask2len (mask);
    printf("network = %s, suffix = %d\n", mask, len);

    return 0;
}
