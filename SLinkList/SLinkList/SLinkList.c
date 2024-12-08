#include "SLinkList.h"

//打印链表
void SLTPrint(SListNode* phead) {	//无需断言，空链表也可以打印
	SListNode* cur = phead;
	//while(cur)
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//将创建节点的代码封装成一个函数
SListNode* BuySLTNode(SLTDataType data) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL) {
		perror("malloc error");
		return NULL;
	}
	//初始化
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//尾插法
void SLTPushBack(SListNode** pphead, SLTDataType data) {
	SListNode* newNode = BuySLTNode(data);
	if (*pphead == NULL) {
		*pphead = newNode;
		return;
	}

	//找当前链表的尾结点
	SListNode* tail = *pphead;
	while (tail->next != NULL) {	//如果phead为空，那么tail初始时  为  野指针
		tail = tail->next;
	}
	tail->next = newNode;
}
//头插法
void SLTPushFront(SListNode** pphead, SLTDataType data) {
	SListNode* newNode = BuySLTNode(data);
	//当*pphead为空时， 以下代码也适用
	newNode->next = *pphead;
	*pphead = newNode;
}
//尾删和头删
void SLTPopBack(SListNode** pphead) {
	assert(*pphead);//删除时确保链表不能为空
	if (*pphead == NULL) {
		return;
	}
	//1. 链表只有一个结点
	//2. 链表有多个结点
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;	//存下tail的前一个结点
			tail = tail->next;
		}
		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}
void SLTPopFront(SListNode** pphead) {
	assert(*pphead);
	if (*pphead == NULL) {
		return;
	}
	SListNode* prev = *pphead;
	*pphead = prev->next;
	prev->next = NULL;//将第一个结点和之后的结点断开
	free(prev);		//释放
	prev = NULL;	//置空
}
