#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define SHMSZ 27
void main(){
	char c;
	char *shm,*s;
	key_t key = 567800;
	int shm_id;
	if((shm_id = shmget(key,SHMSZ,0666))<0){
		printf("ERROR: shmget error");
		exit(1);
	}
	if((shm = shmat(shm_id,NULL,0))  == (char *)-1){
		printf("ERROR: shmat error");
		exit(1);
	}
	s = shm;
	while(1){
		if(*shm){
			putchar(*shm++);
		}else{
			*shm++=getchar();
		}
	}
	putchar('\n');
	*shm = '*';
	exit(EXIT_SUCCESS);
}
