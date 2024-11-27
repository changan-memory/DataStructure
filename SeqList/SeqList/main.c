#include "SeqList.h"

void SeqTest1() {
	SeqList S;
	SLInit(&S);
	SLPushBack(&S, 1);
	SLPushBack(&S, 2);
	SLPushBack(&S, 3);
	SLPushBack(&S, 4);
	SLPushBack(&S, 5);
	SLPushBack(&S, 6);
	SLPushBack(&S, 7);
	SLPushBack(&S, 8);
	SLPushBack(&S, 9);
	SLPushBack(&S, 10);
	SLPrint(&S);
	SLPopBack(&S);
	SLPrint(&S);

	SLPopBack(&S);
	SLPrint(&S);

	SLDestroy(&S);
}

void SeqTest2() {
	SeqList S;
	SLInit(&S);
	SLPushFront(&S, 1);
	SLPushFront(&S, 2);
	SLPushFront(&S, 3);
	SLPushFront(&S, 4);

	SLPrint(&S);
	SLPopBack(&S);
	SLPushFront(&S, 5);
	SLPushFront(&S, 6);
	SLPushFront(&S, 7);
	SLPushFront(&S, 8);
	SLPopBack(&S);
	SLPrint(&S);
	//头插N个数据时间复杂度  O(N^2)
	//尾插N个数据时间复杂度  O(N)


}

int main() {

	//SeqTest1();
	SeqTest2();
	return 0;
}