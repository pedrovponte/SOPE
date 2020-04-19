#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 10000


void * thrfunc(void * arg){

    int i;
    int aux = *(int*)arg;
    fprintf(stderr, "Starting thread %d\n", aux);
    for (i = 1; i <= NUMITER; i++) write(STDERR,arg,1);
    return NULL;
}

int main(){

    pthread_t ta, tb;
    //int i1 = 1, i2 = 2;
    char c1 = '1', c2 = '2';
    pthread_create(&ta, NULL, thrfunc, &c1);
    pthread_create(&tb, NULL, thrfunc, &c2);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0;
}