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
	BiNode* data[MaxSize];	// 存放队中元素
	int front, rear;	// 队头和队尾指针/循环队列出队
}SqQuence;				// 顺序循环队列

//初始化循环队列
bool InitSqQuence(SqQuence& Q);

//	循环队列入队
bool PushQuence(SqQuence& Q, BiNode* ele);

// 循环队列出队
BiTree PopQuence(SqQuence& Q, BiNode* x);

//利用队列   实现二叉树的 层次遍历
void LevelOrder(BiNode* B);

