#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#define _PROJ_NAME_  "./map.tmp"

int main()
{
	//创建一个共享文件
	int fd =open(_PROJ_NAME_,O_CREAT|O_RDWR,0644);
	if(fd < 0)
	{
		perror("fopen");
		return -1;
	}
	//将共享内存映射
	int len = lseek(fd, 0, SEEK_END);
	char * add =(char*) mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(add == NULL)
	{
		close(fd);
		perror("mmap");
		return -2;
	}

	int index = 0;
	while(1)
	{
		add[index++] = '#';
		add[index] = '\0';
		sleep(1);
	}
	//解除映射
	munmap(add,len);
	return 0;
}
