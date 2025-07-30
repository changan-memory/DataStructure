#include "Stack.h"

typedef struct {
	Stack pushST;  //���ջ
	Stack popST;  //����ջ
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	if (pq == NULL) {
		perror("malloc failed\n");
		return NULL;
	}
	StackInit(&pq->pushST);
	StackInit(&pq->popST);
	return pq;
}

void myQueuePush(MyQueue* obj, int x) {
	// pushSTΪ���ջ��popSTΪ����ջ
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj) {
	// �������ջΪ�գ������ջ����Ԫ�ص�������ջ
	if (StackEmpty(&obj->popST)) {
		while (!StackEmpty(&obj->pushST)) {
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	// ��ʱ����ջ����Ϊ����ͷ��Ԫ��
	int data = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return data;
}

int myQueuePeek(MyQueue* obj) {
	//����ջΪ�գ���ȫ������
	if (StackEmpty(&obj->popST)) {
		while (!StackEmpty(&obj->pushST)) {
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
	obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/