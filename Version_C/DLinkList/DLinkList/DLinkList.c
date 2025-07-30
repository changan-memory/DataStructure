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

//初始化，设置哨兵位   可以返回节点来避免Init函数参数的二级指针
// 不能用哨兵位结点，存放链表的size,因为链表内的数据不一定存放的是int类型，
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
//打印链表
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

//尾插
void ListPushBack(ListNode* phead, LTDataType data) {
	assert(phead);

	/*ListNode* newNode = BuyListNode(data);
	ListNode* tail = phead->prev;

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;*/

	//可以复用在pos的相关位置插入
	ListInsert(phead, data);
}


//尾删
void ListPopBack(ListNode* phead) {
	assert(phead);
	assert(!ListEmpty(phead));

	////找尾
	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev;

	//tailPrev->next = phead;
	//phead->prev = tailPrev;
	//free(tail);
	//tail = NULL;

	ListErase(phead->prev);
}

//头插和头删
void ListPushFront(ListNode* phead, LTDataType data) {
	assert(phead);

	//ListNode* newNode = BuyListNode(data);
	////一定要先连上新结点，再断开
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

//查找
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

//在pos前面进行插入
void ListInsert(ListNode* pos, LTDataType data) {
	assert(pos);
	ListNode* newNode = BuyListNode(data);

	newNode->next = pos;
	newNode->prev = pos->prev;

	pos->prev->next = newNode;
	pos->prev = newNode;
}
//删除pos位置的结点
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