#include "SLinkList.h"

void TestBack() {
	LinkList head = NULL;
	//Node* head = NULL;
	SLTPushBack(head, 1);
	SLTPushBack(head, 2);
	SLTPushBack(head, 3);
	SLTPushBack(head, 4);
	SLTPushBack(head, 5);

	SLTPopBack(head);
	SLTPopBack(head);
	SLTPrint(head);
	SLTPopBack(head);
	SLTPopBack(head);
	SLTPopBack(head);
	SLTPrint(head);
}

void TestFront() {
	LinkList head = NULL;
	//Node* head = NULL;
	SLTPushFront(head, 1);
	SLTPushFront(head, 2);
	SLTPushFront(head, 3);
	SLTPushFront(head, 4);
	SLTPushFront(head, 5);
	SLTPushFront(head, 6);
	SLTPrint(head);

	SLTPopFront(head);
	SLTPopFront(head);
	SLTPrint(head);
	SLTPopFront(head);
	SLTPopFront(head);
	SLTPopFront(head);
	SLTPopFront(head);

	SLTPrint(head);
}

int main() {
	//TestBack();
	TestFront();
	return 0;
}