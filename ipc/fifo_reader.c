/*************************************************************************
  > File Name: process_.c
  > Author: Simba
  > Mail: dameng34@163.com
  > Created Time: Sat 23 Feb 2013 02:34:02 PM CST
 ************************************************************************/
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<signal.h>
#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

int main(int argc, char *argv[])
{
    int outfd = open("myout", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfd == -1)
        ERR_EXIT("open error");

    int infd;
    infd = open("myfifo", O_RDONLY);
    if (infd == -1) {
        printf("can't open fifo\n");
        ERR_EXIT("open error");
    }

    char buf[1024];
    int n;
    while ((n = read(infd, buf, 1024)) > 0)
        write(outfd, buf, n);

    close(infd);
    close(outfd);
    unlink("myfifo"); // delete a name and possibly the file it refers to
    return 0;
}
