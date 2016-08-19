#pragma once

#define _PROJ_NAME_ "/tmp"
#define _PROJ_ID_ 0x6666

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
//创建共享内存
int create_shm(int size);
//获取共享内存
int get_shm();
//销毁共享内存
int destory_shm(int shm_id);
//映射共享内存
void* attch(int shm_id);
//解除映射关系
int datattch(void* add);
