#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct DNode {
	int data;
	struct DNode* prior;
	struct DNode* next;
}DNode, *DLinklist;

DLinklist InitDLinklist() {
	DLinklist head = (DNode*)malloc(sizeof(DNode));
	assert(head);
	head->data = 0;
	head->next = head;
	head->prior = head;
	return head;
}
bool EmptyJudge(DLinklist& head) {	//非空循环双链表  头结点指向的下一个节点非空
	assert(head);
	if (head->next == head)
		return true;
	return false;
}
//创建一个空节点
DNode* creatNode(int data) {
	DNode* newNode = (DNode*)malloc(sizeof(DNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	newNode->prior = NULL;
	return newNode;
}
bool isTail(DLinklist& head, DNode* node) {
	if (node->next == head)
		return true;
	return false;
}
// 头插法双向循环链表插入
void insertNode(DLinklist& head, int data) {
	DNode* newNode = creatNode(data);
	newNode->data = data;
	newNode->next = head->next;
	newNode->prior = head;
	head->next = newNode;
}

void DelDNode(DNode* p, DNode* q) {	//删除p结点之后的q结点
	p->next = q->next;
	q->next->prior = p;
	free(q);
}
int main() {
	return 0;
}