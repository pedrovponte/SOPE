#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#define NUM_THREADS 10 

void *PrintHello(void *threadnum){
    sleep(1);
    printf("Hello from thread no. %d!\n", *(int *)threadnum);

    void *res = malloc(sizeof(int));
    *(int *) res = *(int *) threadnum;
    return res;
 }

 int main(){
    pthread_t threads[NUM_THREADS];
    //void *res;

    for(int t = 1; t <= NUM_THREADS; t++){
        printf("Creating thread %d\n", t);
        pthread_create(&threads[t - 1], NULL, PrintHello, (void *)&t);
        pthread_join(threads[t - 1], NULL);                           //pthread_join(threads[t -1], &res);
    }
    pthread_exit(0);
 }