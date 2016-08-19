#pragma once

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include <errno.h>
#include<unistd.h>

#define _PROJ_NAME_ "/tmp"
#define _PROJ_ID_  0x6666

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};
//创建信号量集
int create_sem_set(int sems);
//获取信号量
int get_sem_set();
//初始化信号量
int init_sem_set(int sem_id, int which, int _val);
//销毁信号量
int destory_sem_set(int sem_id);
//p操作
int P(int sem_id, int which);
//V操作
int V(int sem_id, int which);


