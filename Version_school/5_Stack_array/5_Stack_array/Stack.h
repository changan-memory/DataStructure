#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//静态栈，实际中并不实用
//#define N 10
//struct Stack {
//	int base[N];
//	int top;
//};

#define INIT_CAPACITY 4
typedef int StackDataType;		//括号匹配需要把 int 换成char

typedef struct Stack {
	StackDataType* base;
	int top;	//top表示栈顶元素的下一个位置
	int capacity;
}Stack;

//初始化与销毁
void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

//入栈与出栈
void StackPush(Stack* ps, StackDataType ele);
void StackPop(Stack* ps);

StackDataType StackTop(Stack* ps);	//获取栈顶元素

bool StackEmpty(Stack* ps);		//判断是否为空
int StackSize(Stack* ps);	//获取栈中有效元素个数