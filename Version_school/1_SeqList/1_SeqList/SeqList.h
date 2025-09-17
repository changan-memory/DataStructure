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
bool SeqListInit(SeqList& L);
void SeqListDestroy(SeqList& L);

// ����Ƿ���Ҫ���ݣ�������
bool CheckCapacity(SeqList& L);

// β����βɾ
void PushBack(SeqList& L, SLDataType val);
void PopBack(SeqList& L);

// ͷ����ͷɾ
void PushFront(SeqList& L, SLDataType val);
void PopFront(SeqList& L);

// �Ϸ�λ�ò�����ɾ��
void SeqListInsert(SeqList& L, int pos, SLDataType val);
void SeqListErase(SeqList& L, int pos);

// size �� capacity ��ȡ
int Size(const SeqList& L);
int Capacity(const SeqList& L);

// ����ֵΪ val ��Ԫ�أ����ض�Ӧ�±꣬�Ҳ������� -1
int SeqListFind(const SeqList& L, SLDataType val);
// ������ӡԪ��
void SeqListPrint(const SeqList& L);