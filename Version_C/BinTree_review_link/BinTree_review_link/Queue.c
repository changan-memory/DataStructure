#include "Queue.h"

//初始化 与 销毁队列
void QueueInit(Queue* pQueue) {
	assert(pQueue);
	pQueue->head = pQueue->tail = NULL;
	pQueue->size = 0;
}
//销毁
void QueueDestroy(Queue* pQueue) {
	assert(pQueue);
	QNode* cur = pQueue->head;
	while (cur != NULL) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pQueue->head = pQueue->tail = NULL;
	pQueue->size = 0;
}

// 队尾入队列    队头出队列
void QueuePush(Queue* pQueue, QDataType data) {
	assert(pQueue);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL) {
		perror("malloc failed\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	// 初始化后，head 和 tail 都为NULL
	if (pQueue->head == NULL) {
		assert(pQueue->tail == NULL);	// head为NULL时，tail必须也为NULL
		pQueue->head = pQueue->tail = newNode;
	}
	else {
		pQueue->tail->next = newNode;
		pQueue->tail = newNode;
	}
	pQueue->size++;
}
//队列的头删法
void QueuePop(Queue* pQueue) {
	assert(pQueue);
	assert(pQueue->head != NULL);

	////if(pQueue->head->next == NULL){}	//考虑只剩一个结点的情况
	//if (pQueue->head == pQueue->tail) {	
	//	free(pQueue->head);
	//	pQueue->head = pQueue->tail = NULL;
	//}
	//else {
	//	QNode* cur = pQueue->head;
	//	pQueue->head = pQueue->head->next;
	//	free(cur);
	//	cur = NULL;
	//}
	//pQueue->size--;

	//优化版本
	QNode* cur = pQueue->head;
	if (pQueue->head == pQueue->tail)
		pQueue->head = pQueue->tail = NULL;
	else
		pQueue->head = pQueue->head->next;

	free(cur);
	cur = NULL;
	pQueue->size--;
}

// 获取队列头部元素   获取队列尾部元素
QDataType QueueFront(Queue* pQueue) {
	assert(pQueue);
	//确保队列非空
	assert(!QueueEmpty(pQueue));
	return pQueue->head->data;
}
//获取队列尾部元素
QDataType QueueBack(Queue* pQueue) {
	assert(pQueue);
	//确保队列非空
	assert(!QueueEmpty(pQueue));
	return pQueue->tail->data;
}

//获取队列中有效元素个数	检测队列是否为空，如果为空返回非零结果，如果非空返回0
// 双向链表中，不能用 哨兵位的数据  来存储 链表的长度
// 之前的实现中，结点内存放的数据是int，导致哨兵位内的数据位类型也是int,
int QueueSize(Queue* pQueue) {
	assert(pQueue);
	return pQueue->size;
}
bool QueueEmpty(Queue* pQueue) {
	assert(pQueue);
	//return (pQueue->head == NULL && pQueue->tail == NULL);
	return pQueue->size == 0;	// size为0时为空
}


////初始化 与 销毁队列
//void QueueInit(Queue* pQueue) {
//	// 队列结构体需要存在
//	assert(pQueue);
//	pQueue->head = pQueue->tail = NULL;
//	pQueue->size = 0;
//}
//void QueueDestroy(Queue* pQueue) {
//	assert(pQueue);
//	QNode* cur = pQueue->head;
//	while (cur != NULL) {
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pQueue->head = pQueue->tail = NULL;
//	pQueue->size = 0;
//}

//// 队尾入队列    队头出队列
//void QueuePush(Queue* pQueue, QDataType data) {
//	assert(pQueue);
//	QNode* newNode = (QNode*)malloc(sizeof(QNode));
//	if (newNode == NULL) {
//		perror("malloc failed\n");
//		return;
//	}
//	newNode->data = data;
//	newNode->next = NULL;
//	if (QueueEmpty(pQueue)) {
//		pQueue->head = newNode;
//		pQueue->tail = newNode;
//	}
//	else {
//		pQueue->tail->next = newNode;
//		pQueue->tail = newNode;
//	}
//	pQueue->size++;
//}
//void QueuePop(Queue* pQueue) {
//	assert(pQueue);
//	assert(!QueueEmpty(&pQueue));
//	if (pQueue->head == pQueue->tail) {
//		free(pQueue->head);
//		pQueue->head = pQueue->tail = NULL;
//	}
//	else {
//		QNode* next = pQueue->head->next;
//		free(pQueue->head);
//		pQueue->head = next;
//	}
//	pQueue->size--;
//}

//// 获取队列头部元素   /获取队列尾部元素
//QDataType QueueFront(Queue* pQueue) {
//	assert(pQueue);
//	assert(!QueueEmpty(pQueue));
//	return pQueue->head->data;
//}
//QDataType QueueBack(Queue* pQueue) {
//	assert(pQueue);
//	assert(!QueueEmpty(pQueue));
//	return pQueue->tail->data;
//}
//
////获取队列中有效元素个数	检测队列是否为空，如果为空返回非零结果，如果非空返回0
//size_t QueueSize(Queue* pQueue) {
//	assert(pQueue);
//	return pQueue->size;
//}
//bool QueueEmpty(Queue* pQueue) {
//	assert(pQueue);
//	return pQueue->size == 0;
//}

