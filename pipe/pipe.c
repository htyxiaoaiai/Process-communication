/*************************************************************************
	> File Name: pipe.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年07月16日 星期六 17时32分33秒
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
		int i = 0;
		char* _mesg_c = NULL;
		while(i < 100)
		{
			_mesg_c = "i am child\n";
			write(_pipe[1],_mesg_c,strlen(_mesg_c));//no +1 write file
			//sleep(1);
			i++;
		}
		close(_pipe[1]);
	}
	else
	{
		close(_pipe[1]);
		int j = 0;
		char buff[1024];
		while(j < 100 )
		{
			memset(buff,'\0',sizeof(buff)-1);
			read(_pipe[0],buff,sizeof(buff) -1);
			printf("%s",buff);
			j++;
			sleep(5);
		}
		close(_pipe[0]);
	}
	return 0;
}
