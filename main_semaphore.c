#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>

#define KEY 0xdeadbeef

int main(){
  //file stuffz
  int file = open("story.txt", O_RDWR | O_APPEND);
  char * lastline;
  char line[100];
  
  //shared memory stuffz
  key_t key = 12581;
  int shmid;
  int * data;
  
  shmid = shmget(key, 200, 0644 | IPC_CREAT | IPC_EXCL);
  data = shmat(shmid, (void *)0, 0);
  if(shmid == -1){
    printf("last line : %s",lastline);
  }else{
    printf("%s\n","this is the first line");
    scanf("%[^\n]\n", line);
    *data = sizeof(line);
    if(write(file, line, *data) < 0){
      exit(1);
    }
  }

  shmdt(data);//closes data
  close(file);//closes file
  return 0;
}
