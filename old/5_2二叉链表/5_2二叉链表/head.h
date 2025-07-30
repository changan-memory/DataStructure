#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100


//�����Һ�̵�   �ö�������
typedef struct BiNode {
	int data;	//	������
	struct BiNode* Lchild, * Rchild;	//ָ����   ָ�����Һ���
}BiNode, *BiTree;	//ǰ���ǽ��   ������ָ��ý���ָ��

// ���е�assert(S)  ��Ϊ�˷�ֹ�����S Ϊ��ָ��
typedef struct {
	BiTree* top;	//ջ��ָ��    topָ��ָ���ջ��Ԫ�ص���һ��Ԫ�ص�λ��
	BiTree* base;	//ջ��ָ��
	int stacksize; //ջ���������
}Sqstack;

//��ʼ��ջ
void InitStack(Sqstack& S);
//�ж�ջ�Ƿ�Ϊ��
bool EmptyStack(Sqstack& S);
//��ջ
bool Push(Sqstack& S, BiTree ele);
//��ջ
bool Pop(Sqstack& S, BiTree ele);

