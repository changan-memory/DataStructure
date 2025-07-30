#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//��������˳��洢���Ƕѵ�ǰ��
//��˳��洢�Ķ������ϼ�һЩ�޶�����������Ϊ��
//
//����ĳ���ڵ��ֵ���ǲ����ڻ�С���丸�ڵ��ֵ
//������һ��    ��ȫ������
//
//С����   �������и��׶�С�ڻ���ں���
//�����   �������и��׶����ڻ���ں���
//�ѿ����������򣬵��Ѳ����������  ,���ѵĹ���ʵ�ʾ�������Ĺ���

//�ѵ����ϵ���

//ʵ�ִ��   ������ʵ�ִ����Ϊ����
typedef int HeapDataType;
typedef struct HeapNode {
	HeapDataType* base;
	int size;
	int capacity;
}Heap;


//�������е�Ԫ��
void Swap(HeapDataType* child, HeapDataType* parent);
//�ѵ����� ���µ���
void AdjustUp(HeapDataType* arr, int child);
void AdjustDown(HeapDataType* arr, int size, int parent);

//�ѳ�ʼ��������
void HeapInit(Heap* pheap);
void HeapDestroy(Heap* pheap);

//�Ѳ����ɾ��
void HeapPush(Heap* pheap, HeapDataType data);
void HeapPop(Heap* pheap);

//��ȡ�Ѷ�Ԫ��
HeapDataType HeapTop(Heap* pheap);
//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(Heap* pheap);
//��ȡ�ѵ�size
int HeapSize(Heap* pheap);
