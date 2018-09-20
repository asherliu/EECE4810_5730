/******************************************************************************
 * Compilation command: gcc -lpthread pthread_hello_world.c -o pthread_hello_world.bin
 * Execution: ./pthread_hello_world.bin
 * ******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    
    //Child thread needs to first exit
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;

    int rc;
    long t;
    
    //Getting attribute 
    pthread_attr_init(&attr);

    for(t=0;t<NUM_THREADS;t++){
        printf("In main: creating thread %ld\n", t);

        //Creating threads
        rc = pthread_create(&threads[t], &attr, PrintHello, (void *)t);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    //Joining the child threads
    for(t=0;t<NUM_THREADS;t++){
        pthread_join(threads[t], NULL);
    }

    return 0;
}
