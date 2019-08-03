#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* myfunc(void* args);
void printids(char *s);

int main()
{
	pthread_t th;
	
	printids("main thread:");
	pthread_create(&th, NULL, myfunc, "new thread:");
	pthread_join(th, NULL);
	
	printf("main thread over.\n");
	return 0;
}

void* myfunc(void* args)
{
	printids(args);
	printf("Hello, world!\n");
	return NULL;
}

void printids(char *s)
{
	pid_t		pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s \tpid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int)tid,(unsigned int)tid);
}
