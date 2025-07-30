#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//双向循环链表
typedef int LTDataType;

typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//申请结点
ListNode* BuyListNode(LTDataType data);

//初始化与销毁双向循环链表
ListNode* ListInit();
void ListDestroy(ListNode* phead);

//打印链表
void ListPrint(ListNode* phead);

//尾插和尾删
void ListPushBack(ListNode* phead, LTDataType data);
void ListPopBack(ListNode* phead);

//头插和头删
void ListPushFront(ListNode* phead, LTDataType data);
void ListPopFront(ListNode* phead);

//查找与判空
ListNode* ListFind(ListNode* phead, LTDataType data);
bool ListEmpty(ListNode* phead);

//在pos前面进行插入
void ListInsert(ListNode* pos, LTDataType data);
//删除pos位置的结点
void ListErase(ListNode* pos);


