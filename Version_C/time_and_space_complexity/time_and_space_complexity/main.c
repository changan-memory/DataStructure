#include<stdio.h>

int BinSearch(int arr[], int val, int size)
{
	int left = 0, right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] > val)
			right = mid - 1;
		else if (arr[mid] < val)
			left = mid + 1;
		else
			return mid;   // ÕÒµ½
	}

	return -1; // Ã»ÕÒµ½
}

void F1()
{
	int a = 10;
	printf("%p\n", &a);
}

void F2()
{
	int b = 10;
	printf("%p\n", &b);
}
int main()
{
	F1();
	F2();
	return 0;
}