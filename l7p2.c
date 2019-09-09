//This program perform standard input and output redirection but using dup2()
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<wait.h>
int main(int argc, char *argv[])
{
	int fd1,fd2,exitstatus;
	switch(fork())
	{
		case 0:
			//Child process
			fd1=open(argv[1],O_RDONLY);
			fd2=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0644);
			dup2(fd1,0);
			dup2(fd2,1);
			execvp(argv[3],&argv[3]);
			exit(1);
		case -1:
			printf("Fork error\n");
			exit(2);
		default:
			//Parent process
			wait(&exitstatus);
			printf("Exit status : %d\n",WEXITSTATUS(exitstatus));
	}
}
