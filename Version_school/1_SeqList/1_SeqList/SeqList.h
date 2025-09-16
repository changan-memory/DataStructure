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

// ��ʼ��������
bool InitSeqList(SeqList& L);
bool DestroySeqList(SeqList& L);

// ����Ƿ���Ҫ���ݣ�������
void CheckCapacity(SeqList& L);

// ͷ����β��
//void PushFront() {
//
//}




// size �� capacity ��ȡ
size_t Size(SeqList& L);
size_t Capacity(SeqList& L);
