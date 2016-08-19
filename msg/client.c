#include "comm.h"

int main()
{

	int msg_id = get_msg_queue();
	char buf[_SIZE_];
	while(1)
	{
		printf("please Enter:");
		fflush(stdout);
		ssize_t _size =read(0,buf,sizeof(buf)-1);
		buf[_size-1] = '\0';
		send_msg(msg_id,_CLIENT_TYPE_,buf);

		memset(buf,'\0',sizeof(buf));

		recv_msg(msg_id,_SERVER_TYPE_,buf);
		printf("server->client:%s\n",buf);

	}
	return 0;
}



