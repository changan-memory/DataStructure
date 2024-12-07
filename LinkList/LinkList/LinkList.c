#include "LinkList.h"

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
//尾插法
void SLTPushBack(SListNode** pphead, SLTDataType data) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL) {
		perror("malloc error");
		return;
	}
	//初始化
	newNode->data = data;
	newNode->next = NULL;
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