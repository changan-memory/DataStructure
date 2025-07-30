#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, *QuencePtr;	//前者是强调结点  后者强调表头
//结点   指向头结点的指针

typedef struct {
	QuencePtr front;
	QuencePtr rear;
}LinkQuence;

LinkQuence Q;

//初始化链队列
bool InitLinkQuence(LinkQuence& Q) {	//初始化队列头
	//两个指针分别指向 头结点
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));//传入指针构成的结构体 申请一块空间,让两个指针指向这片空间
	if (!Q.front)
		return false;
	assert(Q.front);
	Q.front->next = NULL;
	return true;
}

//销毁一个链队列
bool DestroyQuence(LinkQuence& Q) {
	QuencePtr p = NULL;
	while (Q.front) {
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
		//链表都要销毁了，尾指针留着也没用，不如好好利用
		//Q.rear = Q.front->next;
		//free(Q.front);
		//Q.front = Q.rear;
	}
	return true;
}

//链式队列入队
bool InsertLQuence(LinkQuence& Q, int ele) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	newNode->next = NULL;
	newNode->data = ele;
	Q.rear->next = newNode;
	Q.rear = newNode;
	return true;
}

//链队列出队
bool PopLQuence(LinkQuence& Q, int& ele) {
	if (Q.front == Q.rear)
		return false;
	QNode* p = Q.front->next;
	if (p == Q.rear) {	// 出队的是队列的最后一个结点是 特殊处理
		Q.rear = Q.front;
		Q.front = NULL;
		free(p);
	}
	else {
		Q.front->next = p->next;
		ele = p->data;
		free(p);
		return true;
	}
}

//获取队列的队头元素
bool GeteleHead(LinkQuence& Q, int& ele) {	//用一个外部变量接受 链式队头的元素
	if (Q.rear != Q.rear) {
		ele = Q.front->data;
		return true;
	}
	return false;
}

//遍历链式队列
void printLQuence(LinkQuence& Q) {
	QNode* pMove = Q.front->next;
	while (pMove) {
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
int main() {
	InitLinkQuence(Q);
	InsertLQuence(Q, 5);
	InsertLQuence(Q, 4);
	InsertLQuence(Q, 3);
	InsertLQuence(Q, 2);
	printLQuence(Q);
	printLQuence(Q);
	DestroyQuence(Q);
	return 0;
}