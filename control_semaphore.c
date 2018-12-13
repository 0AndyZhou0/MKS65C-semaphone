#include <stdio.h>
#include <sys/types>
#include <sys.ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define KEY 0x12894872

int main(){
  int sem;
  sem = (KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
  if(sem == -1){
    printf("error %d: %s\n", errno, strerror(errno));
  }else{
    struct sembuf buf;
  }
  return 0;
}
