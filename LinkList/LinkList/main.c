#include "LinkList.h"

void TestLinkList1() {
	SListNode* pList = NULL;
	SLTPushBack(&pList, 1);
	SLTPushBack(&pList, 2);
	SLTPushBack(&pList, 3);
	SLTPushBack(&pList, 4);
	SLTPrint(pList);
}
//void Func(int* ptr) {
//
//	ptr = (int*)malloc(sizeof(int));
//	*ptr = 100;
//}

int main() {

	TestLinkList1();
	/*int* px = NULL;
	Func(px);
	printf("%d", *px);*/
	return 0;
}