#define _CRT_SECURE_NO_WARNINGS 1
#define MaxQsize 10

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//循环队列牺牲了一个存储空间

typedef struct {
	int front; //数组队头
	int rear;	//数组队尾
	int* base; //数组基地址
}SqQuence;
SqQuence Q;
//初始化一个队列
bool InitSqQuence(SqQuence& Q) {
	Q.base = (int*)malloc(sizeof(int) * MaxQsize);	//申请连续的数组空间
 	//Q.base = new int[MaxQsize];  也可用C++的动态申请内存的方式
	assert(Q.base);
	Q.front = 0;
	Q.rear = 0;
	return true;
}

//	获取循环队列的长度
int GetQlength(SqQuence& Q) {
	return (Q.rear - Q.front + MaxQsize) % MaxQsize;
}

//	循环队列入队
bool PushQuence(SqQuence& Q, int ele) {   
	if ((Q.rear + 1) % MaxQsize == Q.front)	//判断是否队满
		return false;

	Q.base[Q.rear] = ele;
	Q.rear = (Q.rear + 1) % MaxQsize;	//这里考虑了循环队列入队后rear指针的变化
}

//循环队列出队
int PopQuence(SqQuence& Q, int& x) {
	x = Q.base[Q.front];
	Q.front = (Q.front + MaxQsize) % MaxQsize;
	return 	x;	//	只能在队列头出队
}

// 取队头元素
int GetFrontele(SqQuence& Q) {
	if (Q.front == Q.rear)
		return false;
	return Q.base[Q.front];   //只返回队头元素  队头指针不变
}

//遍历队列
void printQuence(SqQuence& Q) {
	if (Q.rear > Q.front) {
		for (int i = Q.front; i < Q.rear; i++)
			printf("%d ", Q.base[i]);
		printf("\n");
	}
	if (Q.rear < Q.front) {
		for (int i = Q.front; i > Q.rear; i--)
			printf("%d ", Q.base[i]);
		printf("\n");
	}
}
int main() {
	InitSqQuence(Q);
	PushQuence(Q, 9);
	PushQuence(Q, 8);
	PushQuence(Q, 7);
	PushQuence(Q, 6);
	PushQuence(Q, 5);
	PushQuence(Q, 4);
	PushQuence(Q, 3);
	PushQuence(Q, 2);
	printQuence(Q);
	return 0;
}