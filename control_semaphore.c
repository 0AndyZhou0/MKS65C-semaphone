#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define KEY 0x12894872

union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO */
};

int main(int argc, char *argv[]){
  int sem;
  if(argc == 2){
    if(!strcmp(argv[1],"-c")){
      sem = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
      if(sem == -1){
	//File already exists
	printf("error %d: %s\n", errno, strerror(errno));
	sem = semget(KEY, 1, 0);
	int v = semctl(sem, 0, GETVAL, 0);
	printf("semctl returned: %d\n", v);
      }else{
	//down
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_flg = SEM_UNDO;
	buf.sem_op = -1;
	semop(sem,&buf,1);

	//Enter line
	printf("%s\n","Enter the line you want to enter");
	char * line;
        scanf("%[99^\n]", line);
	//union semun un;
	//un.val = 420;
	//int r = semctl(sem, 0, SETVAL, un);
	//printf("semctl returned: %d\n", r);
	      
	//up
	buf.sem_op = 1;
	semop(sem,&buf,1);
      }
    }
    else if(!strcmp(argv[1],"-r")){
      
    }
    else if(!strcmp(argv[1],"-v")){
      
    }
  }
  return 0;
}
