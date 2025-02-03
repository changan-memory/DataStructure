#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#include <time.h>


//堆排序  利用对的思想 对数组进行排序
//只用到了向上和向下调整，不需要堆这个数据结构
//排升序 --------- 建大堆
//排降序 --------- 建小堆
void HeapSort(HeapDataType* arr, int size) {
	// 建堆 -----  1 向上调整建堆  时间复杂度  O(N*logN)
	//for (int i = 1; i < size; i++) {	//让每个数都向上调整，就建成了堆(这里实现的是大堆)
	//	AdjustUp(arr, i);
	//}//建完堆后，arr[0]是最大的

	// 建堆 -----  2 向下调整建堆  时间复杂度  O(N)
	//从  最后一个叶子的父亲  开始逐次向下调整
	for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(arr, size, i);
	}

	int end = size - 1;	// 最后一个元素的下标end, size是最后一个元素的下一个位置,下标就是前面数据的个数
	while (end > 0) {	//end > 0, 最后和 1交换  时间复杂度 O(N*logN)
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, end, 0);	//交换过好，模拟数组的大小变为size-1，也就是end
		--end;
	}
}
void TestHeapSort() {
	int arr[10] = { 5, 9, 28, 99, 55, 2, 0, 100, 8, 14 };
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//1G 约等于 10亿字节
//Topk 问题，从n个数据中，找到最大的前k个
void TestTopK() {
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL) {
		perror("open error\n");
		return;
	}
	for (size_t i = 0; i < n; ++i) {
		int x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void PrintTopK(const char* file, int k) {
	int* topk = (int*)malloc(sizeof(int) * k);
	assert(topk);

	const char* fileName = "data.txt";
	FILE* fout = fopen(fileName, "r");
	if (fout == NULL) {
		perror("fopen error\n");
		return;
	}
	//读出前k个元素建堆
	for (int i = 0; i < k; i++) {
		fscanf(fout, "%d", &topk[i]);
	}
}
void TestPush() {
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 46);
	HeapPush(&hp, 18);
	HeapPush(&hp, 99);
	HeapPush(&hp, 6);
	HeapPush(&hp, 73);
	HeapPush(&hp, 5);
	HeapPush(&hp, 5);
	HeapPush(&hp, 15);
	HeapPush(&hp, 50);
	HeapPush(&hp, 5);
	HeapPush(&hp, 50);
	HeapPush(&hp, 15);
	HeapPush(&hp, 5);
	int k = 0;
	printf("请输入k\n");
	scanf("%d", &k);
	while (!HeapEmpty(&hp) && k--) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
}
int main() {
	TestPush();
	//TestHeapSort();
	//TestTopK();
	return 0;
}