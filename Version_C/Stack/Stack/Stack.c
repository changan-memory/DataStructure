#pragma once
#include "Stack.h"

//初始化与销毁
void StackInit(Stack* ps) {
	assert(ps);
	ps->base = (StackDataType*)malloc(sizeof(StackDataType) * INIT_CAPACITY);
	if (ps->base == NULL) {
		perror("malloc failed");
		return;
	}
	ps->capacity = INIT_CAPACITY;
	ps->top = 0;	//top是栈顶元素的下一个位置
}
void StackDestroy(Stack* ps) {
	assert(ps);
	
	free(ps->base);
	ps->base = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//入栈与出栈
void StackPush(Stack* ps, StackDataType ele) {
	assert(ps);
	if (ps->top == ps->capacity) {	//如果满了,就扩容
		StackDataType* newSpace = (StackDataType*)realloc(ps->base, sizeof(StackDataType)*ps->capacity * 2);
		if (newSpace == NULL) {
			perror("realloc failed");
			return;
		}
		ps->base = newSpace;
		ps->capacity *= 2;
	}
	//放数据
	ps->base[ps->top++] = ele;
}
void StackPop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));	//不能一直出栈，检查栈是否为空

	ps->top--;
}

//获取栈顶元素
StackDataType StackTop(Stack* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->base[ps->top-1];
}

//判断是否为空
bool StackEmpty(Stack* ps) {
	assert(ps);
	/*if (ps->top == 0)
		return true;
	return false;*/
	return ps->top == 0;
}

//获取栈中有效元素个数
int StackSize(Stack* ps) {
	assert(ps);
	return ps->top;
}