//This program takes directory name as argument and list all 
//subdirectories
#include<stdio.h>
#include<dirent.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char* argv[])
{
	DIR*dir;
	struct stat statbuf;
	struct dirent *dentry;
	mode_t F-type,f_perm;
	dir=opendir(argv[1]);
	if(dir==NULL)
	{
		printf("Cannot open directory...\n");
		exit(1);
	}
	chdir(argv[1]);
	// chdir call is essential because the d_name member of the
	//dirent
	//structure evaluates to a filename without slashes. Without
	//chdir lstat would
	//look for the file in the current directory
	while((dentry=readdir(dir))!=NULL)
	{
		lstat(dentry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			f_type=statbuf.st_mode & S_IFMT;
			f_perm=statbuf.st_mode & ~S_IFMT;
			printf("%o %o %s\n",f_type,f_perm,dentry->d_name);
		}
	}
	closedir(dir);
}	
