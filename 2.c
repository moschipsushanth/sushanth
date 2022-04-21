#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void main(int argc,char *argv[])
{
	int fd,ret;
	
	char buf[100];
	
	if(argc!=2)
	{
		printf("Wrong input\n");
		exit(1);
	}
	
	fd=open(argv[1],O_RDWR);
	
	if(fd==-1)
	{
		printf("Couldn't Open the file\n");
		exit(1);
	}	
	
	ret=read(fd,buf,100);
	
	printf("No of Characters written from the terminal-->%d\n",ret);
	
	ret=write(1,buf,strlen(buf));
	
	close(fd);
}
