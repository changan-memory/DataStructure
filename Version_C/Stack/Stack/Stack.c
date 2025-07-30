#pragma once
#include "Stack.h"

//��ʼ��������
void StackInit(Stack* ps) {
	assert(ps);
	ps->base = (StackDataType*)malloc(sizeof(StackDataType) * INIT_CAPACITY);
	if (ps->base == NULL) {
		perror("malloc failed");
		return;
	}
	ps->capacity = INIT_CAPACITY;
	ps->top = 0;	//top ��ʼ��0 ��ʾջ��Ԫ�ص���һ��λ�ã�Ҳ���Ը���ʼ��-1����ʾջ��Ԫ�ص��±�
}
void StackDestroy(Stack* ps) {
	assert(ps);
	
	free(ps->base);
	ps->base = NULL;
	ps->capacity = ps->top = 0;
}

//��ջ���ջ
void StackPush(Stack* ps, StackDataType ele) {
	assert(ps);
	if (ps->top == ps->capacity) {	//�������,������
		StackDataType* newSpace = (StackDataType*)realloc(ps->base, sizeof(StackDataType)*ps->capacity * 2);
		if (newSpace == NULL) {
			perror("realloc failed");
			return;
		}
		ps->base = newSpace;
		ps->capacity *= 2;
	}
	//������
	ps->base[ps->top++] = ele;
}
void StackPop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));	//����һֱ��ջ�����ջ�Ƿ�Ϊ��

	ps->top--;
}

//��ȡջ��Ԫ��
StackDataType StackTop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->base[ps->top-1];
}

//�ж��Ƿ�Ϊ��
bool StackEmpty(Stack* ps) {
	assert(ps);
	/*if (ps->top == 0)
		return true;
	return false;*/
	return ps->top == 0;
}

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps) {
	assert(ps);
	return ps->top;
}

////��ϰ�Ķ���ʵ��
////��ʼ��������
//void StackInit(Stack* ps) {
//	assert(ps);	//ջ�Ľṹ��������
//	ps->base = (StackDataType*)malloc(sizeof(StackDataType) * INIT_CAPACITY);
//	if (ps->base == NULL) {
//		perror("malloc failed\n");
//		return;
//	}
//	ps->capacity = INIT_CAPACITY;
//	ps->top = 0;	
//}
//void StackDestroy(Stack* ps) {
//	assert(ps);
//	free(ps->base);
//	ps->base = NULL;
//
//	ps->capacity = ps->top = 0;
//}
//
////��ջ���ջ
//void StackPush(Stack* ps, StackDataType ele) {
//	assert(ps);
//	//�������
//	if (ps->top == ps->capacity) {
//		StackDataType* newSpace = (StackDataType*)realloc(ps->base, sizeof(StackDataType)*ps->capacity*2);
//		if (newSpace == NULL) {
//			perror("realloc failed\n");
//			return;
//		}
//		ps->base = newSpace;
//		ps->capacity *= 2;
//	}
//	// ����Ԫ��
//	ps->base[ps->top++] = ele;
//}
//void StackPop(Stack* ps) {
//	assert(ps);
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
//StackDataType StackTop(Stack* ps) {
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->base[ps->top - 1];
//}
//bool StackEmpty(Stack* ps) {
//	assert(ps);
//	return ps->top == 0;
//}
//
//int StackSize(Stack* ps) {
//	assert(ps);
//	return ps->top;
//}