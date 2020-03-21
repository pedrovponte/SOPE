#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int v = 0;

void usr_handler(int signo){
    if(signo == SIGUSR1){
        printf("Increasing..\n");
        v++;
    }
    else if(signo == SIGUSR2){
        printf("Decreasing...\n");
        v--;
    }
}

int main(void){
    struct sigaction action;

    action.sa_handler = usr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if(sigaction(SIGUSR1, &action, NULL) < 0){
        fprintf(stderr, "Unable to install SIGUSR1 handler\n");
        exit(1);
    }

    if(sigaction(SIGUSR2, &action, NULL) < 0){
        fprintf(stderr, "Unable to install SIGUSR2 handler\n");
        exit(1);
    }

    while(1){
        sleep(1);
        printf("v = %d\n", v);
    }
}