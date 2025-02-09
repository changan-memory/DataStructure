//#define _CRT_SECURE_NO_WARNINGS 1
////无头结点
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//typedef struct LNode {
//	int data;
//	struct LNode* next;
//}LNode, *Linklist;
//
//bool InitList(Linklist& L) {
//	L = NULL;
//	return true;
//}
//
//bool InsertList(Linklist& L, int i, int ele) {//按位序插入 位序是从1开始的,带头结点的链表头是第0个结点
//	//在第i个结点插入，相当于让新插入的节点成为第i个结点
//	if (i < 1)
//		return false;
//	if (i == 1) {
//		LNode* newNode_0 = (LNode*)malloc(sizeof(LNode));
//		assert(newNode_0);
//		newNode_0->data = ele;
//		newNode_0->next = L;
//		L = newNode_0;
//		return true;
//	}
//	LNode* p = L; //初始时p指向表头
//	int j = 1;	//j表示当前p指向的是第几个结点
//
//	while (p != NULL && j < i - 1) {  //满足的话继续找下一个节点  需要找到第i-1个结点
//		p = p->next;					//找到了的话，若i = 4, 找到了的话j=3
//		j++;
//	}
//
//	if (p == NULL)		//p指向第j个结点
//		return false;
//	LNode* newNode = (LNode*)malloc(sizeof(LNode));
//	assert(newNode);
//	newNode->next = p->next;
//	newNode->data = ele;
//	p->next = newNode;
//	return true;	//插入成功
//}
//
