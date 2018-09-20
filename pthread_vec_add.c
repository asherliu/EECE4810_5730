/******************************************************************************
 * Compilation command: gcc -lpthread pthread_vec_add.c -o pthread_vec_add.bin
 * Execution: ./pthread_vec_add.bin
 * ******************************************************************************/


// CPP Program to find sum of array 
#include <stdio.h> 
#include <pthread.h> 
#include <assert.h>
#include <stdlib.h>

// size of array 
#define MAX 16 

// maximum number of threads 
#define MAX_THREAD 4 


typedef struct param{
    int *vec_a;
    int *vec_b;
    int *vec_res;
    int my_beg;
    int my_end;
} param_t;

void* sum_array(void* param) 
{ 
    //sleep(2);    
    param_t *my_param = (param_t *)param;
//    printf("Thread will be working on %d ~ %d\n", my_param->my_beg, my_param->my_end);

	// Each thread computes the sum for a quarter range 
	for (int i = my_param->my_beg; i < my_param->my_end; i ++)
        my_param->vec_res[i] = my_param->vec_a[i] + my_param->vec_b[i];
    pthread_exit(NULL);

} 

// Driver Code 
int main(int args, char **argv) 
{ 
	
    assert(MAX%MAX_THREAD == 0);
	pthread_t threads[MAX_THREAD]; 
    pthread_attr_t attr;
    
    int *vec_a = (int *)malloc(sizeof(int)*MAX);
    int *vec_b = (int *)malloc(sizeof(int)*MAX);
    int *vec_res = (int *)malloc(sizeof(int)*MAX);
    

    //Init vec
    for(int i = 0; i < MAX; i++)
    {
        vec_a[i] = rand()%89;
        vec_b[i] = rand()%59;
    }
    

	// Creating 4 threads 
    pthread_attr_init(&attr);
    int step = MAX/MAX_THREAD;
	for (int i = 0; i < MAX_THREAD; i++)
    {
        param_t *my_param = (param_t*)malloc(sizeof(param_t));
        my_param->vec_a = vec_a;
        my_param->vec_b = vec_b;
        my_param->vec_res = vec_res;
        
        my_param->my_beg = step * i;
        my_param->my_end = step * (i+1);


        printf("Thread %d will be working on %d ~ %d\n", i, my_param->my_beg, my_param->my_end);
		pthread_create(&threads[i], &attr, sum_array, (void*) my_param); 
    }

	// joining 4 threads i.e. waiting for all 4 threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL); 

	// adding sum of all 4 parts 
	for (int i = 0; i < MAX; i++) 
        printf("%d + %d = %d\n",  vec_a[i],  vec_b[i], vec_res[i]); 		 

    
    free(vec_a);
    free(vec_b);
    free(vec_res);
	return 0; 
} 
