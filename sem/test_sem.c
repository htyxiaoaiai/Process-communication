#include "comm.h"

int main()
{
	int sem_id = create_sem_set(1);
	init_sem_set(sem_id,0,1);
	pid_t id =fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	if(id == 0)
	{
		//child
		int c_sem_id  = get_sem_set();
		while(1)
		{
			P(c_sem_id,0);
			printf("A");
			fflush(stdout);
			usleep(rand()%12345);
			printf("A");
			fflush(stdout);
			usleep(rand()%12354);
			V(c_sem_id ,0);
		}
	}
	else
	{
		//father
		while(1)
		{
			P(sem_id,0);
			printf("B");
			fflush(stdout);
			usleep(rand()%123455);
			printf("B");
			fflush(stdout);
			usleep(rand()%123564);
			V(sem_id ,0);
		}
		wait(NULL);
		destory_sem_set(sem_id);
	}
	return 0;
}
