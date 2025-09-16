#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//��ͷ���
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
bool Empty(Linklist& L) { //���ؽ��Ϊtrue �����ͷ�ǿ�
	return (L != NULL);
}


//bool InsertList(Linklist& L, int i, int ele) {//��λ����� λ���Ǵ�1��ʼ��,��ͷ��������ͷ�ǵ�0�����
//	//�ڵ�i�������룬�൱�����²���Ľڵ��Ϊ��i�����
//	if (i < 1)
//		return false;
//	LNode* p = L; //��ʼʱpָ���ͷ
//	int j = 0;	//j��ʾ��ǰpָ����ǵڼ������
//
//	while (p != NULL && j < i - 1) {  //����Ļ���������һ���ڵ�  ��Ҫ�ҵ���i-1�����
//		p = p->next;					//�ҵ��˵Ļ�����i = 4, �ҵ��˵Ļ�j=3
//		j++;
//	}
//
//	if (p == NULL)		//pָ���j�����
//		return false;
//	LNode* newNode = (LNode*)malloc(sizeof(LNode));
//	assert(newNode);
//	newNode->next = p->next;
//	newNode->data = ele;
//	p->next = newNode;
//	return true;	//����ɹ�
//}

//��ָ���ڵ�֮�����һ��Ԫ��
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
//��ָ�����֮ǰ����ڵ�
bool InsertPriorNode(LNode* p, int data) {	//͵�컻�շ�
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL)
		return false;
	newNode->next = p->next;
	newNode->data = p->data;
	p->next = newNode;
	p->data = data;			//�˷�������Ϊ͵�컻�գ��������󣬴�ʱ��newNode������ԭ����p���
	return false;			//ԭ����p���Ŀռ��д���Ų�����½�������
}
//ɾ���ڵ��Ҫ���ر�ɾ���Ľ���ڴ�ŵ�Ԫ��
//����λ��ɾ��   ɾ����i�����
int Listdelte(Linklist& head, int i) {	//��ɾ���Ľ������������һ����㣬��Ҫ���⿼��
	if (i < 1)
		return false;
	LNode* p = head;
	int j = 0;	//	j��ʾ��ǰָ��ڼ������
	while (j < i - 1 && p!= NULL) {   
		p = p->next;
		j++;
	}
	if (p == NULL)	//iֵ���Ϸ�
		return false;
	if (p->next == NULL)	// ��i-1���ڵ�֮�����������ڵ�
		return false;
	LNode* q = (LNode*)malloc(sizeof(LNode));
	//LNode* q = p->next;
	q = p->next;
	p->next = q->next;
	int e = q->data;
	free(q);
	
}
//��������(��ͷ���)�е� �� i �����  �����ؽ��������Ԫ�ص�ֵ
LNode* GetEle(Linklist& L, int i) {
	if (i < 1)
		return NULL;
	LNode* p = L;		//�Ѳ���ʱ��Ӧ���߼������    
	int j = 0;	//	j��ʾ��ǰָ��ڼ������
	while (j < i && p != NULL) {	//��i-1���i
		p = p->next;
		j++;
	}
	return p;
}
//��ֵ����
LNode* GetEle_ele(Linklist& L, int ele) {
	LNode* p = L->next;
	while (p != NULL && p->data != ele) { // ��������ȱһ���� 
		p = p->next;	//�������ڲ���Ԫ�ز���ȣ����Ҳ�������  ���pָ��NULL, ����������û�����Ԫ��
	}
	return p;
}

//������ĳ���
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
	//���������ð������
	
	return 0;
}

