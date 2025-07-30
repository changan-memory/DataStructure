// 两个队列是实现一个栈
// 解答leetcode时需要将队列的源代码复制下来

#include "Queue.h"

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

MyStack* myStackCreate() {
	MyStack* mStack = (MyStack*)malloc(sizeof(MyStack));
	if (mStack == NULL) {
		perror("malloc failed\n");
		return NULL;
	}
	// 两个q也要初始化
	QueueInit(&mStack->q1);
	QueueInit(&mStack->q2);
	return mStack;
}

void myStackPush(MyStack* obj, int x) {
	// 选择非空的队列插入，若都空则选任意（如q1）
	if (!QueueEmpty(&obj->q1)) {
		QueuePush(&obj->q1, x);
	}
	else {
		QueuePush(&obj->q2, x);
	}
}

// Pop需要搬运数据
int myStackPop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1)) {
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	// 倒数据
	while (QueueSize(nonemptyQ) > 1) {
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}
	QDataType top = QueueFront(nonemptyQ);
	QueuePop(nonemptyQ);
	return top;
}

int myStackTop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1)) {
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	return QueueBack(nonemptyQ);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
	obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/