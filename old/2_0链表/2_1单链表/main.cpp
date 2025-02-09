#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node {
	int data;	//数据域
	struct Node* next;	//指针域
};
//创建链表头
struct Node* creatList() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//初始化
	headNode->data = 0;
	headNode->next = NULL;
	return headNode;
}
//创建新结点    
struct Node* creatNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//插入新结点
void insertNodeByhead(struct Node* headNode, int data) {
	struct Node* newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}//节点的形成需要创建后插入

void insertNodeBytail(struct Node* headNode, int data) {
	struct Node* newNode = creatNode(data);
}

//打印链表
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
	//此时posNode 已经指向了 待删除的结点
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