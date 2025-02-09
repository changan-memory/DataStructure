#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100


//经常找后继的   用二叉链表
typedef struct BiNode {
	int data;	//	数据域
	struct BiNode* Lchild, * Rchild;	//指针域   指向左右孩子
}BiNode, *BiTree;	//前面是结点   后面是指向该结点的指针

// 所有的assert(S)  是为了防止传入的S 为空指针
typedef struct {
	BiTree* top;	//栈顶指针    top指针指向的栈顶元素的下一个元素的位置
	BiTree* base;	//栈底指针
	int stacksize; //栈的最大容量
}Sqstack;

//初始化栈
void InitStack(Sqstack& S);
//判断栈是否为空
bool EmptyStack(Sqstack& S);
//入栈
bool Push(Sqstack& S, BiTree ele);
//出栈
bool Pop(Sqstack& S, BiTree ele);

