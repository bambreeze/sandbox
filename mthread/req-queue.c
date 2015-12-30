#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>  
#include <pthread.h>
#include <semaphore.h>

typedef struct _req_entry {
    int is_v4;
    int is_add;
    int interface;
} req_entry;

typedef struct _req_queue {
    req_entry *entry[16];
    int current;
    int counter;
    int waiting;
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
} req_queue;

req_queue *global_req_queue = NULL;

void handler(int signo)
{
    printf("Exit program.\n");
    exit(0);
}

void *work_thread(void *arg)
{
    req_queue *queue = NULL;
    req_entry *req = NULL;

    queue = arg;
    while (1) {
        sleep(2);

        if (queue->current < queue->counter) {
            pthread_mutex_lock(&queue->mutex);

            req = queue->entry[queue->current];
            queue->current++;
            if (queue->current == 16) {
                queue->current = 0;
            }

            printf("processing...\n");
            printf("  req->is_v4: %d\n", req->is_v4);
            printf("  req->is_add: %d\n", req->is_add);
            printf("  req->interface: 0x%08x\n", req->interface);
            printf("processing done\n");

            queue->waiting = 1;
            printf("before cond wait\n");
            pthread_cond_wait(&queue->cond, &queue->mutex);
            printf("after cond wait\n");
            queue->waiting = 0;
            pthread_mutex_unlock(&queue->mutex);    
        }
    }
}

void *done_thread(void * arg)
{
    req_queue *queue = NULL;

    queue = arg;
    while (1) {
        sleep(3);

        if (queue->waiting) {
            pthread_mutex_lock(&queue->mutex);
            printf("before cond signal\n");
            pthread_cond_signal(&queue->cond);
            printf("after cond signal\n");
            pthread_mutex_unlock(&queue->mutex);    
        }
    }
}

void init_queue(req_queue *queue)
{
    int i = 0;

    for (i = 0; i < 16; i++) {
        queue->entry[i] = NULL;
    }

    queue->current = 0;
    queue->counter = 0;
    queue->waiting = 0;

    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
}

int add_req(req_queue *queue, int is_v4, int is_add, int interface)
{
    req_entry *req = NULL;

    req = malloc(sizeof(req_entry));
    if (!req) {
        printf("malloc req failed\n");
        exit(1);
    }

    req->is_v4       = is_v4;
    req->is_add      = is_add;
    req->interface   = interface;

    pthread_mutex_lock(&queue->mutex);
    queue->entry[queue->counter] = req;
    queue->counter++;
    if (queue->counter == 16) {
        queue->counter = 0;
    }
    pthread_mutex_unlock(&queue->mutex);    

    return 0;
}

int main()
{
    int rc = 0;

    if (signal(SIGINT, handler) == SIG_ERR) {
        printf("Signal error.\n");
        exit(1);
    }

    global_req_queue = malloc(sizeof(req_queue));
    if (!global_req_queue) {
        printf("malloc queue failed\n");
        exit(1);
    }

    init_queue(global_req_queue);
    add_req(global_req_queue, 1, 1, 0x12340001);
    add_req(global_req_queue, 1, 0, 0x12340002);
    add_req(global_req_queue, 0, 1, 0x12340003);
    add_req(global_req_queue, 0, 0, 0x12340004);

    pthread_t work;
    if (pthread_create(&work, NULL, work_thread, global_req_queue) != 0) {
        printf("Creating work thread failed.\n");
        exit(1);
    }

    pthread_t done;
    if (pthread_create(&done, NULL, done_thread, global_req_queue) != 0) {
        printf("Creating done thread failed.\n");
        exit(1);
    }

    printf("main(), wait for thread join\n");
    pthread_join(work, NULL);
    pthread_join(done, NULL);
    printf("main(), join done\n");

    return 0;
}
