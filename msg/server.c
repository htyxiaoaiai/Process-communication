#include "comm.h"

int main()
{
	int msg_id = create_msg_queue();
	
	char buf[_SIZE_];
	while(1)
	{
		memset(buf,'\0',sizeof(buf));

		recv_msg(msg_id,_CLIENT_TYPE_,buf);
		printf("client->server:%s\n",buf);

		printf("please Enter:");
		fflush(stdout);
		ssize_t _size = read(0,buf,sizeof(buf)-1);
		buf[_size-1] = '\0';
		send_msg(msg_id,_SERVER_TYPE_,buf);
	}
	destroy_msg_queue(msg_id);
	return 0;
}





