/* Program waits for 5 seconds for user input and then generates SIGALRM
that has a handler specified. */
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#define BUFSIZE 100
void alrm_handler(int signo);
void quit(char *message,int exit_status);
char buf[BUFSIZE] = "foo\0";
int main()
{
	int n;
	if(signal(SIGALRM,alrm_handler)==SIG_ERR) 
	quit("sigalrm",1);
	fprintf(stderr,"Enter Filename : ");
	alarm(5);
	n = read(STDIN_FILENO,buf,BUFSIZE);
	if ( n > 1)
	printf("Filename = %s\n",buf);
	exit(0);
}
void alrm_handler(int signo)
{
	signal(SIGALRM,alrm_handler); 
	fprintf(stderr,"\nSignal %d received default filename : %s\n",signo,buf);
	exit(1);
}
void quit(char *msg, int si)
{
	printf("%s %d\n",msg, si);
}
