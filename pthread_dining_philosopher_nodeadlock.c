#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t philosopher[5];
pthread_mutex_t ourMutex[5];

void *func(void *threadIdx)
{
    long n = (long)threadIdx;
	printf ("Philosopher %d is thinking\n",n);

	//when philosopher 5 is eating he takes fork 1 and fork 5
	pthread_mutex_lock(&ourMutex[0]);
	printf ("Philosopher %d is eating\n",n);
	sleep(3);
	pthread_mutex_unlock(&ourMutex[0]);

	printf ("Philosopher %d finished eating\n",n);

	return(NULL);
}

int main()
{
	int i;
	for(i=0;i<5;i++)
		pthread_mutex_init(&ourMutex[i],NULL);

	for(i=0;i<5;i++)
		pthread_create(&philosopher[i],NULL,func,(void *)i);

	for(i=0;i<5;i++)
		pthread_join(philosopher[i],NULL);

	for(i=0;i<5;i++)
		pthread_mutex_destroy(&ourMutex[i]);

	return 0;
}
