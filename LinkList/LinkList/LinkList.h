#pragma once

#include <stdio.h>
#include <stdlib.h>

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