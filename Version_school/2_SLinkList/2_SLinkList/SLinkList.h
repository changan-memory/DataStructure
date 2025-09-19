#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLTDataType;

typedef struct LNode {
	SLTDataType val;
	struct LNode* next;
}Node, *LinkList;

// 不带头结点，不需要初始化
//Node* InitList(Node*& head);

// 遍历和创建节点
void SLTPrint(const Node* head);
Node* BuySLTNode(SLTDataType val);

// 尾插尾删
void SLTPushBack(Node*& head, SLTDataType val);
void SLTPopBack(Node*& head);


// 头插头删
void SLTPushFront(Node*& head, SLTDataType val);
void SLTPopFront(Node*& head);

// 单链表的查找   查找值，返回指针
Node* SLTFind(Node* head, SLTDataType val); 

// 在pos之前插入结点    删除pos位置的结点
void SLTInsert(Node* head, Node* pos, SLTDataType val);
void SLTErase(Node* head, Node* pos);

// pos后面插入   删除pos后面的结点
void SLTInsertAfter(Node* pos, SLTDataType val);
void SLTEraseAfter(Node* pos);