#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo)
{
    printf("\nIn SIGINT handler ...\n");
}

void sigusr1_handler(int signo)
{
    printf("\nIn SIGUSR1 handler ...\n");
}

int main(void)
{
    if (signal(SIGINT, sigint_handler) < 0)
    {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    if (signal(SIGUSR1, sigusr1_handler) < 0)
    {
        fprintf(stderr, "Unable to install SIGUSR1 handler\n");
        exit(1);
    }

    printf("Sleeping for 30 seconds ...\n");
    //raise(SIGUSR1);
    sleep(30);
    printf("Waking up ...\n");
    exit(0);
}