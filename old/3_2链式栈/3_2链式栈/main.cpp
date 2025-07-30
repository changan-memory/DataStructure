#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
//链式栈是运算受限的单链表  操作只能在表头进行
typedef struct StackNode {
	int data;
	struct StackNode* prior;	//由于栈的后入先出特性，链式栈的  栈顶结点指向的是前一个结点的位置
}StackNode, *LinkStack;

LinkStack S;//这是一个指针  指向栈节点    栈链表不需要表头

//头结点即为栈顶  栈链表不需要表头
// 插入和删除都在表头进行

void InitStack(LinkStack& S) {
	S = NULL;
}
//判断栈是否为空
bool EmptyJudge(LinkStack S) {
	if (S == NULL)
		return true;
	return false;
}
//链式栈的入栈
void PushStack(LinkStack& S, int data) {
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	assert(newNode);
	newNode->data = data;
	newNode->prior = S;	//S初始为空指针
	S = newNode;
}
//链式栈的出栈
void PopStcak(LinkStack& S, int& ele) {
	assert(S);
	StackNode* p = S;
	ele = S->data;
	S = S->prior;
	free(p);
}

//打印链式栈
void printLStcak(LinkStack& S) {
	StackNode* pMove = S;
	while (pMove != NULL) {
		printf("%d ", pMove->data);
		pMove = pMove->prior;
	}
	printf("\n");
}

//取栈顶元素
int GetEle(LinkStack& S) {
	assert(S);
	return S->data;
}
int main() {
	InitStack(S);
	PushStack(S, 1);
	PushStack(S, 2);
	PushStack(S, 3);
	PushStack(S, 4);
	PushStack(S, 5);
	PushStack(S, 6);
	PushStack(S, 7);
	PushStack(S, 8);
	printLStcak(S);
	int x = 0;
	PopStcak(S, x);
	printLStcak(S);
	printf("%d ", x);
	return 0;
}