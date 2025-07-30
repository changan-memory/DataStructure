#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//队列，先进先出，数组的话在头部出数据不方便，因此用链表来实现，单链表
typedef int QDataType;

typedef struct QNode {		//链式队列，用单链表实现
	struct QNode* next;
	QDataType data;
}QNode;

//队列中 用两个指针来指示 队头和队尾，方便入队和出队
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化 与 销毁队列
void QueueInit(Queue* pQueue);
void QueueDestroy(Queue* pQueue);

// 队尾入队列    队头出队列
void QueuePush(Queue* pQueue, QDataType data);
void QueuePop(Queue* pQueue);

// 获取队列头部元素   /获取队列尾部元素
QDataType QueueFront(Queue* pQueue);
QDataType QueueBack(Queue* pQueue);

//获取队列中有效元素个数	检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueSize(Queue* pQueue);
bool QueueEmpty(Queue* pQueue);



