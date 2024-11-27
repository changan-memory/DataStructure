#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define N 10
#define INIT_CAPACITY 4

typedef int SLDataType;	//定义顺序表数据类型

////静态顺序表   开少了不够用   开多了浪费
//typedef struct SeqList {
//	SLDataType arr[N];
//	int size;
//};

//动态顺序表   动态扩容   开辟内存在堆区       没必要用柔性数组
typedef struct SeqList {
	SLDataType* base;	//动态数组的基地址
	int size;		//有效数据个数		size是    最后一个元素的下一个位置的下标
	int capacity;	//空间容量
}SeqList;

// 数据结构管理的需求   增删查改

//初始化与销毁
void SLInit(SeqList* ps);
void SLDestroy(SeqList* ps);
// 尾插与尾删
void SLPushBack(SeqList* ps, SLDataType data);
void SLPopBack(SeqList* ps);
// 头插与头删
void SLPushFront(SeqList* ps, SLDataType data);
void SLPushFront(SeqList* ps, SLDataType data);

//检查容量与扩容   将扩容抽象成一个函数
void checkCapacity(SeqList* ps);

//打印顺序表
void SLPrint(SeqList* ps);