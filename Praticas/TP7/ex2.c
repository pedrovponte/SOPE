#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 10000
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int N;


void * thrfunc(void * arg){

    int i = 0;
    int aux = *(int*)arg;
    char s[5];
    sprintf(s, "%d", aux);
    fprintf(stderr, "Starting thread %d\n", aux);
    while (N > 1)
    {
        write(STDERR,arg,1);
        pthread_mutex_lock(&mutex);
        N--;
        i++;
        pthread_mutex_unlock(&mutex);
    }
    void* res = malloc(sizeof(int));
    *(int*) res = i;

    return res;
}

int main(){

    N = 10000;
    pthread_t ta, tb;
    void *t1, *t2;
    int num[2] = {1,2};

    pthread_create(&ta, NULL, thrfunc, &num[0]);
    pthread_create(&tb, NULL, thrfunc, &num[1]);

    pthread_join(ta, &t1);
    pthread_join(tb, &t2);

    fprintf(stderr, "\nThread 1 wrote %d characters\n", *(int*)t1);
    fprintf(stderr, "\nThread 2 wrote %d characters\n", *(int*)t2);

    free(t1);
    free(t2);

    return 0;
}
