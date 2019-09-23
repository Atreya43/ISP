//This program attaches some value and then detaches using shared
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
	int shmid,stat;
	char *buf;
	int k,*val;
	
	struct shmid_ds sds;
	
	shmid=shmget(IPC_PRIVATE,100,IPC_CREAT|0644);
	if(shmid==-1)
	{
		perror("shmget");
		exit(1);
	}
	
	buf = (char *) shmat(shmid,0,SHM_RND);
	val = (int *) shmat(shmid,0,SHM_RND);
	*val=10;
	buf[0]='a';
	
	printf("Integer=%d Charecter=%c\n",*val,buf[0]);
	
	//Deleting Shared Memory...
	shmdt(buf);
	shmdt(val);
	
	k=shmctl(shmid,IPC_RMID,&sds);
	if(k==-1)
	{
		perror("Error...\n");
		exit(2);
	}
}
