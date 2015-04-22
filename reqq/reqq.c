/*
 * Build: 
 *   gcc -pthread -o reqq reqq.c
 *
 * Usage: how to add request to queue
 *   pkill -3 reqq: v4, add
 *   pkill -4 reqq: v4, del
 *   pkill -5 reqq: v6, add
 *   pkill -6 reqq: v6, del
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
#include "reqq.h"

req_queue *global_req_queue = NULL;
int global_interface = 0x12340000;

void handler1(int signo)
{
    int interface = 0;

    interface = global_interface;  
    global_interface++;

    printf("\n  ==> ipv4, add, interface: 0x%08x\n", interface);
    add_req(global_req_queue, 1, 1, interface);
}

void handler2(int signo)
{
    int interface = 0;

    interface = global_interface;  
    global_interface++;

    printf("\n  ==> ipv4, del, interface: 0x%08x\n", interface);
    add_req(global_req_queue, 1, 0, interface);
}

void handler3(int signo)
{
    int interface = 0;

    interface = global_interface;  
    global_interface++;

    printf("\n  ==> ipv6, add, interface: 0x%08x\n", interface);
    add_req(global_req_queue, 0, 1, interface);
}

void handler4(int signo)
{
    int interface = 0;

    interface = global_interface;  
    global_interface++;

    printf("\n  ==> ipv6, del, interface: 0x%08x\n", interface);
    add_req(global_req_queue, 0, 0, interface);
}

void *workerer_thread(void *arg)
{
    req_queue *queue = NULL;
    req_entry *req = NULL;

    time_t t;
    time(&t);

    queue = arg;
    while (1) {
        pthread_mutex_lock(&queue->mutex);
        if (queue->counter) {
            // get one request
            req = queue->entry[queue->out];
            queue->counter--;
            queue->entry[queue->out] = NULL;
            queue->out++;
            if (queue->out == BUFLEN) {
                queue->out = 0;
            }

            printf("\nprocessing...\n");
            printf("  req->is_v4: %d\n", req->is_v4);
            printf("  req->is_add: %d\n", req->is_add);
            printf("  req->interface: 0x%08x\n", req->interface);
            printf("processing done\n\n");

            time(&t);
            printf("before cond wait - %s", ctime(&t));
            queue->waiting = 1;
            pthread_cond_wait(&queue->cond, &queue->mutex);
            queue->waiting = 0;
            time(&t);
            printf("after cond wait - %s", ctime(&t));

            printf("\n  <== free req ... interface: 0x%08x\n\n", req->interface);
            free(req);
            req = NULL;

            pthread_mutex_unlock(&queue->mutex);    
        } else {
            pthread_mutex_unlock(&queue->mutex);    
            printf("[pid %d] no req...\n", gettid());
            sleep(1);
        }
    }
}

void *notifier_thread(void * arg)
{
    req_queue *queue = NULL;

    time_t t;
    srand((unsigned) time(&t));

    queue = arg;
    while (1) {
        sleep((rand() % 2));

        pthread_mutex_lock(&queue->mutex);
        if (queue->waiting) {
            time(&t);
            printf("before cond signal - %s", ctime(&t));
            pthread_cond_signal(&queue->cond);
            time(&t);
            printf("after cond signal - %s", ctime(&t));
            pthread_mutex_unlock(&queue->mutex);    
        } else {
            pthread_mutex_unlock(&queue->mutex);    
            printf("[pid %d] no pending...\n", gettid());
        }
    }
}

int add_req(req_queue *queue, int is_v4, int is_add, int interface)
{
    req_entry *req = NULL;

    if (queue->counter == BUFLEN) {
        printf("\n!!! req-queue is full, will discard req !!!\n");
        return 1;
    }

    req = malloc(sizeof(req_entry));
    if (!req) {
        printf("malloc req failed\n");
        exit(1);
    }

    req->is_v4       = is_v4;
    req->is_add      = is_add;
    req->interface   = interface;

    pthread_mutex_lock(&queue->mutex);
    queue->entry[queue->in] = req;
    queue->counter++;
    queue->in++;
    if (queue->in == BUFLEN) {
        queue->in = 0;
    }
    pthread_mutex_unlock(&queue->mutex);    

    return 0;
}

void init_queue(req_queue *queue)
{
    int i = 0;

    for (i = 0; i < BUFLEN; i++) {
        queue->entry[i] = NULL;
    }

    queue->in = 0;
    queue->out = 0;
    queue->counter = 0;
    queue->waiting = 0;

    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
}

int main()
{
    int rc = 0;

    // install signal hander
    if (signal(SIGQUIT, handler1) == SIG_ERR) {
        printf("Signal error.\n");
        exit(1);
    }

    if (signal(SIGILL, handler2) == SIG_ERR) {
        printf("Signal error.\n");
        exit(1);
    }

    if (signal(SIGTRAP, handler3) == SIG_ERR) {
        printf("Signal error.\n");
        exit(1);
    }

    if (signal(SIGABRT, handler4) == SIG_ERR) {
        printf("Signal error.\n");
        exit(1);
    }

    // init req-queue
    global_req_queue = malloc(sizeof(req_queue));
    if (!global_req_queue) {
        printf("malloc queue failed\n");
        exit(1);
    }

    init_queue(global_req_queue);

    // create threads
    pthread_t worker;
    if (pthread_create(&worker, NULL, workerer_thread, global_req_queue) != 0) {
        printf("Creating worker thread failed.\n");
        exit(1);
    }

    pthread_t notifier;
    if (pthread_create(&notifier, NULL, notifier_thread, global_req_queue) != 0) {
        printf("Creating notifier thread failed.\n");
        exit(1);
    }

    printf("[pid %d] main(), waiting for thread join...\n", gettid());
    pthread_join(worker, NULL);
    pthread_join(notifier, NULL);
    printf("[pid %d] main(), thread join done\n", gettid());

    return 0;
}
