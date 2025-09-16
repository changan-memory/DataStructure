#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10//默认最大长度
typedef struct {
	int* data;		//指向动态分配数组的指针
	int MaxSize;	//顺序表的最大容量
	int length;		//顺序表的当前长度
}SeqList;

void InitList(SeqList& L) {
	L.data = (int*)malloc(sizeof(int) * InitSize);	//指向动态申请的空间
	L.length = 0;									//未加入数据前，初始长度为0
	L.MaxSize = InitSize;							//设置最大长度
}

void IncreaseSize(SeqList& L, int len) {	//待增加的顺序表   和要增加的长度
	int* p = L.data;						//
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));//再另一片区域开辟了空间
	for (int i = 0; i < L.length; i++) {//把之前空间中的数据转移
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;//改变最大长度
	free(p);//释放之前的空间
}
int GetElem(SeqList& L, int i) {	//查找顺序表中第i个(数组下标为i-1)元素的值
	if (i > L.length || i <= 0)
		return 1;
	return *(L.data+i-1);
}
int LocateEle(SeqList& L, int ele) {
	for (int i = 0; i < L.length; i++)
		if (ele == L.data[i])
			return i + 1;	//返回其位序 i+1
}
//int main() {
//	SeqList L;
//	InitList(L);
//	IncreaseSize(L, 0);
//	return 0;
//}
