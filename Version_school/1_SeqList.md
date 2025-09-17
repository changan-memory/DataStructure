# 动态顺序表



# 头文件

```cpp
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
```



# 源文件

```cpp
#include "SeqList.h"

// 初始化空间  设置初始状态
bool SeqListInit(SeqList& L) {
	L.base = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	if (L.base == NULL) {
		perror("malloc failed\n");
		return false;
	}
	L.capacity = INIT_CAPACITY;
	L.size = 0;
	return true;
}

// 销毁
void SeqListDestroy(SeqList& L) {
	if (L.base) {
		free(L.base);
		L.base = NULL;
		L.capacity = L.size = 0;
	}
}

bool CheckCapacity(SeqList& L) {
	if (L.size == L.capacity) {
		// 开空间
		//int newCap = (L.capacity == 0 ? INIT_CAPACITY : L.capacity * 2); // 初始化后capacity不可能为0
		SLDataType* newSpace = (SLDataType*)malloc(sizeof(SLDataType) * L.capacity * 2);
		if (newSpace == NULL) {
			perror("malloc failed");
			return false;
		}
		// 拷贝数据  仅能拷贝无动态资源的类型
		memcpy(newSpace, L.base, sizeof(SLDataType) * L.size);
		// 更新状态
		free(L.base);
		L.base = newSpace;
		L.capacity *= 2;
		return true;
	}
	return true;
}

void PushBack(SeqList& L, SLDataType val) {
	// 检查扩容
	if(L.size == L.capacity)
		CheckCapacity(L);
	L.base[L.size++] = val;
	//SeqListInsert(L, L.size, val);
}
void PopBack(SeqList& L) {
	assert(L.size > 0);
	L.size--;

	//assert(L.size > 0);
	//SeqListErase(L, L.size - 1);
}

void PushFront(SeqList& L, SLDataType val) {
	// 检查扩容
	if (L.size == L.capacity)
		CheckCapacity(L);
	// 挪动元素
	int end = L.size - 1;
	while (end >= 0) {
		L.base[end + 1] = L.base[end];
		--end;
	}
	// 插入
	L.base[end + 1] = val;
	++L.size;
}
void PopFront(SeqList& L) {
	assert(L.size > 0);
	int begin = 0;
	while (begin < L.size - 1) {
		L.base[begin] = L.base[begin + 1];
		++begin;
	}
	// 更新状态
	--L.size;
}

void SeqListInsert(SeqList& L, int pos, SLDataType val) {
	// 检查插入位置
	assert(pos >= 0 && pos <= L.size);

	// 检查扩容
	if (L.size == L.capacity)
		CheckCapacity(L);
	// 挪动元素
	int end = L.size - 1;
	while (end >= pos) {
		L.base[end + 1] = L.base[end];
		--end;
	}
	// 插入元素
	L.base[pos] = val;
	++L.size;
}
void SeqListErase(SeqList& L, int pos) {
	assert(L.size > 0);
	assert(pos >= 0 && pos < L.size);
	int begin = pos + 1;
	while (begin < L.size) {
		L.base[begin - 1] = L.base[begin];
		++begin;
	}
	--L.size;
}

// size 与capacity
int Size(const SeqList& L) {
	return L.size;
}
int Capacity(const SeqList& L) {
	return L.capacity;
}

int SeqListFind(const SeqList& L, SLDataType val) {
	if (L.base == NULL)
		return -1;
	for (int i = 0; i < L.size; ++i) {
		if (L.base[i] == val)
			return i;
	}
	return -1;
}

void SeqListPrint(const SeqList& L) {
	if (L.base == NULL)
		return;
	for (int i = 0; i < L.size; ++i)
		printf("%d ", L.base[i]);
	printf("\n");
}
```

