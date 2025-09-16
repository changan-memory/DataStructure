//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdlib.h>
//#include <stdio.h>
//#include <assert.h>
//typedef struct LNode {
//	int data;
//	struct LNode* next;
//}LNode, *Linklist;
//
////bool InitLinklist(Linklist& L) {
////	L = (LNode*)malloc(sizeof(LNode));
////	assert(L);
////	L->data = 0;
////	L->next = L;
////}
//
//// 我认为初始化链表应该  创建表头，并且返回表头的地址
//
//LNode* creatNode(int data) {
//	LNode* newNode = (LNode*)malloc(sizeof(LNode));
//	assert(newNode);
//	newNode->data - data;
//	newNode->next = NULL;
//	return newNode;
//}
//Linklist InitListHead() {	//循环链表只需要 在初始化时让表头的next指针指向自身
//	Linklist L = (LNode*)malloc(sizeof(LNode));
//	assert(L);
//	L->data = NULL;
//	L->next = NULL;
//	/*L->next = L; */
//	return L;
//}
////头插法插入节点
//void InsertNodeByhead(Linklist& head, int data) {
//	LNode* Node = creatNode(data);
//	Node->next = head->next;
//	head->next = Node;
//	Node->data = data;
//}
//
//void DelNode(Linklist& head, int posNodedata) {
//	LNode* posNode = head->next;
//	LNode* posNodeFront = head;
//	while (posNode->data != posNodedata) {
//		posNodeFront = posNode;
//		posNode = posNode->next;
//	}
//	posNodeFront->next = posNode->next;
//	posNode->next = NULL;
//	free(posNode);
//}
//void printList(Linklist& head) {
//	LNode* pMove = head->next;
//	while (pMove) {
//		printf("%d ", pMove->data);
//		pMove = pMove->next;
//	}
//	printf("\n");
//}
////判断循环单链表是否为空链表
//bool EmptyJudge(Linklist& head) {
//	assert(head);
//	if (head->next == head)
//		return true;
//	return false;	//若表头的next指针指向自己，说明链表后面没有其他结点，表明链表是空的
//}
//
////判断某个节点是否为表尾
//bool isTail(Linklist& head, LNode* p) {
//	if (p->next == head)
//		return true;
//	return false;
//}
//int main() {
//	LNode* head = InitListHead();
//	/*printf("%d\n", EmptyJudge(head));*/
//	InsertNodeByhead(head, 5);
//	InsertNodeByhead(head, 4);
//	InsertNodeByhead(head, 3);
//	InsertNodeByhead(head, 2);
//	InsertNodeByhead(head, 1);
//	printList(head);
//	DelNode(head, 5);
//	printList(head);
//	/*printf("%d\n", EmptyJudge(head));*/
//
//	return 0;
//}