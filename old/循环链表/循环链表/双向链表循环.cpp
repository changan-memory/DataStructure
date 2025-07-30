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
bool EmptyJudge(DLinklist& head) {	//�ǿ�ѭ��˫����  ͷ���ָ�����һ���ڵ�ǿ�
	assert(head);
	if (head->next == head)
		return true;
	return false;
}
//����һ���սڵ�
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
// ͷ�巨˫��ѭ���������
void insertNode(DLinklist& head, int data) {
	DNode* newNode = creatNode(data);
	newNode->data = data;
	newNode->next = head->next;
	newNode->prior = head;
	head->next = newNode;
}

void DelDNode(DNode* p, DNode* q) {	//ɾ��p���֮���q���
	p->next = q->next;
	q->next->prior = p;
	free(q);
}
int main() {
	return 0;
}