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
	PopBack(L);
	PopBack(L);
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
	PopFront(L);
	PopFront(L);
	SeqListPrint(L);

	PopFront(L);
	PopFront(L);
	SeqListPrint(L);
	
	SeqListDestroy(L);
}
void TestInsertErase() {
	SeqList L;
	SeqListInit(L);
	SeqListInsert(L, 0, 1);
	SeqListInsert(L, 1, 2);
	SeqListInsert(L, 2, 3);
	SeqListInsert(L, L.size, 4);
	SeqListPrint(L);

	SeqListErase(L, 0);
	SeqListErase(L, L.size - 1);
	SeqListErase(L, 1);
	SeqListPrint(L);

	SeqListDestroy(L);

}
int main() {
	//TestPushPopBack();
	//TestPushPopFront();
	TestInsertErase();


	return 0;
}