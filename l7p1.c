/*Program 1
  This program shows standard input and output redirection
  First argument is input file, second is output file and 	
  remaining arguments
  as command line to be executed 
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	int fd1,fd2;
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0644);
	close(STDIN_FILENO);
	dup(fd1);
	close(STDOUT_FILENO);
	dup(fd2);
	execvp(argv[3],&argv[3]);
	printf("Command failed...\n");
	close(fd1);
	close(fd2);
	exit(0);
}
