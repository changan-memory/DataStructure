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
	int arr[] = { 4, 6, 3, 2, 1, 0, 0, 5, 11 , 8, 2};
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	shellSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
}

int main() 
{
	//testInsertSort();
	testShellSort();
	return 0;
}