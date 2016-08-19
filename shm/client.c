#include "comm.h"

int main()
{
    int shm_id = get_shm();
	char* add = (char*)attch(shm_id);
	int index = 0;
	while(1)
	{
		add[index++] = '#';
		add[index] = '\0';
		sleep(1);
	}

	datattch(add);
	return 0;
}
