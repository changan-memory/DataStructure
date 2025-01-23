#include "SLinkList.h"

void TestLinkList1() {
	SListNode* pList = NULL;
	SLTPushBack(&pList, 1);
	SLTPushBack(&pList, 2);
	SLTPushBack(&pList, 3);
	SLTPushBack(&pList, 4);
	SLTPrint(pList);

	SLTPushFront(&pList, 2);
	SLTPushFront(&pList, 3);
	SLTPushFront(&pList, 4);
	SLTPushFront(&pList, 5);
	SLTPrint(pList);

	SLTPopBack(&pList);
	SLTPopBack(&pList);
	SLTPrint(pList);
	SLTPopBack(&pList);
	SLTPopBack(&pList);
	SLTPrint(pList);
	SLTPopBack(&pList);
	SLTPopBack(&pList);
	SLTPopBack(&pList);
	SLTPopBack(&pList);
	SLTPrint(pList);

	SLTPopBack(&pList);
	SLTPrint(pList);
}

void TestLinkList2() {
	SListNode* pList = NULL;
	SLTPushBack(&pList, 1);
	SLTPushBack(&pList, 2);
	SLTPushBack(&pList, 3);
	SLTPushBack(&pList, 4);
	SLTPrint(pList);

	SLTPushFront(&pList, 2);
	SLTPushFront(&pList, 3);
	SLTPushFront(&pList, 4);
	SLTPushFront(&pList, 5);
	SLTPrint(pList);

	SLTPopFront(&pList);
	SLTPopFront(&pList);
	SLTPopFront(&pList);
	SLTPopFront(&pList);
	SLTPrint(pList);

	SLTPopFront(&pList);
	SLTPopFront(&pList);
	SLTPopFront(&pList);
	SLTPopFront(&pList);
	SLTPrint(pList);

}

void TestFind() {
	SListNode* head = NULL;
	SLTPushBack(&head, 1);
	SLTPushBack(&head, 2);
	SLTPushBack(&head, 3);
	SLTPushBack(&head, 4);
	SLTPrint(head);
	SListNode* retNode = SListFind(head, 2);
	retNode->data *= 2;
	SLTPrint(head);
	SListInsert(&head, retNode, 9);
	SListInsert(&head, retNode, 9);
	SListErase(&head, retNode);
	SLTPrint(head);

}
int main() {

	//TestLinkList1();
	//TestLinkList2();
	TestFind();
	return 0;
}