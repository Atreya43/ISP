//allocate shared memory, parent process will store AAA and child
//convert it to lower case. Then parent process will print
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
	int i,shmid,pid,id;
	char *buf;
	struct shmid_ds sds;
	shmid=shmget(IPC_PRIVATE,100,IPC_CREAT|0644);
	if(shmid==-1)
	{
		perror("shmget:");
		exit(1);
	}
	buf=(char *)shmat(shmid,0,SHM_RND);
	for(i=0;i<3;i++)
	{
		buf[i]='A';
	}
	pid=fork();
	
	if(pid==0)
	{
		//child process
		for(i=0;i<3;i++)
		{
			printf("%c",buf[i]);
		}
		printf("\n");
	}
	id=shmctl(shmid,IPC_RMID,NULL);
	if(id==-1)
	{
		perror("shmctl:");
		exit(2);
	}
	shmdt(buf);
}
