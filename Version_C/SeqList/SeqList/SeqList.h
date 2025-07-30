#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define N 10
#define INIT_CAPACITY 4

typedef int SLDataType;	//����˳�����������

////��̬˳���   �����˲�����   �������˷�
//typedef struct SeqList {
//	SLDataType arr[N];
//	int size;
//};

//��̬˳���   ��̬����   �����ڴ��ڶ���       û��Ҫ����������
typedef struct SeqList {
	SLDataType* base;	//��̬����Ļ���ַ
	int size;		//��Ч���ݸ���		size��    ���һ��Ԫ�ص���һ��λ�õ��±�
	int capacity;	//�ռ�����
}SeqList;

// ���ݽṹ���������   ��ɾ���


void SLInit(SeqList* ps);	//��ʼ��������
void SLDestroy(SeqList* ps);
void checkCapacity(SeqList* ps);	//�������������   �����ݳ����һ������

void SLPushBack(SeqList* ps, SLDataType data);	// β����βɾ
void SLPopBack(SeqList* ps);

void SLPushFront(SeqList* ps, SLDataType data);	// ͷ����ͷɾ
void SLPushFront(SeqList* ps, SLDataType data);

void SLInsert(SeqList* ps, int pos, SLDataType data);	//��ָ��λ��(���������±�)����ɾ��Ԫ��
void SLErase(SeqList* ps, int pos);

int FindSL(SeqList* ps, SLDataType ele);	//����  ������

//��ӡ˳���
void SLPrint(SeqList* ps);