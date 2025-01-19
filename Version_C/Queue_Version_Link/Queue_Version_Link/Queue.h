#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//队列，先进先出，数组的话在头部出数据不方便，因此用链表来实现，单链表
typedef int QDataType;

struct QuqueNode {		//链式队列，用单链表实现
	struct QueueNode* next;
	QDataType data;
};