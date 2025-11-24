#include "Sort.h"

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	
	printf("\n");
}

void testInsertSort()
{
	int arr[] = { 4, 6, 3, 2, 1, 0, 0, 5, 11 };
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	insertSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void testShellSort()
{
	//int arr[] = { 4, 6, 3, 2, 1, 0, 0, 5, 11 , 8, 2};
	int arr[] = { 50, 1, 49, 2, 48, 3, 47, 4, 46, 5, 45, 6, 44, 7, 43, 8 };
	
	//int arr[] = { 5, 2, 4, 6, 1, 3 };
	//int arr[] = { 9, 8, 7, 6, 5 ,4};
	
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	shellSort_1(arr, sizeof(arr) / sizeof(arr[0]));
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void testSelectSort()
{
	//int arr[] = { 4, 6, 3, 2, 1, 0, 0, 5, 11 , 8, 2};
	int arr[] = { 50, 1, 49, 2, 48, 3, 47, 4, 46, 5, 45, 6, 44, 7, 43, 8 };

	//int arr[] = { 5, 2, 4, 6, 1, 3 };
	//int arr[] = { 9, 8, 7, 6, 5 ,4};

	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void testBubbleSort()
{
	//int arr[] = { 4, 6, 3, 2, 1, 0, 0, 5, 11 , 8, 2};
	int arr[] = { 50, 1, 49, 2, 48, 3, 47, 4, 46, 5, 45, 6, 44, 7, 43, 8 };

	//int arr[] = { 5, 2, 4, 6, 1, 3 };
	//int arr[] = { 9, 8, 7, 6, 5 ,4};

	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void testQuickSort()
{
	//int arr[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
	int arr[] = {6, 1, 2, 6, 9, 3, 6, 5, 10, 8};

	//int arr[] = { 5, 2, 4, 6, 1, 3 };

	//int arr[] = { 9, 8, 7, 6, 5 ,4};

	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	quickSort_1(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
}


// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	shellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//quickSort(a2, 0, N - 1);
	//quickSort_1(a2, 0, N - 1);
	//quickSort_2(a2, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end7 - begin7);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
int main() 
{
	//testInsertSort();
	//testShellSort();
	//testSelectSort();
	//testBubbleSort();

	//testQuickSort();

	TestOP();
	return 0;
}