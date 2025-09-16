#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MaxSize 100

typedef struct BiNode {
	int data;
	struct BiNode* Lchild, *Rchild;
}BiNode, *BiTree;

typedef struct {
	BiNode* data[MaxSize];	// ��Ŷ���Ԫ��
	int front, rear;	// ��ͷ�Ͷ�βָ��/ѭ�����г���
}SqQuence;				// ˳��ѭ������

//��ʼ��ѭ������
bool InitSqQuence(SqQuence& Q);

//	ѭ���������
bool PushQuence(SqQuence& Q, BiNode* ele);

// ѭ�����г���
BiTree PopQuence(SqQuence& Q, BiNode* x);

//���ö���   ʵ�ֶ������� ��α���
void LevelOrder(BiNode* B);

