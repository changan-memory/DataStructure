#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#include <time.h>


//������  ���öѵ�˼�� �������������
//ֻ�õ������Ϻ����µ���������Ҫ��������ݽṹ

//������ --------- �����
//�Ž��� --------- ��С��

// ���� -----  1 ���ϵ�������  ʱ�临�Ӷ�  O(N*logN)
void HeapSort(HeapDataType* arr, int size) {
	// �Ƚ���
	// ģ�����Ĺ���  ���ϵ���  ʵ�ֽ���
	// ͨ�� i ���ƶ�����ģ�����Ĺ���  
	// ���±� 1 ��ʼɨ�裬�������ϵ�����������˽���
	for (int i = 1; i < size; ++i)	//��ÿ���������ϵ������ͽ����˶�(����ʵ�ֵ��Ǵ��)
		AdjustUp(arr, i);					//����Ѻ�arr[0]������

	int end = size - 1;	// ���һ��Ԫ�ص��±�end, size�����һ��Ԫ�ص���һ��λ��,�±����ǰ�����ݵĸ���
	while (end > 0) {	//end > 0, ��� 0 �� 1����  ʱ�临�Ӷ� O(N*logN)
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, end, 0);	//��������ģ������Ĵ�С��Ϊsize-1��Ҳ����end
		--end;
	}
}

// ���� -----  2 ���µ�������  ʱ�临�Ӷ�  O(N)
void HeapSort_2(HeapDataType* arr, int size) {
	//��  ���һ��Ҷ�ӵĸ���(������һ����Ҷ�ӽڵ�)  ��ʼ������µ���
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
		AdjustDown(arr, size, i);

	int end = size - 1;	// ���һ��Ԫ�ص��±�end, size�����һ��Ԫ�ص���һ��λ��,�±����ǰ�����ݵĸ���
	while (end > 0) {	//end > 0, ��� 0 �� 1����  ʱ�临�Ӷ� O(N*logN)
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, end, 0);	//��������ģ������Ĵ�С��Ϊsize-1��Ҳ����end
		--end;
	}
}
void TestHeapSort() {
	int arr[10] = { 5, 9, 28, 99, 55, 2, 0, 100, 8, 14 };
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, sizeof(arr)/sizeof(arr[0]));
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//1G Լ���� 10���ֽ�
//Topk ���⣬��n�������У��ҵ�����ǰk��
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
	//����ǰk��Ԫ�ؽ���
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
	HeapPush(&hp, 4);
	HeapPush(&hp, 18);
	HeapPush(&hp, 42);
	HeapPush(&hp, 12);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);

	int k = 0;
	printf("������k\n");
	scanf("%d", &k);	//���ý��ѵĹ��̣���ȡǰk��Ԫ��
	//while (!HeapEmpty(&hp)) {
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