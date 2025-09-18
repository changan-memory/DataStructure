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

// β��βɾ
void SLTPushBack(Node*& head, SLTDataType val) {
	// �����ڵ�
	Node* newNode = BuySLTNode(val);
	if (newNode == NULL) {
		perror("malloc failed");
		return;
	}
	// ����ڵ�
	if (head == NULL) {
		head = newNode;
		return;
	}
	// ��β
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
	// ��β
	while (tailNode->next) {
		prevNode = tailNode;
		tailNode = tailNode->next;
	}
	// �ҵ�β��
	free(tailNode);
	tailNode = NULL;
	if (prevNode)
		prevNode->next = NULL;
	else
		head = NULL;
}

// ͷ��ͷɾ
void SLTPushFront(Node*& head, SLTDataType val) {
	// �����ڵ�
	Node* newNode = BuySLTNode(val);
	if (newNode == NULL) {
		perror("malloc fail");
		return;
	}
	// ����ڵ�
	if (head == NULL)
		head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
}
void SLTPopFront(Node*& head) {

}