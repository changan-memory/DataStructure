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
// 可以认为希尔排序的 时间复杂度为 O(n^1.3)
void shellSort(int* arr, int size)
{
	int gap = size;
	
	while (gap > 1)
	{
		//gap /= 2;
		gap = gap / 3 + 1;
		
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
		//gap /= 2;
		gap = gap / 3 + 1;

		// 多组 跳跃插入排序   gap 是几，就被分成了几组
		for (int j = 0; j < gap; j++)
		{
			// 从组内的下个数开始进行预插入排序
			for (int i = j + gap; i < size; i += gap)
			{
				// 希尔排序的预排序逻辑
				// 只是将 直接插入排序中的 一步一步跳，改成了一次跳 gap 步
				int tmp = arr[i];			// 当前组中  接下来要进行插入 排序 的数
				int end = i - gap;			// 当前组中  有序部分的 最后一个数的下标

				while (end >= j)			// 当前组中 第一个数的下标
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


void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// 直接选择排序
void SelectSort(int* arr, int size)
{
	// 对第 j 个位置，找出合适的数放在这里
	for (int j = 0; j < size; ++j)
	{
		// 找数的过程，在 [j, size - 1] 区间中找数
		int minIndex = j;	
		for (int i = j + 1; i <= size - 1; ++i)
		{
			if (arr[i] < arr[minIndex])
				minIndex = i;
		}
		// 找到了比 minIndex 更小的数  再交换
		if (minIndex != j)
			Swap(&arr[minIndex], &arr[j]);
	}
}


// 优化版本   遍历一遍可以 同时找出 最小值和最大值
// 最好 O(N^2)
// 最坏 O(N^2)
void selectSort(int* arr, int size)
{
	int left = 0, right = size - 1;

	while (left < right)
	{
		// 找区间 [left, right] 中的最大值和最小值
		int minIndex = left, maxIndex = left;
		for (int i = left + 1; i <= right; ++i)
		{
			if (arr[i] < arr[minIndex])
				minIndex = i;
			if (arr[i] > arr[maxIndex])
				maxIndex = i;
		}
		Swap(&arr[left], &arr[minIndex]);
		if (left == maxIndex)
			maxIndex = minIndex;
		Swap(&arr[right], &arr[maxIndex]);
		++left;
		--right;
	}
}

// 最坏  O(N^2)
// 最好  O(N)
void bubbleSort(int* arr, int size)
{
	for (int j = 0; j < size; ++j)
	{
		// 单趟冒泡排序
		for (int i = 1; i < size - j; ++i)
		{
			if (arr[i - 1] > arr[i])
				Swap(&arr[i - 1], &arr[i]);
		}
	}
}

// 冒泡排序的优化，如果一趟排序中，没有发生一次交换，那么代表已经有序，无需再进行排序
void bubbleSort_1(int* arr, int size)
{
	for (int j = 0; j < size; ++j)
	{
		bool exchange = false;
		// 单趟冒泡排序
		for (int i = 1; i < size - j; ++i)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap(&arr[i - 1], &arr[i]);
				exchange = true;
			}
		}
		// 检查有无发生交换  没有交换，就提前结束
		if (!exchange)
			break;
	}
}


// 闭区间
void quickSort(int* arr, int left, int right)
{
	// 递归结束条件   仅剩一个元素时，就结束,
	// 不能用 left == right 
	// 因为传参时传的是 right = keyi -1 ，可能上次调用后，keyi 为0，传下去 right 就是-1了
	// 而 left 总是为 0

	// 区间中仅有一个元素(left == right)  或 区间不存在(left > right)   时，就结束递归
 	if (left >= right)
		return;
	
	// 左边的值做 key 时，右边要先走  这样可以保证，相遇位置一定比 key 小
	int begin = left, end = right;
	int keyi = left;

	// 因为 
	// 右边先走，右边先在 第一个比 key 小的数 那里停下，就能保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)		
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= arr[keyi])	// 找到右侧第一个比 key 小的数
			--end;

		while (begin < end && arr[begin] <= arr[keyi])	// 找到左侧第一个比 key 大的数
			++begin;

		Swap(&arr[begin], &arr[end]);
		/*--end;
		++begin;*/
	}
	Swap(&arr[keyi], &arr[end]);
	keyi = end;	

	// [begin, keyi - 1]  keyi  [keyi+1, end]  两个区间 递归
	quickSort(arr, left, keyi - 1);
	quickSort(arr, keyi + 1, right);
}
// 快排的性能分析    
// 认为 快排的时间复杂度为 O(N*logN)
// 最好 O(N*logN)	keyi 每次递归 越接近中间，性能越好 即: 数据越乱，快排效率越高
// 最坏 O(N*N)    数据已经有序(已升序或降序)
// 通过以上分析，可以通过  选取合适的 key 来提高快排的性能

