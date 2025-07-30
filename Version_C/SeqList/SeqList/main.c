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
	//ͷ��N������ʱ�临�Ӷ�  O(N^2)
	//β��N������ʱ�临�Ӷ�  O(N)

}

void SeqTest3() {
	SeqList S;
	SLInit(&S);
	SLInsert(&S, 0, 1);
	SLInsert(&S, 1, 2);
	SLInsert(&S, 2, 3);
	SLInsert(&S, 3, 4);
	SLInsert(&S, 4, 5);
	SLInsert(&S, 5, 5);
	SLInsert(&S, 6, 5);
	SLPrint(&S);

	SLInsert(&S, 3, 400);
	SLInsert(&S, 3, 400);
	SLInsert(&S, 3, 400);
	SLInsert(&S, 3, 400);
	SLPrint(&S);

	SLErase(&S, 3);
	SLErase(&S, 3);
	SLErase(&S, 0);
	SLPrint(&S);
	SLErase(&S, S.size-1);
	SLPrint(&S);

}

//���԰Ѹ�˳���Ĳ���д��һ���˵�

void menu() {
	printf("-----------------------------------------\n");
	printf("--------1. β������  2. βɾ����---------\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
}

int main() {

	//SeqTest1();
	//SeqTest2();
	SeqTest3();

		
	return 0;
}