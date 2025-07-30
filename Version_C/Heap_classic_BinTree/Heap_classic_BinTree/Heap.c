#include "Heap.h"

//堆初始化
void HeapInit(Heap* pheap) {
	assert(pheap);	
	pheap->base = (HeapDataType*)malloc(sizeof(HeapDataType) * 4);
	if (pheap->base == NULL) {
		perror("malloc failed\n");
		return;
	}
	pheap->size = 0;
	pheap->capacity = 4;
}

void HeapDestroy(Heap* pheap) {
	assert(pheap);

	free(pheap->base);
	pheap->base = NULL;
	pheap->capacity = pheap->size = 0;
}

void Swap(HeapDataType* child, HeapDataType* parent) {
	HeapDataType temp = *child;
	*child = *parent;
	*parent = temp;
}

// 插入，不能指定位置插入。
// 因为新元素插入后要进行调整使其满足堆的结构，指定的位置不一定是最终调整后的位置
void HeapPush(Heap* pheap, HeapDataType data) {
	assert(pheap);	//空堆也可以push，但需保证结构体存在

	//插入检查是否需要扩容
	if (pheap->size == pheap->capacity) {
		HeapDataType* newSpace = (HeapDataType*)realloc(pheap->base, sizeof(HeapDataType) * pheap->capacity * 2);
		if (newSpace == NULL) {
			perror("realloc failed\n");
			return;
		}
		pheap->base = newSpace;
		pheap->capacity *= 2;
	}
	pheap->base[pheap->size] = data;
	pheap->size++;

	//插入后需向上调整，保证插入后满足堆的特性
	AdjustUp(pheap->base, pheap->size - 1);	//size++ 后，size-1 是新插入元素的下标
}

//堆的删除   要删除堆顶的数，删除堆尾的数据没有意义，删除最大的或最小的，可以选出第二大或第二小的
//挪动删除(直接删)的缺点  1. 效率低下O(n)   2.  堆的父子关系全乱了
// 删堆顶的元素，将第一个元素和最后一个元素交换(最大限度的保持了原有的关系)，再向下调整维持堆的大小关系
void HeapPop(Heap* pheap) {
	assert(pheap && pheap->size > 0);
	assert(!HeapEmpty(pheap));
	//删除堆顶元素   交换堆顶元素 和 堆尾元素
	Swap(&pheap->base[0], &pheap->base[pheap->size - 1]);
	pheap->size--;		//删除数据，让size-1   size--之后，可能会为0

	// 仅当堆非空时进行向下调整
	if (pheap->size > 0) {
		AdjustDown(pheap->base, pheap->size, 0);
	}
}

// 插入数据向上调整， 删除数据向下调整
//向上调整 或向下调整的条件是，左右子树 必须是大堆 或者 小堆
void AdjustUp(HeapDataType* arr, int child) {
	assert(arr);
	int parent = (child - 1) / 2;
	//while (parent >= 0) {		//	 个人建议while的循环条件内不要写太复杂的条件
	//写成  child > 0  会更好  因为 最坏时 child 为 0 ，此时parent = (child-1)/2  也为0
	//因此 实际上 parent 不会为 <= 0
	while (child > 0) {   // child 等于 0 或小于 0 时就不用再调整了
		if (arr[child] > arr[parent]) {		// arr[child] > arr[parent] 建的是大堆
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else		//child <= parent 时
			break;
	}
}

// 向下向上调整时间复杂度为 logN
// 向下调整 到叶子结点结束，叶子结点的左孩子 的下标  大于 size   size是数组的大小
void AdjustDown(HeapDataType* arr, int size, int parent) {
	assert(arr);
	assert(parent >= 0 && parent < size);	//parent非负 且 不能越界
	int child = parent * 2 + 1;
	while (child < size) {
		//检查 child+1 是否越界 以及 找出 左右孩子中更大的那个
		if (child + 1 < size && arr[child + 1] > arr[child])
			++child;

		if (arr[child] > arr[parent]) {
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

// 向上调整建堆
void creatHeapUp(HeapDataType* arr, int size) {
	for (int i = 1; i < size; ++i)
		AdjustUp(arr, i);
}
// 向下调整建堆
void creatHeapDown(HeapDataType* arr, int size) {
	// 不能从 0 开始向下调整建堆，选择从 最后一个叶子结点的父亲(最后一个非叶子结点) 开始调整
	// 向下调整的条件是，左右子树都是大堆，从下开始往上调，可以保证调到0的时候左右子树都是大堆
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
		AdjustDown(arr, size, i);
}

//获取堆顶元素
HeapDataType HeapTop(Heap* pheap) {
	assert(pheap);
	assert(pheap->base);
	return pheap->base[0];
}
//判断堆是否为空
bool HeapEmpty(Heap* pheap) {
	assert(pheap);
	return pheap->size == 0;
}
//获取堆的size
int HeapSize(Heap* pheap) {
	assert(pheap);
	return pheap->size;
}

