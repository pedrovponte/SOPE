#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#define MAXLEN 20

int main(){
  int fd, fdDummy, n, i1, i2;
  char[MAXLEN];

  if(mkfifo("./fifo_req", 0666) < 0){
    if(errno = EEXIST)
      printf("FIFO './fifo_req' already exists\n");
    else{
      printf("Created FIFO 'fifo_req'\n");
    }
  }
  if((fd = open("./fifo_req",O_RDONLY)) != -1)
    printf("FIFO './fifo_req' openned in READONLY mode\n");

  if((fdDummy = open("./fifo_req", O_WRONLY)) != -1)
    printf("FIFO './fifo_req' openned in WRONLY mode\n");

  do{
    n = read(fd, msg, MAXLEN);
    sscanf(msg, "%d %d", &i1, &i2);
    sprintf(msg, "%d\n", i1 + i2);
    n = strlen(msg);
    write(fdDummy, msg, n);
  } while(!(i1 == 0 && i2 == 0));

  close(fd);
  close(fdDummy);

  if(unlink("./fifo_req") < 0)
    printf("Error when destroying FIFO './fifo_req'\n");
  else
    printf("FIFO './fifo_req' has been destroyed\n");

  exit(0);
  return 0;
}
