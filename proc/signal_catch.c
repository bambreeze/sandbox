#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/* 
 * $ kill -l
 * ...
 * 6) SIGABRT
 * ...
 *
 * For those curious, the status code is 128 plus the signal that was caught. 
 * 134 - 128 = 6. Signal 6 is SIGABRT.
 */
void my_sig_hander(int sig)
{
    printf("got the signal %d...\n", sig);
    //exit(0);
}

main()
{
    if (signal(6, my_sig_hander) == SIG_ERR) {
        perror("cannot reset the SIGABRT signal handler");
        return 1;
    }

    while(1);
}
