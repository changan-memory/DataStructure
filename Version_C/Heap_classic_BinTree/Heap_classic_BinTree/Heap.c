#include "Heap.h"

//�ѳ�ʼ��
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

// ���룬����ָ��λ�ò��롣
// ��Ϊ��Ԫ�ز����Ҫ���е���ʹ������ѵĽṹ��ָ����λ�ò�һ�������յ������λ��
void HeapPush(Heap* pheap, HeapDataType data) {
	assert(pheap);	//�ն�Ҳ����push�����豣֤�ṹ�����

	//�������Ƿ���Ҫ����
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

	//����������ϵ�������֤���������ѵ�����
	AdjustUp(pheap->base, pheap->size - 1);	//size++ ��size-1 ���²���Ԫ�ص��±�
}

//�ѵ�ɾ��   Ҫɾ���Ѷ�������ɾ����β������û�����壬ɾ�����Ļ���С�ģ�����ѡ���ڶ����ڶ�С��
//Ų��ɾ��(ֱ��ɾ)��ȱ��  1. Ч�ʵ���O(n)   2.  �ѵĸ��ӹ�ϵȫ����
// ɾ�Ѷ���Ԫ�أ�����һ��Ԫ�غ����һ��Ԫ�ؽ���(����޶ȵı�����ԭ�еĹ�ϵ)�������µ���ά�ֶѵĴ�С��ϵ
void HeapPop(Heap* pheap) {
	assert(pheap && pheap->size > 0);
	assert(!HeapEmpty(pheap));
	//ɾ���Ѷ�Ԫ��   �����Ѷ�Ԫ�� �� ��βԪ��
	Swap(&pheap->base[0], &pheap->base[pheap->size - 1]);
	pheap->size--;		//ɾ�����ݣ���size-1   size--֮�󣬿��ܻ�Ϊ0

	// �����ѷǿ�ʱ�������µ���
	if (pheap->size > 0) {
		AdjustDown(pheap->base, pheap->size, 0);
	}
}

// �����������ϵ����� ɾ���������µ���
//���ϵ��� �����µ����������ǣ��������� �����Ǵ�� ���� С��
void AdjustUp(HeapDataType* arr, int child) {
	assert(arr);
	int parent = (child - 1) / 2;
	//while (parent >= 0) {		//	 ���˽���while��ѭ�������ڲ�Ҫд̫���ӵ�����
	//д��  child > 0  �����  ��Ϊ �ʱ child Ϊ 0 ����ʱparent = (child-1)/2  ҲΪ0
	//��� ʵ���� parent ����Ϊ <= 0
	while (child > 0) {   // child ���� 0 ��С�� 0 ʱ�Ͳ����ٵ�����
		if (arr[child] > arr[parent]) {		// arr[child] > arr[parent] �����Ǵ��
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else		//child <= parent ʱ
			break;
	}
}

// �������ϵ���ʱ�临�Ӷ�Ϊ logN
// ���µ��� ��Ҷ�ӽ�������Ҷ�ӽ������� ���±�  ���� size   size������Ĵ�С
void AdjustDown(HeapDataType* arr, int size, int parent) {
	assert(arr);
	assert(parent >= 0 && parent < size);	//parent�Ǹ� �� ����Խ��
	int child = parent * 2 + 1;
	while (child < size) {
		//��� child+1 �Ƿ�Խ�� �Լ� �ҳ� ���Һ����и�����Ǹ�
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

// ���ϵ�������
void creatHeapUp(HeapDataType* arr, int size) {
	for (int i = 1; i < size; ++i)
		AdjustUp(arr, i);
}
// ���µ�������
void creatHeapDown(HeapDataType* arr, int size) {
	// ���ܴ� 0 ��ʼ���µ������ѣ�ѡ��� ���һ��Ҷ�ӽ��ĸ���(���һ����Ҷ�ӽ��) ��ʼ����
	// ���µ����������ǣ������������Ǵ�ѣ����¿�ʼ���ϵ������Ա�֤����0��ʱ�������������Ǵ��
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
		AdjustDown(arr, size, i);
}

//��ȡ�Ѷ�Ԫ��
HeapDataType HeapTop(Heap* pheap) {
	assert(pheap);
	assert(pheap->base);
	return pheap->base[0];
}
//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(Heap* pheap) {
	assert(pheap);
	return pheap->size == 0;
}
//��ȡ�ѵ�size
int HeapSize(Heap* pheap) {
	assert(pheap);
	return pheap->size;
}

