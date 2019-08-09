#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LOOP_NUM 5000

int counter;
void *doit(void *);
pthread_mutex_t mutex;	//声明互斥锁;

int main(int argc, char **argv)
{

	pthread_t tidA, tidB;
	if(pthread_mutex_init(&mutex, NULL) == 0)
	{
		printf("互斥锁初始化成功!\n");
	}
	else
	{
		printf("互斥锁初始化失败!\n");
	}
	

	pthread_create(&tidA, NULL, &doit, NULL);
	pthread_create(&tidB, NULL, &doit, NULL);

	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	printf("counter: %d\n", counter);

	return 0;
}

void *doit(void *vptr)
{
	int i,val;

	for(i=0;i<LOOP_NUM;i++)
	{
		pthread_mutex_lock(&mutex);

		val = counter;
		printf("%x: %d\n", (unsigned int)pthread_self(), val+1);
		counter = val+1;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
