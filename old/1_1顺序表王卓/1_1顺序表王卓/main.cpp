#define _CRT_SECURE_NO_WARNINGS 1
// #define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
// 动态的话用动态内存管理
// 静态的话用 数组 加 宏定义

// 静态的
// typedef struct SeqList {
//	int arr[MAXSIZE]; //表示顺序表的空间的起始位置    前面的数据类型一般都是结构体类型
//	int length;		//表示顺序表的当前长度
// }SeqList;

typedef struct SeqList
{
	int *init;	// 表示顺序表的空间的起始位置    前面的数据类型一般都是结构体类型
	int length; // 表示顺序表的当前长度
	int MaxSize;
} SeqList;
SeqList L;

// 动态分配   初始化线性表
void InitSqlist(SeqList &L)
{
	L.init = (int *)malloc(sizeof(int) * L.MaxSize);
	assert(L.init); // 防止空间分配失败
	L.length = 0;
	L.MaxSize = 4;
}
// 销毁线性表
void DestroySqList(SeqList &L)
{
	if (L.init)
		free(L.init);
}
// 清空线性表
void ClaerSqList(SeqList &L)
{
	L.length = 0;
}
// 求线性表长度
int GetLength(SeqList &L)
{
	return L.length;
}
// 判断是否非空
bool EmptyJudge(SeqList &L)
{
	if (L.length)
		return false;
	return true;
}
// 获取线性表中 第i个元素   函数直接返回第 i 个元素
int Getele(SeqList &L, int i)
{
	if (i < 1 || i > L.length)
		return -1;
	return L.init[i - 1];
}
// 按值查找 线性表中的元素   判断表中有无对应元素  同时返回该元素 是表中的第几个元素
int GetEle(SeqList &L, int ele)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.init[i] == ele)
			return i + 1;
	}
	return 0;
}
// 动态给顺序表扩容
void IncreaseLen(SeqList &L, int len)
{
	int *p = L.init;
	L.init = (int *)malloc(sizeof(int) * (len + L.MaxSize));
	assert(L.init);
	// 转移元素
	for (int i = 0; i < L.length; i++)
	{
		L.init[i] = p[i];
	}
	p = NULL;
	free(p);
	L.MaxSize = L.MaxSize + len;
}
void Insertele_1(SeqList &L, int i, int ele)
{												// 将第i个及其后面的元素后移 j从最后一个元素(下标为length-1)开始
	for (int j = L.length - 1; j >= i - 1; j--) // 需要移动的最后一个元素的下标为(i-1)
		L.init[j + 1] = L.init[j];
	L.init[i - 1] = ele; // 第i个元素的数组下标为 i-1
	L.length++;
}
// 在顺序表的 第 i 个位置上插入一个元素
bool Insertele_2(SeqList &L, int i, int ele)
{
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.length == L.MaxSize)
	{
		IncreaseLen(L, 1);
		Insertele_1(L, i, ele);
		return true;
	}
	Insertele_1(L, i, ele);
	return true;
}
// 删除顺序表上第 i 个元素   并返回
bool Delele(SeqList &L, int i, int &ele)
{
	if (i < 1 || i > L.length)
		return false;
	ele = L.init[i - 1];
	for (int j = i - 1; j <= L.length - 1; j++)
	{
		L.init[j] = L.init[j + 1];
	}
	L.length--;
}

// 遍历顺序表
void printSqlist(SeqList &L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.init[i]);
	}
	printf("\n");
}
int main()
{
	InitSqlist(L);
	for (int i = 0; i < 5; i++)
	{
		Insertele_2(L, i + 1, i);
	}
	printSqlist(L);
	int x = 0;
	Delele(L, 5, x);
	printSqlist(L);

	return 0;
}