#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define INIT_CAPACITY 4

typedef int SLDataType;

typedef struct SeqList {
	SLDataType* base;
	int size;
	int capacity;
}SeqList;

// 初始化与销毁
bool InitSeqList(SeqList& L);
bool DestroySeqList(SeqList& L);

// 检查是否需要扩容，并扩容
void CheckCapacity(SeqList& L);

// 头插与尾插
//void PushFront() {
//
//}




// size 与 capacity 获取
size_t Size(SeqList& L);
size_t Capacity(SeqList& L);
