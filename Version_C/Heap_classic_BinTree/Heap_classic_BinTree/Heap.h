#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//二叉树的顺序存储，是堆的前身
//在顺序存储的二叉树上加一些限定条件，定义为堆

//堆中某个节点的值总是不大于或不小于其父节点的值
//堆总是一棵    完全二叉树

//小根堆   树中所有父亲都小于或等于孩子
//大根堆   树中所有父亲都大于或等于孩子
//堆可以用来排序，但堆并非是有序的  

//堆的向上调整

//实现大堆
typedef int HeapDataType;
typedef struct HeapNode {
	HeapDataType* base;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* pheap);

void HeapPush(Heap* pheap, HeapDataType data);


