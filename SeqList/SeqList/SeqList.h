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

// ���ݽṹ����������   ��ɾ���

//��ʼ��������
void SLInit(SeqList* ps);
void SLDestroy(SeqList* ps);
// β����βɾ
void SLPushBack(SeqList* ps, SLDataType data);
void SLPopBack(SeqList* ps);
// ͷ����ͷɾ
void SLPushFront(SeqList* ps, SLDataType data);
void SLPushFront(SeqList* ps, SLDataType data);

//�������������   �����ݳ����һ������
void checkCapacity(SeqList* ps);

//��ӡ˳���
void SLPrint(SeqList* ps);