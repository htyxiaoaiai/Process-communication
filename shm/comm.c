#include "comm.h"

static int comm_shm(int size, int flags)
{
	key_t _key = ftok(_PROJ_NAME_,_PROJ_ID_);
	if(_key < 0)
	{
		perror("ftok");
		return -1;
	}

	int shm_id = shmget(_key,size,flags);
	if(shm_id < 0)
	{
		perror("shmget");
		return -2;
	}
	return shm_id;
}

int create_shm(int size)
{
	int flags = IPC_CREAT |IPC_EXCL |0644;
	return comm_shm(size,flags);
}

int get_shm()
{
	int flags = IPC_CREAT;
	return comm_shm(0,flags);
}

int destory_shm(int shm_id)
{
	if(shmctl(shm_id,IPC_RMID,NULL) < 0)
	{
		perror("shmctl");
		return -1;
	}
	return 0;
}

void* attch(int shm_id)
{
	return shmat(shm_id,NULL,0);
}

int datattch(void* add)
{
	return shmdt(add);
}
