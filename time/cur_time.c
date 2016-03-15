#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MILLION 1000000
#define NANO 1000000000L

// buf needs to store 30 characters
int timespec2str(char *buf, unsigned int len, struct timespec *ts) 
{
    int ret;
    struct tm t;

    tzset();
    if (localtime_r(&(ts->tv_sec), &t) == NULL)
        return 1;

    ret = strftime(buf, len, "%F %T", &t);
    if (ret == 0)
        return 2;
    len -= ret - 1;

    ret = snprintf(&buf[strlen(buf)], len, ".%09ld", ts->tv_nsec);
    if (ret >= len)
        return 3;

    return 0;
}

int main(void)
{
    long int loop = 1000;
    struct timespec tpstart;
    struct timespec tpend;
    long timedif;
    struct timespec cur;
    time_t rawtime;
    struct tm * timeinfo;
    const unsigned int TIME_FMT = strlen("2012-12-31 12:59:59.123456789") + 1;
    char timestr[TIME_FMT];

    clock_gettime(CLOCK_MONOTONIC, &tpstart);
    printf ("The current local time is: %s", ctime (&(tpstart.tv_sec)));

    while (--loop){
        system("cd");
    }

    clock_gettime(CLOCK_MONOTONIC, &tpend);
    printf ("The current local time is: %s", ctime (&(tpend.tv_sec)));

    timedif = MILLION*(tpend.tv_sec-tpstart.tv_sec)+(tpend.tv_nsec-tpstart.tv_nsec)/1000;
    fprintf(stdout, "it took %ld microseconds\n", timedif);

    printf("=== test 1 ===\n");
    time (&rawtime);
    printf ("The current local time is: %s", ctime (&rawtime));

    printf("=== test 2 ===\n");
    //clock_gettime(CLOCK_MONOTONIC, &cur);
    clock_gettime(CLOCK_REALTIME, &cur);
    printf ("The current local time is: %s", ctime(&cur.tv_sec));

    printf("=== test 3 ===\n");
    //time (&rawtime);
    //timeinfo = localtime (&rawtime);
    //clock_gettime(CLOCK_MONOTONIC, &cur);
    clock_gettime(CLOCK_REALTIME, &cur);
    timeinfo = localtime(&cur.tv_sec);
    printf ("Current local time and date: %s", asctime(timeinfo));

    printf("=== test 4 ===\n");
    //clock_gettime(CLOCK_MONOTONIC, &cur);
    clock_gettime(CLOCK_REALTIME, &cur);
    timespec2str(timestr, TIME_FMT, &cur);
    printf ("Current local time and date: %s\n", timestr);

    return 0;
}
