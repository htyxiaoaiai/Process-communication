/*************************************************************************
	> File Name: pipeMemory.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年07月17日 星期日 11时12分10秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	int _pipe[2];
	int ret = pipe(_pipe);
	if(ret == -1)
	{
		printf("error errno code:%d \n",errno);
		return -1;
	}
	pid_t id = fork();
	
	if(id == 0)
	{
		//child
		close(_pipe[0]);
		char mesage[1024];
		int i = 0;
		for(;i<1024;i++)
		{
			mesage[i] = 'a';
		}
		int count = 0;
		while(1)
		{
			write(_pipe[1],mesage,1024);//no +1 write file
			printf("count %d\n",count);
			count++;
		}
		close(_pipe[1]);
	}
	else
	{
		char buff[1024];
		memset(buff,'\0',1);
		close(_pipe[1]);
			sleep(10);
			read(_pipe[0],buff,sizeof(buff) -1);
			printf("%s\n",buff);
		close(_pipe[0]);
	}
	return 0;
}
