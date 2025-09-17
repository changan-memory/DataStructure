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
bool SeqListInit(SeqList& L);
void SeqListDestroy(SeqList& L);

// 检查是否需要扩容，并扩容
bool CheckCapacity(SeqList& L);

// 尾插与尾删
void PushBack(SeqList& L, SLDataType val);
void PopBack(SeqList& L);

// 头插与头删
void PushFront(SeqList& L, SLDataType val);
void PopFront(SeqList& L);

// 合法位置插入与删除
void SeqListInsert(SeqList& L, int pos, SLDataType val);
void SeqListErase(SeqList& L, int pos);

// size 与 capacity 获取
int Size(const SeqList& L);
int Capacity(const SeqList& L);

// 查找值为 val 的元素，返回对应下标，找不到返回 -1
int SeqListFind(const SeqList& L, SLDataType val);
// 遍历打印元素
void SeqListPrint(const SeqList& L);