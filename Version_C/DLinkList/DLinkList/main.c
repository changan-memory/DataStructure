#include "DLinkList.h"

void TestDLinkList() {
	ListNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPrint(pList);

	ListPopBack(pList);
	ListPopBack(pList);
	ListPopBack(pList);
	ListPrint(pList);

	ListPushFront(pList, 6);
	ListPushFront(pList, 5);
	ListPushFront(pList, 4);
	ListPrint(pList);

	ListPopFront(pList);
	ListPopFront(pList);
	ListPrint(pList);

	ListPopFront(pList);
	ListPrint(pList);

	ListPopFront(pList);
	ListPrint(pList);

	ListPushFront(pList, 6);
	ListPushFront(pList, 5);
	ListPushFront(pList, 4);
	ListPrint(pList);

}
int main() {

	TestDLinkList();
	return 0;
}
