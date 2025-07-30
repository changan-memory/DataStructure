#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//���У��Ƚ��ȳ�������Ļ���ͷ�������ݲ����㣬�����������ʵ�֣�������
typedef int QDataType;

typedef struct QNode {		//��ʽ���У��õ�����ʵ��
	struct QNode* next;
	QDataType data;
}QNode;

//������ ������ָ����ָʾ ��ͷ�Ͷ�β��������Ӻͳ���
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//��ʼ�� �� ���ٶ���
void QueueInit(Queue* pQueue);
void QueueDestroy(Queue* pQueue);

// ��β�����    ��ͷ������
void QueuePush(Queue* pQueue, QDataType data);
void QueuePop(Queue* pQueue);

// ��ȡ����ͷ��Ԫ��   /��ȡ����β��Ԫ��
QDataType QueueFront(Queue* pQueue);
QDataType QueueBack(Queue* pQueue);

//��ȡ��������ЧԪ�ظ���	�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueSize(Queue* pQueue);
bool QueueEmpty(Queue* pQueue);



