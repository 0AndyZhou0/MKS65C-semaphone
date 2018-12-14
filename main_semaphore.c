#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/shm.h>

#define KEY 0xdeadbeef

int main(){
  //shared memory stuffz
  key_t key = 12581;
  int shmid;
  int * data;
  shmid = shmget(key, 200, 0644 | IPC_CREAT);
  data = shmat(shmid, (void *)0, 0);
  shmdt(data);
  return 0;
}
