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

// ������Ĳ���   ����ֵ������ָ��
Node* SLTFind(Node* head, SLTDataType val); 

// ��pos֮ǰ������    ɾ��posλ�õĽ��
void SLTInsert(Node* head, Node* pos, SLTDataType val);
void SLTErase(Node* head, Node* pos);

// pos�������   ɾ��pos����Ľ��
void SLTInsertAfter(Node* pos, SLTDataType val);
void SLTEraseAfter(Node* pos);