#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//��̬ջ��ʵ���в���ʵ��
//#define N 10
//struct Stack {
//	int base[N];
//	int top;
//};

#define INIT_CAPACITY 4
typedef int StackDataType;		//����ƥ����Ҫ�� int ����char

typedef struct Stack {
	StackDataType* base;
	int top;	//top��ʾջ��Ԫ�ص���һ��λ��
	int capacity;
}Stack;

//��ʼ��������
void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

//��ջ���ջ
void StackPush(Stack* ps, StackDataType ele);
void StackPop(Stack* ps);

StackDataType StackTop(Stack* ps);	//��ȡջ��Ԫ��

bool StackEmpty(Stack* ps);		//�ж��Ƿ�Ϊ��
int StackSize(Stack* ps);	//��ȡջ����ЧԪ�ظ���