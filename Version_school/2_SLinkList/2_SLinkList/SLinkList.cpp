#include "SLinkList.h"

void SLTPrint(const Node* head) {
	const Node* curNode = head;
	while (curNode) {
		printf("%d ", curNode->val);
		curNode = curNode->next;
	}
	printf("\n");
}

Node* BuySLTNode(SLTDataType val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		perror("malloc fail");
		return NULL;
	}
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

// 尾插尾删
void SLTPushBack(Node*& head, SLTDataType val) {
	// 创建节点
	Node* newNode = BuySLTNode(val);
	if (newNode == NULL) {
		perror("malloc failed");
		return;
	}
	// 插入节点
	if (head == NULL) {
		head = newNode;
		return;
	}
	// 找尾
	Node* tailNode = head;
	while (tailNode->next) {
		tailNode = tailNode->next;
	}
	tailNode->next = newNode;
}
void SLTPopBack(Node*& head) {
	//assert(head);
	if (head == NULL)
		return;
	Node* tailNode = head;
	Node* prevNode = NULL;
	// 找尾
	while (tailNode->next) {
		prevNode = tailNode;
		tailNode = tailNode->next;
	}
	// 找到尾了
	free(tailNode);
	tailNode = NULL;
	if (prevNode)
		prevNode->next = NULL;
	else
		head = NULL;
}

// 头插头删
void SLTPushFront(Node*& head, SLTDataType val) {
	// 创建节点
	Node* newNode = BuySLTNode(val);
	if (newNode == NULL) {
		perror("malloc fail");
		return;
	}
	// 插入节点
	if (head == NULL)
		head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
}
void SLTPopFront(Node*& head) {

}