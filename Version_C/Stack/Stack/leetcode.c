#include "Stack.h"

typedef struct {
	Stack pushST;  //入队栈
	Stack popST;  //出队栈
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
	// pushST为入队栈，popST为出队栈
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj) {
	// 如果出队栈为空，将入队栈所有元素倒到出队栈
	if (StackEmpty(&obj->popST)) {
		while (!StackEmpty(&obj->pushST)) {
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	// 此时出队栈顶即为队列头部元素
	int data = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return data;
}

int myQueuePeek(MyQueue* obj) {
	//出队栈为空，倒全部数据
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