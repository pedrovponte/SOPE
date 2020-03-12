#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main(){
    pid_t PID;

    PID = fork();

    if(PID > 0){
        printf("Hello ");
    }
    else if(PID == 0){
        printf("World!\n");
    }
    else{
        perror("fork");
    }
    return 0;
}