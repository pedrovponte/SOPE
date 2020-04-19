#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>

void *Sum(void *op){
    int *aux = (int*) op;

    void *res = malloc(sizeof(int));
    *(int *) res = aux[0] + aux[1];
    return res;
}

void *Sub(void *op){
    int *aux = (int*) op;

    void *res = malloc(sizeof(int));
    *(int *) res = aux[0] - aux[1];
    return res;
}

void *Mul(void *op){
    int *aux = (int*) op;

    void *res = malloc(sizeof(int));
    *(int *) res = aux[0] * aux[1];
    return res;
}

void *Div(void *op){
    int *aux = (int*) op;

    void *res = malloc(sizeof(int));
    *(int *) res = aux[0] / aux[1];
    return res;
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

    void *sum, *sub, *mul, *div;

    pthread_join(tsum, &sum);
    pthread_join(tsub, &sub);
    pthread_join(tmul, &mul);
    pthread_join(tdiv, &div);

    printf("Sum: %d\n", *(int*)sum);
    printf("Sub: %d\n", *(int*)sub);
    printf("Mul: %d\n", *(int*)mul);
    printf("Div: %d\n", *(int*)div);

    pthread_exit(0);
}