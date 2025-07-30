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

//�������ӡ
void SLTPrint(SListNode* phead);
void SListDestroy(SListNode** pphead);

//β���ͷ��
void SLTPushBack(SListNode** pphead, SLTDataType data);
void SLTPushFront(SListNode** pphead, SLTDataType data);
//βɾ��ͷɾ
void SLTPopBack(SListNode** pphead);
void SLTPopFront(SListNode** pphead);

SListNode* BuySLTNode(SLTDataType data);

//���������
SListNode* SListFind(SListNode* phead, SLTDataType data);

// pos֮ǰ����    posλ��ɾ��
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType data);
void SListErase(SListNode** pphead, SListNode* pos);

//����һ��͵�������ķ���������ͷָ�룬ɾ��posǰ��Ľ�㣬����˼������è��̫��


// pos�������   pos����ɾ��
void SListInsertAfter(SListNode* pos, SLTDataType data);
void SListEraseAfter(SListNode* pos);

//// �������size, �������һ���ṹ�壬�ṹ�ڴ��ָ��ͷ����ָ���size,���պͶ��е�д��
//typedef struct List {
//	SListNode* pList;	//ָ��ͷ����ָ��,���ͷ���ĵ�ַ
//	int size;
//}List;




