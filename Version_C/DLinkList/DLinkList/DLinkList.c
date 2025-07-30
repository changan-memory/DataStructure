#pragma once
#include "DLinkList.h"

ListNode* BuyListNode(LTDataType data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		perror("malloc failed\n");
		return NULL;
	}
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//��ʼ���������ڱ�λ   ���Է��ؽڵ�������Init���������Ķ���ָ��
// �������ڱ�λ��㣬��������size,��Ϊ�����ڵ����ݲ�һ����ŵ���int���ͣ�
ListNode* ListInit() {
	ListNode* phead = BuyListNode(-1);

	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListDestroy(ListNode* phead) {
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead) {
		ListNode* curNext = cur->next;
		free(cur);
		cur = curNext;
	}
	free(phead);
	phead = NULL;
}
//��ӡ����
void ListPrint(ListNode* phead) {
	assert(phead);

	printf("head->");
	ListNode* cur = phead->next;
	while (cur != phead) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β��
void ListPushBack(ListNode* phead, LTDataType data) {
	assert(phead);

	/*ListNode* newNode = BuyListNode(data);
	ListNode* tail = phead->prev;

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;*/

	//���Ը�����pos�����λ�ò���
	ListInsert(phead, data);
}


//βɾ
void ListPopBack(ListNode* phead) {
	assert(phead);
	assert(!ListEmpty(phead));

	////��β
	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev;

	//tailPrev->next = phead;
	//phead->prev = tailPrev;
	//free(tail);
	//tail = NULL;

	ListErase(phead->prev);
}

//ͷ���ͷɾ
void ListPushFront(ListNode* phead, LTDataType data) {
	assert(phead);

	//ListNode* newNode = BuyListNode(data);
	////һ��Ҫ�������½�㣬�ٶϿ�
	//newNode->next = phead->next;
	//newNode->prev = phead;

	//phead->next->prev = newNode;
	//phead->next = newNode;

	ListInsert(phead->next, data);
}
void ListPopFront(ListNode* phead) {
	assert(phead);
	assert(!ListEmpty(phead));
	
	/*ListNode* firstNode = phead->next;
	phead->next = firstNode->next;
	firstNode->next->prev = phead;
	free(firstNode);
	firstNode = NULL;*/

	ListErase(phead->next);
}

//����
ListNode* ListFind(ListNode* phead, LTDataType data) {
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == data) {
			return cur;
		}
		else {
			cur = cur->next;
		}
	}
	return NULL;
}

bool ListEmpty(ListNode* phead) {
	return phead->next == phead;
}

//��posǰ����в���
void ListInsert(ListNode* pos, LTDataType data) {
	assert(pos);
	ListNode* newNode = BuyListNode(data);

	newNode->next = pos;
	newNode->prev = pos->prev;

	pos->prev->next = newNode;
	pos->prev = newNode;
}
//ɾ��posλ�õĽ��
void ListErase(ListNode* pos) {
	assert(pos);
	if (pos->next == pos) {
		return;
	}
	else {
		ListNode* del = pos;
		ListNode* delPrev = pos->prev;
		ListNode* delNext = pos->next;

		delPrev->next = delNext;
		delNext->prev = delPrev;
		free(del);
	}
}