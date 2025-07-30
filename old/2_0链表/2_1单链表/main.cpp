#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node {
	int data;	//������
	struct Node* next;	//ָ����
};
//��������ͷ
struct Node* creatList() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//��ʼ��
	headNode->data = 0;
	headNode->next = NULL;
	return headNode;
}
//�����½��    
struct Node* creatNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//�����½��
void insertNodeByhead(struct Node* headNode, int data) {
	struct Node* newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}//�ڵ���γ���Ҫ���������

void insertNodeBytail(struct Node* headNode, int data) {
	struct Node* newNode = creatNode(data);
}

//��ӡ����
void printList(struct Node* headNode) {
	struct Node* pMove = headNode->next;
	while (pMove) {
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
void deleteNode(struct Node* headNode, int posData) {
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	assert(posNode);
	while (posNode->data != posData) {
		/*posNode = posNode->next;
		posNodeFront = posNodeFront->next;*/
		posNodeFront = posNode;
		posNode = posNodeFront->next;
	}
	//��ʱposNode �Ѿ�ָ���� ��ɾ���Ľ��
	posNodeFront->next = posNode->next;
	free(posNode);
}
int main() {
	struct Node* headNode = creatList();
	insertNodeByhead(headNode, 1);
	insertNodeByhead(headNode, 5);
	insertNodeByhead(headNode, 4);
	insertNodeByhead(headNode, 6);
	printList(headNode);
	deleteNode(headNode, 4);
	printList(headNode);
	return 0;
}