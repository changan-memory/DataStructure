#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, *QuencePtr;	//ǰ����ǿ�����  ����ǿ����ͷ
//���   ָ��ͷ����ָ��

typedef struct {
	QuencePtr front;
	QuencePtr rear;
}LinkQuence;

LinkQuence Q;

//��ʼ��������
bool InitLinkQuence(LinkQuence& Q) {	//��ʼ������ͷ
	//����ָ��ֱ�ָ�� ͷ���
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));//����ָ�빹�ɵĽṹ�� ����һ��ռ�,������ָ��ָ����Ƭ�ռ�
	if (!Q.front)
		return false;
	assert(Q.front);
	Q.front->next = NULL;
	return true;
}

//����һ��������
bool DestroyQuence(LinkQuence& Q) {
	QuencePtr p = NULL;
	while (Q.front) {
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
		//����Ҫ�����ˣ�βָ������Ҳû�ã�����ú�����
		//Q.rear = Q.front->next;
		//free(Q.front);
		//Q.front = Q.rear;
	}
	return true;
}

//��ʽ�������
bool InsertLQuence(LinkQuence& Q, int ele) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	newNode->next = NULL;
	newNode->data = ele;
	Q.rear->next = newNode;
	Q.rear = newNode;
	return true;
}

//�����г���
bool PopLQuence(LinkQuence& Q, int& ele) {
	if (Q.front == Q.rear)
		return false;
	QNode* p = Q.front->next;
	if (p == Q.rear) {	// ���ӵ��Ƕ��е����һ������� ���⴦��
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

//��ȡ���еĶ�ͷԪ��
bool GeteleHead(LinkQuence& Q, int& ele) {	//��һ���ⲿ�������� ��ʽ��ͷ��Ԫ��
	if (Q.rear != Q.rear) {
		ele = Q.front->data;
		return true;
	}
	return false;
}

//������ʽ����
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