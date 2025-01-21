#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//队列，先进先出，数组的话在头部出数据不方便，因此用链表来实现，单链表
typedef int QDataType;

typedef struct QuqueNode {		//链式队列，用单链表实现
	struct QueueNode* next;
	QDataType data;
}Queue;

//初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType ele);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列尾部元素
QDataType QueueBack(Queue* q);
//获取队列中有效元素个数
int QueueSize(Queue* q);
//检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);


