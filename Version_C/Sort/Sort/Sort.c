#include "Sort.h"

// 最坏 O(N^2) 
// 最好 O(N)
void insertSort(int* arr, int size)
{
	// 对从 下标为 1 开始 的每个数，都进行插入排序
	for (int i = 1; i < size; ++i)
	{
		// 对一个数进行插入排序的逻辑
		int end = i - 1;			// 有序部分的  最后一个数的下标
		int tmp = arr[i];			// 接下来要进行  插入排序 的数

		while (end >= 0)
		{
			if (tmp >= arr[end])
			{
				break;
			}
			// tmp < arr[end] 时，挪动数据，进行 插入逻辑
			else
			{
				arr[end + 1] = arr[end];
				--end;
			}
		}
		// 循环结束后，有两种情况
		// 1. end 为 -1
		// 2. tmp >= arr[end]
		arr[end + 1] = tmp;		// 两种情况均执行该操作即可
	}
}

// gap 越大，跳的越快，就越不接近有序
// 先排三组中的第一组，再排三组的第二组
// gap > 1 
void shellSort(int* arr, int size)
{
	int gap = size;
	
	while (gap > 1)
	{
		gap /= 2;
		// gap = gap / 3 + 1;
		
		// 跳跃插入排序    把 gap 换成 1，就是直接插入排序
		for (int i = 0; i < size - gap; ++i)
		{
			// 希尔排序的预排序逻辑
			// 只是将 直接插入排序中的 一步一步跳，改成了一次跳 gap 步
			int end = i;				// 当前组中  有序部分的 最后一个数的下标
			int tmp = arr[end + gap];				// 当前组中  接下来要进行插入 排序 的数

			while (end >= 0)
			{
				if (tmp >= arr[end])
				{
					break;
				}
				else
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

// 先排第一组，再排第二组，再排第三组
void shellSort_1(int* arr, int size)
{
	int gap = size;

	while (gap > 1)
	{
		gap /= 2;

		// 多组 跳跃插入排序   gap 是几，就被分成了几组
		for (int j = 0; j < gap; j++)
		{
			// 一组 跳跃插入排序    把 gap 换成 1，就是直接插入排序
			for (int i = j; i < size - gap; i += gap)
			{
				// 希尔排序的预排序逻辑
				// 只是将 直接插入排序中的 一步一步跳，改成了一次跳 gap 步
				int end = i;					// 当前组中  有序部分的 最后一个数的下标
				int tmp = arr[end + gap];		// 当前组中  接下来要进行插入 排序 的数

				while (end >= 0)
				{
					if (tmp >= arr[end])
					{
						break;
					}
					else
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
				}
				arr[end + gap] = tmp;
			}
		}
	}
}
