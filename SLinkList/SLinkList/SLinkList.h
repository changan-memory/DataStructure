#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode {

	SLTDataType data;
	struct SListNode* next;

	//SListNode* next;  C���Բ�����ôд
	//SLTNode* next;  C���Բ�����ôд
}SListNode;
// typedef ��14�ж�������Ч
// ����������һ������ʱ�� ���ڸ����͵��Ϸ����� �����͵� ���� �� ����

void SLTPrint(SListNode* phead);

void SLTPushBack(SListNode** pphead, SLTDataType data);
void SLTPushFront(SListNode** pphead, SLTDataType data);
//βɾ��ͷɾ
void SLTPopBack(SListNode** pphead);
void SLTPopFront(SListNode** pphead);


