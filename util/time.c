#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(void)
{
    time_t t;
    struct timeval tv;
    unsigned char *buf;
    char str[256];

    time(&t);
    printf("Today's date and time: %s\n", ctime(&t));

    gettimeofday(&tv, NULL);
    buf = ctime(&tv.tv_sec);

    // TODO
    //buf = 0;

    buf[strlen(buf)-1] = 0;
    //fprintf(dhclient_logfile, "%s:", buf);
    snprintf(str, sizeof(str), "%s:", buf);
    printf("%s\n", str);

    return 0;
}
