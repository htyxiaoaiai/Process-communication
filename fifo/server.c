/*************************************************************************
	> File Name: server.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 19 Jul 2016 07:01:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{

	if(mkfifo("./fifo",S_IFIFO|0666) < 0 )
	{
		perror("mkfifo");
		return 1;
	}

	int fd = open("./fifo",O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return 2;
	}

	char buf[1024];
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		read(fd,buf,sizeof(buf)-1);
		printf("client # %s\n",buf);
	}
	return 0;

}
