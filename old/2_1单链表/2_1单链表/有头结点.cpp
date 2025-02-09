#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//带头结点
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *Linklist;
bool InitList(Linklist& L, int data) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->data = data;
	L->next = NULL;
	return true;
}
bool Empty(Linklist& L) { //返回结果为true 代表表头非空
	return (L != NULL);
}


//bool InsertList(Linklist& L, int i, int ele) {//按位序插入 位序是从1开始的,带头结点的链表头是第0个结点
//	//在第i个结点插入，相当于让新插入的节点成为第i个结点
//	if (i < 1)
//		return false;
//	LNode* p = L; //初始时p指向表头
//	int j = 0;	//j表示当前p指向的是第几个结点
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

//在指定节点之后插入一个元素
bool InsertNode(LNode* p, int data) {
	if (p == NULL)
		return false;
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL)
		return false;
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	return true;
}
//在指定结点之前插入节点
bool InsertPriorNode(LNode* p, int data) {	//偷天换日法
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL)
		return false;
	newNode->next = p->next;
	newNode->data = p->data;
	p->next = newNode;
	p->data = data;			//此番操作名为偷天换日，操作过后，此时的newNode结点就是原来的p结点
	return false;			//原来的p结点的空间中存放着插入的新结点的数据
}
//删除节点后要返回被删除的结点内存放的元素
//按照位序删除   删除第i个结点
int Listdelte(Linklist& head, int i) {	//若删除的结点是链表的最后一个结点，需要额外考虑
	if (i < 1)
		return false;
	LNode* p = head;
	int j = 0;	//	j表示当前指向第几个结点
	while (j < i - 1 && p!= NULL) {   
		p = p->next;
		j++;
	}
	if (p == NULL)	//i值不合法
		return false;
	if (p->next == NULL)	// 第i-1个节点之后已无其他节点
		return false;
	LNode* q = (LNode*)malloc(sizeof(LNode));
	//LNode* q = p->next;
	q = p->next;
	p->next = q->next;
	int e = q->data;
	free(q);
	
}
//查找链表(有头结点)中的 第 i 个结点  并返回结点中数据元素的值
LNode* GetEle(Linklist& L, int i) {
	if (i < 1)
		return NULL;
	LNode* p = L;		//把插入时对应的逻辑搬过来    
	int j = 0;	//	j表示当前指向第几个结点
	while (j < i && p != NULL) {	//把i-1变成i
		p = p->next;
		j++;
	}
	return p;
}
//按值查找
LNode* GetEle_ele(Linklist& L, int ele) {
	LNode* p = L->next;
	while (p != NULL && p->data != ele) { // 两个条件缺一不可 
		p = p->next;	//在链表内部，元素不相等，查找不到不到  如果p指向NULL, 代表链表中没有相关元素
	}
	return p;
}

//求链表的长度
int GetListLen(Linklist& L) {
	if (L == NULL)
		return 0;
	LNode* p = L;
	int i = 0;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
void printlist(Linklist& head) {
	LNode* pMove = head->next;
	while (pMove != NULL) {
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
int main() {

	Linklist head;
	InitList(head, NULL);
	InsertNode(head, 5);
	InsertNode(head, 4);
	InsertNode(head, 3);
	InsertNode(head, 2);
	InsertNode(head, 1);
	printlist(head);
	//对链表进行冒泡排序
	
	return 0;
}

