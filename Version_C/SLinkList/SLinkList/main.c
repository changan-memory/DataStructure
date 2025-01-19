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
int main() {

	//TestLinkList1();
	TestLinkList2();

	return 0;
}