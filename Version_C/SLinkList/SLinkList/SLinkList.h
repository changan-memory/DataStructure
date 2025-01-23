#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;

	//SListNode* next;  C语言不能这么写
	//SLTNode* next;  C语言不能这么写
}SListNode;
// typedef 在14行定义后才生效
// 编译器碰到一个类型时， 会在该类型的上方查找 该类型的 定义 或 声明

void SLTPrint(SListNode* phead);
//尾插和头插
void SLTPushBack(SListNode** pphead, SLTDataType data);
void SLTPushFront(SListNode** pphead, SLTDataType data);
//尾删和头删
void SLTPopBack(SListNode** pphead);
void SLTPopFront(SListNode** pphead);

SListNode* BuySLTNode(SLTDataType data);

//单链表查找
SListNode* SListFind(SListNode* phead, SLTDataType data);

// pos之前插入
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType data);
//pos位置删除
void SListErase(SListNode** pphead, SListNode* pos);

// pos后面插入
void SListInsertAfter(SListNode* pos, SLTDataType data);
//pos后面删除
void SListEraseAfter(SListNode* pos);



