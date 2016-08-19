#include "comm.h"

int main()
{
   /*int shm_id = create_shm(4096);
	printf("create done...\n");
	sleep(1);
	void * add = attch(shm_id);
	printf("attch done...\n");
	sleep(1);
	datattch(add);
	printf("datattch done...\n");
	sleep(1);
	destory_shm(shm_id);
	printf("destory done...\n");*/

    int shm_id = create_shm(4096);
	char* add = (char*)attch(shm_id);
	while(1)
	{
		sleep(1);
		printf("%s\n",add);
		fflush(stdout);
	}
	datattch(add);
	destory_shm(shm_id);
	return 0;
}
