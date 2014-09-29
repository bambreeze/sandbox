#include <stdio.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc, char* argv[])
{
    key_t key = ftok("./mark", 'a');
    int shmid = shmget(key, 100, 0600);
    void* buf = (void*)shmat(shmid, NULL, 0);

    printf("shared memory: %s\n", buf);
    sleep(8);
    printf("shared memory: %s\n", buf);

    if ( -1 == shmdt(buf) ) {
        fprintf(stderr, "%s\n",
                strerror(errno));
        exit(1);
    }

    printf("consumer exited normally\n");
    return 0;
}
