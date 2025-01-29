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

void Swap(HeapDataType* child, HeapDataType* parent) {
	HeapDataType* temp = *child;
	*child = *parent;
	*parent = temp;
}
//向上调整
void AdjustUp(HeapDataType* arr, int child) {
	assert(arr);
	int parent = (child - 1) / 2;

	while (parent >= 0) {
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

		pheap->base[pheap->size] = data;
		pheap->size++;
		pheap->capacity *= 2;

		//插入需要向上调整
		AdjustUp(pheap->base, pheap->size - 1);	//size++ 后，size-1 是新插入元素的位置
	}


}
