//#define _CRT_SECURE_NO_WARNINGS 1
////��ͷ���
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
//bool InsertList(Linklist& L, int i, int ele) {//��λ����� λ���Ǵ�1��ʼ��,��ͷ��������ͷ�ǵ�0�����
//	//�ڵ�i�������룬�൱�����²���Ľڵ��Ϊ��i�����
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
//	LNode* p = L; //��ʼʱpָ���ͷ
//	int j = 1;	//j��ʾ��ǰpָ����ǵڼ������
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
//
