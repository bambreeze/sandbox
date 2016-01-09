/*
 * Build: 
 *   gcc -pthread -o cmdq cmdq.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>  
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "cmdq.h"

cmd_queue *global_cmd_queue = NULL;
int global_interface = 0x12340000;

void handler1(int signo)
{
    int interface = 0;

    interface = global_interface;  
    global_interface++;

    printf("\n  ==> add comd, interface: 0x%08x\n", interface);
    add_cmd(global_cmd_queue, interface);
}

void *worker_thread(void *arg)
{
    cmd_queue *queue = NULL;
    cmd_entry *cmd = NULL;
    int pending_cmd = 0;

    time_t t;
    time(&t);

    queue = arg;
    while (1) {
        pthread_mutex_lock(&queue->mutex);
        pending_cmd = queue->counter;
        pthread_mutex_unlock(&queue->mutex);    

        if (pending_cmd) {
            // get one command
            pthread_mutex_lock(&queue->mutex);
            cmd = queue->entry[queue->out];
            queue->counter--;
            queue->entry[queue->out] = NULL;
            queue->out++;
            if (queue->out == CMDQLEN) {
                queue->out = 0;
            }
            pthread_mutex_unlock(&queue->mutex);    

            printf("\nexecute commands...\n");
            printf("  cmd->interface: 0x%08x\n", cmd->interface);
            printf("done\n\n");

            printf("\n  <== free cmd ... interface: 0x%08x\n\n", cmd->interface);
            free(cmd);
            cmd = NULL;
        } else {
            printf("[pid %d] no pending command...\n", gettid());
            sleep(1);
        }
    }
}

int add_cmd(cmd_queue *queue, int interface)
{
    cmd_entry *cmd = NULL;

    if (queue->counter == CMDQLEN) {
        printf("\n!!! cmd-queue is full, will discard cmd !!!\n");
        return 1;
    }

    cmd = malloc(sizeof(cmd_entry));
    if (!cmd) {
        printf("malloc cmd failed\n");
        exit(1);
    }

    cmd->interface   = interface;
    // FIXME
    //cmd->cmd   = interface;
    //cmd->fname   = interface;

    pthread_mutex_lock(&queue->mutex);
    queue->entry[queue->in] = cmd;
    queue->counter++;
    queue->in++;
    if (queue->in == CMDQLEN) {
        queue->in = 0;
    }
    pthread_mutex_unlock(&queue->mutex);    

    return 0;
}

void init_queue(cmd_queue *queue)
{
    int i = 0;

    for (i = 0; i < CMDQLEN; i++) {
        queue->entry[i] = NULL;
    }

    queue->in = 0;
    queue->out = 0;
    queue->counter = 0;

    pthread_mutex_init(&queue->mutex, NULL);
}

int main()
{
    int rc = 0;

    // install signal hander
    if (signal(SIGHUP, handler1) == SIG_ERR) {
        printf("Signal error.\n");
        exit(1);
    }

    // init cmd-queue
    global_cmd_queue = malloc(sizeof(cmd_queue));
    if (!global_cmd_queue) {
        printf("malloc queue failed\n");
        exit(1);
    }

    init_queue(global_cmd_queue);

    // create threads
    pthread_t worker;
    if (pthread_create(&worker, NULL, worker_thread, global_cmd_queue) != 0) {
        printf("Creating worker thread failed.\n");
        exit(1);
    }

    printf("[pid %d] main(), waiting for thread join...\n", gettid());
    pthread_join(worker, NULL);
    printf("[pid %d] main(), thread join done\n", gettid());

    return 0;
}
