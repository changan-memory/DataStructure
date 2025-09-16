#include "head.h"

//初始化循环队列
bool InitSqQuence(SqQuence& Q) {
	Q.front = 0;
	Q.rear = 0;
	return true;
}

//	循环队列入队
bool PushQuence(SqQuence& Q, BiNode* ele) {
	if ((Q.rear + 1) % MaxSize == Q.front)	//判断是否队满
		return false;

	Q.data[Q.rear] = ele;
	Q.rear = (Q.rear + 1) % MaxSize;	//这里考虑了循环队列入队后rear指针的变化
}

//循环队列出队
BiTree PopQuence(SqQuence& Q, BiNode* x) {
	x = Q.data[Q.front];
	Q.front = (Q.front + MaxSize) % MaxSize;
	return 	x;	//	只能在队列头出队
}

bool QuenceEmpty(SqQuence& Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}


void LevelOrder(BiNode* B) {
	BiNode* p = NULL;
	SqQuence qu;	// 遍历的时候初始化一个局部队列
	InitSqQuence(qu);

	PushQuence(qu, B);	//将传入的初始根结点 入队
	while (!QuenceEmpty(qu)) {	// 只要 队列中非空 就进入循环
		PopQuence(qu, p);	// 让结点出队， 对出队的结点进行访问 
		assert(p);
		printf("%d ", p->data);
		if (p->Lchild != NULL)		// 刚刚出队的结点 后面  只要有  左右结点  就分别入队
			PushQuence(qu, p->Lchild);
		if (p->Rchild != NULL)
			PushQuence(qu, p->Rchild);
	}
}
