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

// ����ͷ��㣬����Ҫ��ʼ��
//Node* InitList(Node*& head);

// �����ʹ����ڵ�
void SLTPrint(const Node* head);
Node* BuySLTNode(SLTDataType val);

// β��βɾ
void SLTPushBack(Node*& head, SLTDataType val);
void SLTPopBack(Node*& head);


// ͷ��ͷɾ
void SLTPushFront(Node*& head, SLTDataType val);
void SLTPopFront(Node*& head);