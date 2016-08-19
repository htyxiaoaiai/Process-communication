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

	int fd = open("./fifo",O_WRONLY);
	if(fd < 0)
	{
		perror("open");
		return 2;
	}

	char buf[1024];
	while(1)
	{
		printf("please Enter #");
		fflush(stdout);
		ssize_t _s = read(0,buf,sizeof(buf)-1);
		if(_s > 0)
		{
			buf[_s-1]='\0';
		}

		write(fd,buf,strlen(buf));
	}
	return 0;

}