void quickSort_1(int* arr, int left, int right)
{
	// 区间中仅有一个元素(left == right)  或 区间不存在(left > right)   时，就结束递归
	if (left >= right)
		return;

	// 左边的值做 key 时，右边要先走  这样可以保证，相遇位置一定比 key 小
	int begin = left, end = right;
	int randi = left + (rand() % (right - left + 1));
	Swap(&arr[left], &arr[randi]);	// 随机的下标，就是随机数做 key

	int keyi = left;

	// 要保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= arr[keyi])	// 找到右侧第一个比 key 小的数
			--end;

		while (begin < end && arr[begin] <= arr[keyi])	// 找到左侧第一个比 key 大的数
			++begin;

		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[keyi], &arr[end]);
	keyi = end;

	// [begin, keyi - 1]  keyi  [keyi+1, end]  两个区间 递归
	quickSort_1(arr, left, keyi - 1);
	quickSort_1(arr, keyi + 1, right);
}

// 优化方案二  left  mid  right  三个数取出不大不小的那个数  作为中间值
int getMidNumi(int* arr, int left, int right)
{
	int mid = (left + right) / 2;

	int a = arr[left];
	int b = arr[mid];
	int c = arr[right];

	// 判断 b 是否是中间值
	if ((a <= b && b <= c) || (c <= b && b <= a))
		return mid;

	// 判断 a 是否是中间值
	if ((b <= a && a <= c) || (c <= a && a <= b))
		return left;

	// 否则 c 为中间值
	return right;
}

void quickSort_2(int* arr, int left, int right)
{
	// 区间中仅有一个元素(left == right)  或 区间不存在(left > right)   时，就结束递归
	if (left >= right)
		return;

	// 优化方案二 三数取中
	int begin = left, end = right;

	int midi = getMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);

	int keyi = left;

	// 要保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= arr[keyi])	// 找到右侧第一个比 key 小的数
			--end;

		while (begin < end && arr[begin] <= arr[keyi])	// 找到左侧第一个比 key 大的数
			++begin;

		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[keyi], &arr[end]);
	keyi = end;

	// [begin, keyi - 1]  keyi  [keyi+1, end]  两个区间 递归
	quickSort_2(arr, left, keyi - 1);
	quickSort_2(arr, keyi + 1, right);
}

// 快排的 挖坑法
// 相遇时一定相遇在 坑的位置，因为，坑要么在左边，要么在右边，相遇时，就在坑的位置
void quickSort_3(int* arr, int left, int right)
{
	// 区间中仅有一个元素(left == right)  或 区间不存在(left > right)   时，就结束递归
	if (left >= right)
		return;

	int begin = left, end = right;

	/*int midi = getMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);*/

	int key = arr[begin];
	int hole = left;

	// 要保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= key)	// 找到右侧第一个比 key 小的数
			--end;

		arr[hole] = arr[end];	// 入坑
		hole = end;				// 更新坑

		while (begin < end && arr[begin] <= key)	// 找到左侧第一个比 key 大的数
			++begin;

		arr[hole] = arr[begin];	// 入坑
		hole = begin;				// 更新坑
	}
	arr[hole] = key;
	// [begin, hole - 1]  hole  [hole+1, end]  两个区间 递归
	quickSort_3(arr, left, hole - 1);
	quickSort_3(arr, hole + 1, right);
}


