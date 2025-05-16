#include "Stack.h"

typedef struct {
	Stack st1;  //入队栈
	Stack st2;  //出队栈
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	if (pq == NULL) {
		perror("malloc failed\n");
		return NULL;
	}
	StackInit(&pq->st1);
	StackInit(&pq->st2);
	return pq;
}

void myQueuePush(MyQueue* obj, int x) {
	// st1为入队栈，st2为出队栈
	StackPush(&obj->st1, x);
}

int myQueuePop(MyQueue* obj) {
	// 如果出队栈为空，将入队栈所有元素倒到出队栈
	if (StackEmpty(&obj->st2)) {
		while (!StackEmpty(&obj->st1)) {
			StackPush(&obj->st2, StackTop(&obj->st1));
			StackPop(&obj->st1);
		}
	}

	// 此时出队栈顶即为队列头部元素
	int data = StackTop(&obj->st2);
	StackPop(&obj->st2);
	return data;
}

int myQueuePeek(MyQueue* obj) {
	//出队栈为空，倒全部数据
	if (StackEmpty(&obj->st2)) {
		while (!StackEmpty(&obj->st1)) {
			StackPush(&obj->st2, StackTop(&obj->st1));
			StackPop(&obj->st1);
		}
	}
	return StackTop(&obj->st2);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->st1) && StackEmpty(&obj->st2);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->st1);
	StackDestroy(&obj->st2);
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