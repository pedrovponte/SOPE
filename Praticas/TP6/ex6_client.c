#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int fd, fd1;
  if(argc != 3){
    printf("Usage: ./client int1 int2\n");
    exit(1);
  }
  fd = open("./fifo_req", O_WRONLY);
  if(fd == -1){
    printf("Server is closed\n");
    exit(1);
  }
  printf("FIFO is openned in WRITEONLY mode\n");
  char line[500];
  sprintf(line, "%d %d\n", atoi(argv[1], argv[2]));
  write(fd, line, strlen(line) + 1);
  close(fd);
  fd2 = open("./fifo_req", O_RDONLY);
  char str[500];
  read(fd2, str, 500);
  int res;
  sscanf(str, "%d", &res);
  printf("Result: %d", res);
  close(fd2);
  return 0;
}
