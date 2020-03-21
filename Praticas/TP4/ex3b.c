#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

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
    pid_t pid;

    action.sa_handler = usr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if(sigaction(SIGUSR1, &action, NULL) < 0){
        fprintf(stderr, "Unable to install SIGUSR1 hangler\n");
        exit(1);
    }

    if(sigaction(SIGUSR2, &action, NULL) < 0){
        fprintf(stderr, "Unable to install SIGUSR2 hangler\n");
        exit(1);
    }

    if((pid = fork()) > 0){
        int s, signo;
        srand(time(NULL));
        for(int i = 0; i < 50; i++){
            s = rand() % 2 + 1;
            if(s == 1)
                signo = SIGUSR1;
            else
                signo = SIGUSR2;
            kill(pid, signo);
            sleep(1);
        }
    }
    else{
        for(int i = 0; i < 50; i++){
            sleep(1);
            printf("v = %d\n", v);
        }
        exit(1);
    }
    exit(1);
}