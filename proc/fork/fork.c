#include <stdio.h>

main()
{
	printf("hello1, pid %d\n", getpid());

	fork();
	printf("hello2, pid %d\n", getpid());

	fork();	
	printf("hello3, pid %d\n", getpid());

	while(1);
}
