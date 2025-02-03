#include "Heap.h"

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
//向上调整 或向下调整的条件是，左右子树 必须是大堆 或者 小堆
void AdjustUp(HeapDataType* arr, int child) {
	assert(arr);
	int parent = (child - 1) / 2;
	//while (parent >= 0) {	//个人建议while的循环条件内不要写太复杂的条件
	//写成  child > 0  会更好
	while(child > 0){
		if (arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void HeapPush(Heap* pheap, HeapDataType data) {
	assert(pheap);	//空堆也可以push，但需要保证结构体存在

	//插入，检查是否需要扩容
	if (pheap->size == pheap->capacity) {
		HeapDataType* newSpace = (HeapDataType*)realloc(pheap->base, sizeof(HeapDataType) * pheap->capacity * 2);
		if (newSpace == NULL) {
			perror("realloc fialed\n");
			return;
		}

		pheap->base = newSpace;
		pheap->capacity *= 2;
	}
	pheap->base[pheap->size] = data;
	pheap->size++;

	//插入需要向上调整
	AdjustUp(pheap->base, pheap->size - 1);	//size++ 后，size-1 是新插入元素的位置
}
//向下向上调整时间复杂度为logN
void AdjustDown(HeapDataType* arr, int size, int parent) {
	assert(arr);
	assert(parent >= 0 && parent < size);
	int child = parent * 2 + 1;
	while (child < size) {
		//检查是否越界 以及 找到左右孩子中更大的那个
		if (child + 1 < size && arr[child + 1] > arr[child]) {
			++child;
		}
		if (arr[child] > arr[parent]) {
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else {
			break;
		}
	}
}
//堆的删除
//挪动删除的缺点  1. 效率地下   2.  堆的父子关系全乱了
// 删堆顶的元素， 将第一个元素和最后一个元素交换(最大限度的保持了原有的关系)，再向下调整维持堆
void HeapPop(Heap* pheap) {
	assert(pheap && pheap->size);
	//删除堆顶元素
	Swap(&pheap->base[0], &pheap->base[pheap->size - 1]);
	pheap->size--;

	//向下调整
	AdjustDown(pheap->base, pheap->size, 0);
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

