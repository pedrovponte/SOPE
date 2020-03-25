#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(void){
    int fd[2];
    pid_t pid;

    pipe(fd);

    struct num {
        int num1;
        int num2;
    };

    pid = fork();

    if(pid > 0){
        struct num nums1;
        printf("PARENT:\n");
        printf("x y ? ");
        scanf("%d %d", &nums1.num1, &nums1.num2);
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
        printf("x + y = %d\n", nums2.num1 + nums2.num2);
        printf("x - y = %d\n", nums2.num1 - nums2.num2);
        printf("x * y = %d\n", nums2.num1 * nums2.num2);
        printf("x / y = %f\n", (float)(nums2.num1 / nums2.num2));
        close(fd[READ]);
    }
    return 0;
}