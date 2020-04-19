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
    exit(0);
}

//Teoricamente, usando o pthread_exit() evita-se que todas as threads terminem quando a thread principal terminar independentemente de estarem ou nao em execuçao, algo que acontece quando se usa o exit
//Como se pode ver ao executar o programa, este não vai executar como esperado, vai faltar sempre um hello ou entao vão saltar numeros