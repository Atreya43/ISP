//This program creates shared memory
//use ipcs -m to see shared memory and ipcrm -m shmid to remove it

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main()
{
	int shmid;
	
	shmid=shmget(IPC_PRIVATE,2048,IPC_CREAT|0644);
	
	if(shmid==-1)
	{
		printf("Shared Memory Error---\n");
		perror("shmget");
		exit(1);
	}
	else
	{
		printf("shmid=%d\n",shmid);
	}
	return 0;
}
