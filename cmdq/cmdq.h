#ifndef CMDQ_H
#define CMDQ_H

#include <unistd.h>
#include <sys/syscall.h>
#ifndef __NR_gettid
#define gettid() getpid()
#else
#define gettid() (int) syscall(__NR_gettid)
#endif

#define STRLEN  256
#define CMDQLEN 256

typedef struct _cmd_entry {
    int interface;
    char cmd[STRLEN];
    char fname[STRLEN];
} cmd_entry;

typedef struct _cmd_queue {
    int in;
    int out;
    int counter;
    cmd_entry *entry[CMDQLEN];
    pthread_mutex_t mutex;
} cmd_queue;

#endif