int partition(int* arr, int left, int right)
{
	// 左边的值做 key 时，右边要先走  这样可以保证，相遇位置一定比 key 小
	int begin = left, end = right;
	int keyi = left;

	// 因为 
	// 右边先走，右边先在 第一个比 key 小的数 那里停下，就能保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= arr[keyi])	// 找到右侧第一个比 key 小的数
			--end;

		while (begin < end && arr[begin] <= arr[keyi])	// 找到左侧第一个比 key 大的数
			++begin;

		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[keyi], &arr[end]);
	keyi = end;

	return keyi;
}

// 快排的性能分析    
// 认为 快排的时间复杂度为 O(N*logN)
// 最好 O(N*logN)	keyi 每次递归 越接近中间，性能越好 即: 数据越乱，快排效率越高
// 最坏 O(N*N)    数据已经有序(已升序或降序)
// 通过以上分析，可以通过  选取合适的 key 来提高快排的性能

int partition_1(int* arr, int left, int right)
{
	// 左边的值做 key 时，右边要先走  这样可以保证，相遇位置一定比 key 小
	int begin = left, end = right;
	int randi = left + (rand() % (right - left + 1));
	Swap(&arr[left], &arr[randi]);	// 随机的下标，就是随机数做 key

	int keyi = left;

	// 要保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= arr[keyi])	// 找到右侧第一个比 key 小的数
			--end;

		while (begin < end && arr[begin] <= arr[keyi])	// 找到左侧第一个比 key 大的数
			++begin;

		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[keyi], &arr[end]);
	keyi = end;

	return keyi;
}

int partition_2(int* arr, int left, int right)
{
	// 优化方案二 三数取中
	int begin = left, end = right;

	int midi = getMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);

	int keyi = left;

	// 要保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= arr[keyi])	// 找到右侧第一个比 key 小的数
			--end;

		while (begin < end && arr[begin] <= arr[keyi])	// 找到左侧第一个比 key 大的数
			++begin;

		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[keyi], &arr[end]);
	keyi = end;

	return keyi;
}

// 快排的 挖坑法
// 相遇时一定相遇在 坑的位置，因为，坑要么在左边，要么在右边，相遇时，就在坑的位置
int partition_3(int* arr, int left, int right)
{
	int begin = left, end = right;

	int midi = getMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);

	int key = arr[begin];
	int hole = left;

	// 要保证 begin 和 end 相遇的值 一定比 key 要小
	while (begin < end)
	{
		// 防止 基准值是 数组中最小的元素 或者  基准值是 数组中最大的元素  时 飘出去
		// 当 arr[keyi] 初始是数组中的最小值时，不加 begin < end 的循环条件，end 会减到 -1,造成越界
		while (begin < end && arr[end] >= key)	// 找到右侧第一个比 key 小的数
			--end;

		arr[hole] = arr[end];	// 入坑
		hole = end;				// 更新坑

		while (begin < end && arr[begin] <= key)	// 找到左侧第一个比 key 大的数
			++begin;

		arr[hole] = arr[begin];	// 入坑
		hole = begin;				// 更新坑
	}
	arr[hole] = key;
	return hole;
}

// 快排的双指针法，数组分区
int partition_4(int* arr, int left, int right)
{
	int midi = getMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);

	int keyi = left;

	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi])
			Swap(&arr[++prev], &arr[cur]);
		
		++cur;
	}
	Swap(&arr[keyi], &arr[prev]);
	keyi = prev;
	return keyi;
}

void qucikSort_partition(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int keyi = partition_4(arr, left, right);
	qucikSort_partition(arr, left, keyi - 1);
	qucikSort_partition(arr, keyi + 1, right);
}



