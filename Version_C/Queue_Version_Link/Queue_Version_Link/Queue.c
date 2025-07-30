#include "Queue.h"

//��ʼ�� �� ���ٶ���
void QueueInit(Queue* pQueue) {
	assert(pQueue);
	pQueue->head = pQueue->tail = NULL;
	pQueue->size = 0;
}
//����
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

// ��β�����    ��ͷ������
void QueuePush(Queue* pQueue, QDataType data) {
	assert(pQueue);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL) {
		perror("malloc failed\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	// ��ʼ����head �� tail ��ΪNULL
	if (pQueue->head == NULL) {
		assert(pQueue->tail == NULL);	// headΪNULLʱ��tail����ҲΪNULL
		pQueue->head = pQueue->tail = newNode;
	}
	else {
		pQueue->tail->next = newNode;
		pQueue->tail = newNode;
	}
	pQueue->size++;
}
//���е�ͷɾ��
void QueuePop(Queue* pQueue) {
	assert(pQueue);
	assert(pQueue->head != NULL);

	////if(pQueue->head->next == NULL){}	//����ֻʣһ���������
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

	//�Ż��汾
	QNode* cur = pQueue->head;
	if (pQueue->head == pQueue->tail)
		pQueue->head = pQueue->tail = NULL;
	else
		pQueue->head = pQueue->head->next;

	free(cur);
	cur = NULL;
	pQueue->size--;
}

// ��ȡ����ͷ��Ԫ��   ��ȡ����β��Ԫ��
QDataType QueueFront(Queue* pQueue) {
	assert(pQueue);
	//ȷ�����зǿ�
	assert(!QueueEmpty(pQueue));
	return pQueue->head->data;
}
//��ȡ����β��Ԫ��
QDataType QueueBack(Queue* pQueue) {
	assert(pQueue);
	//ȷ�����зǿ�
	assert(!QueueEmpty(pQueue));
	return pQueue->tail->data;
}

//��ȡ��������ЧԪ�ظ���	�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
// ˫�������У������� �ڱ�λ������  ���洢 ����ĳ���
// ֮ǰ��ʵ���У�����ڴ�ŵ�������int�������ڱ�λ�ڵ�����λ����Ҳ��int,
int QueueSize(Queue* pQueue) {
	assert(pQueue);
	return pQueue->size;
}
bool QueueEmpty(Queue* pQueue) {
	assert(pQueue);
	//return (pQueue->head == NULL && pQueue->tail == NULL);
	return pQueue->size == 0;	// sizeΪ0ʱΪ��
}


////��ʼ�� �� ���ٶ���
//void QueueInit(Queue* pQueue) {
//	// ���нṹ����Ҫ����
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

//// ��β�����    ��ͷ������
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

//// ��ȡ����ͷ��Ԫ��   /��ȡ����β��Ԫ��
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
////��ȡ��������ЧԪ�ظ���	�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
//size_t QueueSize(Queue* pQueue) {
//	assert(pQueue);
//	return pQueue->size;
//}
//bool QueueEmpty(Queue* pQueue) {
//	assert(pQueue);
//	return pQueue->size == 0;
//}

