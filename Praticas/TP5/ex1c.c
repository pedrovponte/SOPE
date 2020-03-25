#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(void){
    int fd[2];
    pid_t pid;

    pipe(fd);

    struct num {
        char num1[6];
        char num2[6];
    };

    pid = fork();

    if(pid > 0){
        struct num nums1;
        printf("PARENT:\n");
        printf("x y ? ");
        scanf("%s %s", nums1.num1, nums1.num2);
        close(fd[READ]);
        write(fd[WRITE], &nums1, sizeof(struct num));
        close(fd[WRITE]);
    }
    else{
        struct num nums2;
        //printf("SON:\n");
        close(fd[WRITE]);
        read(fd[READ], &nums2, sizeof(struct num));
        printf("SON:\n");
        printf("x + y = %d\n", atoi(nums2.num1) + atoi(nums2.num2));
        printf("x - y = %d\n", atoi(nums2.num1) - atoi(nums2.num2));
        printf("x * y = %d\n", atoi(nums2.num1) * atoi(nums2.num2));
        printf("x / y = %f\n", (float) atoi(nums2.num1) / atoi(nums2.num2));
        close(fd[READ]);
    }
    return 0;
}