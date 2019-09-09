#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<scntl.h>
int main()
{
	int file_dec=open('f1.txt',O_WRONLY|O_APPEND);
	dup2(file_dec,1);
	dup(file_dec,1);	
	printf("I will be printed in file\n");
	return 0;
}
