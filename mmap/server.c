#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define _PROJ_NAME_  "./map.tmp"

int main()
{
	//创建一个共享文件
	int fd =open(_PROJ_NAME_,O_CREAT|O_RDWR|O_TRUNC,0644);
	if(fd < 0)
	{
		perror("fopen");
		return -1;
	}
	//将共享内存映射
	//int len =lseek(fd, 0,SEEK_END);
	//int len = 1024;
	char * add = (char*)mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(add == NULL)
	{
		close(fd);
		perror("mmap");
		return -2;
	}
	

	char *msg ="hello world";
	strcpy(add,msg);
	while(1)
	{
		sleep(1);
		printf("%s\n",add);
		fflush(stdout);
	}

	//解除映射
	munmap(add,1024);
	return 0;
}
