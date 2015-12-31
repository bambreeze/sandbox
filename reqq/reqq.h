#ifndef REQQ_H
#define REQQ_H

#include <unistd.h>
#include <sys/syscall.h>
#define gettid() (int) syscall(__NR_gettid)

#define BUFLEN 16

typedef struct _req_entry {
    int is_v4;
    int is_add;
    int interface;
} req_entry;

typedef struct _req_queue {
    int in;
    int out;
    int counter;
    req_entry *entry[BUFLEN];
    int waiting;
    pthread_cond_t  cond;
    pthread_mutex_t mutex;
} req_queue;

#endif
