#include "SeqList.h"

void TestPushPopBack(){
	SeqList L;
	SeqListInit(L);

	PushBack(L, 1);

	PushBack(L, 2);
	PushBack(L, 3);
	PushBack(L, 4);
	PushBack(L, 5);
	SeqListPrint(L);

	PopBack(L);
	PopBack(L);
	SeqListPrint(L);
	SeqListDestroy(L);
}

void TestPushPopFront() {
	SeqList L;
	SeqListInit(L);
	PushFront(L, 1);
	PushFront(L, 2);
	PushFront(L, 3);
	PushFront(L, 4);
	PushFront(L, 5);
	SeqListPrint(L);

	PopFront(L);
	PopFront(L);
	SeqListPrint(L);
	
	SeqListDestroy(L);
}
int main() {
	TestPushPopBack();
	//TestPushPopFront();

	return 0;
}