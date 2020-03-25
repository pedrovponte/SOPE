#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>

#define READ 0
#define WRITE 1
#define MAX 256

int main(int argc, char * argv[]){
    if(argc != 2){
        perror("Invalid number of arguments");
        return 1;
    }

    int fd[2], n;
    pid_t pid;
    int file;
    char name[MAX];

    file = open(argv[1], O_RDONLY);

    pid = fork();

    if(pipe(fd) == -1){
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    if(file == -1){
        perror("Error opening file");
        return 0;
    }

    if(pid > 0){
        close(fd[READ]);
        while((n = read(file, name, MAX))){
            write(fd[WRITE], name, n);
        }
        close(fd[WRITE]);
        wait(NULL);
    }
    else{
        close(fd[WRITE]);
        dup2(fd[READ], STDIN_FILENO);
        execlp("sort", "sort", NULL);
        close(fd[READ]);
    }
    return 0;
}