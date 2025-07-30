#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//˫��ѭ������
typedef int LTDataType;

typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//������
ListNode* BuyListNode(LTDataType data);

//��ʼ��������˫��ѭ������
ListNode* ListInit();
void ListDestroy(ListNode* phead);

//��ӡ����
void ListPrint(ListNode* phead);

//β���βɾ
void ListPushBack(ListNode* phead, LTDataType data);
void ListPopBack(ListNode* phead);

//ͷ���ͷɾ
void ListPushFront(ListNode* phead, LTDataType data);
void ListPopFront(ListNode* phead);

//�������п�
ListNode* ListFind(ListNode* phead, LTDataType data);
bool ListEmpty(ListNode* phead);

//��posǰ����в���
void ListInsert(ListNode* pos, LTDataType data);
//ɾ��posλ�õĽ��
void ListErase(ListNode* pos);


