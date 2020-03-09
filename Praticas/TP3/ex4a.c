#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    pid_t PID;

    PID = fork();

    if(PID > 0){
        wait(0);
        printf("World! \n");
    }
    else if(PID == 0){
        printf("Hello ");
    }
    else{
        perror("fork");
    }
    return 0;
}