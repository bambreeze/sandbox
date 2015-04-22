#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int data = 10;

int child_process()
{
	sleep(1); // make sure parent process running firstly!
	printf("Child process %d, data %d\n",getpid(),data);
	_exit(0);
}

int main(int argc, char* argv[])
{
	int pid = 0;

	pid = fork();
	if (pid == 0) {
		child_process();
	} else {
		printf("Parent process %d, data %d\n",getpid(), data);
		data = 20;
		printf("Parent process %d, data %d\n",getpid(), data);
		sleep(2);
	}
}
