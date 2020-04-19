#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>

void *Sum(void *op){
    int *aux = (int*) op;

    printf("Sum: %d\n", aux[0] + aux[1]);
    return NULL;
}

void *Sub(void *op){
    int *aux = (int*) op;

    printf("Sub: %d\n", aux[0] - aux[1]);
    return NULL;
}

void *Mul(void *op){
    int *aux = (int*) op;

    printf("Mul: %d\n", aux[0] * aux[1]);
    return NULL;
}

void *Div(void *op){
    int *aux = (int*) op;

    printf("Div: %d\n", aux[0] / aux[1]);
    return NULL;
}

int main(){
    int *args = (int*) malloc(sizeof(int) * 2);
    pthread_t tsum, tsub, tmul, tdiv;

    printf("Insert 2 numbers: ");
    scanf("%d %d", &args[0], &args[1]);

    pthread_create(&tsum, NULL, Sum, (void*)args);
    pthread_create(&tsub, NULL, Sub, (void*)args);
    pthread_create(&tmul, NULL, Mul, (void*)args);
    pthread_create(&tdiv, NULL, Div, (void*)args);

    pthread_join(tsum, NULL);
    pthread_join(tsub, NULL);
    pthread_join(tmul, NULL);
    pthread_join(tdiv, NULL);

    pthread_exit(0);
}