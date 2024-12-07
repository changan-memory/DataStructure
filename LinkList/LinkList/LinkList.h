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

void SLTPushBack(SListNode** pphead, SLTDataType data);
