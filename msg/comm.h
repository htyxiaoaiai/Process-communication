#pragma once

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <error.h>


#define _PROJ_NAME_ "/tmp"
#define _PROJ_ID_ 0x6666
#define _SIZE_ 1024

#define _SERVER_TYPE_ 1
#define _CLIENT_TYPE_ 2

struct msgbuf
{
	long mtype;
	char mtext[_SIZE_];
};

//创建消息队列
int create_msg_queue();
//获取消息队列
int get_msg_queue();
//删除消息队列
int destory_msg_queue(int msg_id);
//接收消息
int recv_msg(int msg_id, int t, char *out);
//发送消息
int send_msg(int msg_id, int t, const char *msg);


