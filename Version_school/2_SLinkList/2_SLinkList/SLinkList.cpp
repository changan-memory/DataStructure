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

	// 插入节点
	if (head == NULL)
		head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
}
void SLTPopFront(Node*& head) {
	assert(head);
	Node* delNode = head;

	head = head->next;
	delNode->next = NULL;

	free(delNode);
	delNode = NULL;
}


Node* SLTFind(Node* head, SLTDataType val) {
	if (head == NULL)
		return NULL;
	Node* curNode = head;
	while (curNode) {
		if (curNode->val == val)
			return curNode;
		else
			curNode = curNode->next;
	}
	return NULL;
}

// 在pos之前插入结点 
void SLTInsert(Node*& head, Node* pos, SLTDataType val) {
	assert(pos);
	assert(head);
	// 头插
	if (pos == head) {
		SLTPushFront(head, val);
	}
	else {
		// 非头插
		Node* prevPos = NULL;
		Node* curNode = head;
		while (curNode != pos) {
			prevPos = curNode;
			curNode = curNode->next;
		}
		assert(curNode == pos);

		Node* newNode = BuySLTNode(val);
		prevPos->next = newNode;
		newNode->next = pos;
	}
}
// 删除pos位置的结点
void SLTErase(Node*& head, Node* pos) {
	assert(pos);
	assert(head);
	// 头删
	if (pos == head) {
		SLTPopFront(head);
		return;
	}
	else {
		// 非头删
		Node* prevPos = NULL;
		Node* curNode = head;
		while (curNode != pos) {
			prevPos = curNode;
			curNode = curNode->next;
		}
		assert(curNode == pos); // 确保pos在链表中
		// 改链接关系
		prevPos->next = pos->next;
		free(pos);
		pos = NULL;
	}
}



// pos后面插入   
void SLTInsertAfter(Node* pos, SLTDataType val) {
	assert(pos);
	Node* newNode = BuySLTNode(val);
	// 先连上，再断开
	newNode->next = pos->next;
	pos->next = newNode;
}

// 删除pos后面的结点
void SLTEraseAfter(Node* pos) {
	assert(pos);
	assert(pos->next);
	Node* delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
	delNode = NULL;
}