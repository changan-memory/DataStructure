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

//销毁与打印
void SLTPrint(SListNode* phead);
void SListDestroy(SListNode** pphead);

//尾插和头插
void SLTPushBack(SListNode** pphead, SLTDataType data);
void SLTPushFront(SListNode** pphead, SLTDataType data);
//尾删和头删
void SLTPopBack(SListNode** pphead);
void SLTPopFront(SListNode** pphead);

SListNode* BuySLTNode(SLTDataType data);

//单链表查找
SListNode* SListFind(SListNode* phead, SLTDataType data);

// pos之前插入    pos位置删除
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType data);
void SListErase(SListNode** pphead, SListNode* pos);

//还有一种偷梁换柱的方法，不给头指针，删除pos前面的结点，中心思想是狸猫换太子


// pos后面插入   pos后面删除
void SListInsertAfter(SListNode* pos, SLTDataType data);
void SListEraseAfter(SListNode* pos);

//// 求链表的size, 可以添加一个结构体，结构内存放指向头结点的指针和size,仿照和队列的写法
//typedef struct List {
//	SListNode* pList;	//指向头结点的指针,存放头结点的地址
//	int size;
//}List;




