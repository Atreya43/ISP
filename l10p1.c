/*PROGRAM TO FIND THE NUMBER OF SIGNALS AVAILABLE ON
YOUR SYSTEM;
IGNORE ALL OF THEM*/
#include<stdio.h>
#include<signal.h>
int main(void)
{
	int i;
	for(i=1;i<=32;i++)
	{
		if(signal(i,SIG_IGN)==SIG_ERR)
		printf("Signal %d can't be ignored\n",i);
	}
}
