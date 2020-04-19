#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10

void *PrintHello(void *threadnum)
{
    printf("Hello from thread no. %d!\n", *(int *)threadnum);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %d\n", t);
        pthread_create(&threads[t], NULL, PrintHello, (void *)&t);
    }
    pthread_exit(0);
}

//o resultado não é o esperado pois a thread seguinte não espera que a anterior termine para executar, fazendo com que por vezes o numero da thread já tenha avançado sem que a anterior tivesse imprimido