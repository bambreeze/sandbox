/*************************************************************************
  > File Name: process_.c
  > Author: Simba
  > Mail: dameng34@163.com
  > Created Time: Sat 23 Feb 2013 02:34:02 PM CST
  利用pipe和dup2函数模拟命令行 ls  | wc -w 功能.

  我们知道命令行 ls | wc -w 中 ls 会输出到管道，而wc 从管道里读取，
  现在使用dup2复制文件描述符，使ls 的标准输出为管道，wc 的标准输入也为管道，
  即使父进程先被调度，因为默认是阻塞I/O操作，故wc 会read 阻塞直到管道被子进程写入了数据。
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
    int pipefd[2];
    if (pipe(pipefd) == -1)
        ERR_EXIT("pipe error");

    pid_t pid;
    pid = fork();
    if (pid == -1)
        ERR_EXIT("fork error");

    if (pid == 0)
    {
        dup2(pipefd[1], STDOUT_FILENO);
        //输出重定向
        close(pipefd[1]);
        close(pipefd[0]);
        execlp("ls", "ls", NULL);
        fprintf(stderr, "error execute ls\n");
        exit(EXIT_FAILURE);
    }

    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    execlp("wc", "wc", "-w", NULL);
    fprintf(stderr, "error execute wc\n");
    exit(EXIT_FAILURE);

    return 0;
}
