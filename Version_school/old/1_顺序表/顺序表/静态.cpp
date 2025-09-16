#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10
#include <stdio.h>
typedef struct {
	int data[MaxSize];
	int length;
}Sqlist;
void Initlist(Sqlist& L) {
	L.length = 0;
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;
	}
}
bool ListInsert(Sqlist& L, int i, int ele) {
	if (i<1 || i>L.length + 1)//判断i是否有效
		return false;
	if (L.length >= MaxSize)//判断顺序表是否存满
		return false;
	for (int j = L.length; j >= i; j--) {//插入
		L.data[j] = L.data[j - 1];	//将第i个元素及之后的元素后移
	}
	L.data[i - 1] = ele;	//在位置i出放入元素ele
	L.length++;				//顺序表总长度+1
	return true;
}
bool ListDelete(Sqlist& L, int i, int& ele) {
	if (i<1 || i>L.length + 1)//判断i是否有效
		return false;
	ele = L.data[i - 1];//被删除的元素需要返回给调用函数的人
	for (int j = L.length; j >= i; j--)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}
int GetEle(Sqlist &L, int i) {	//查找顺序表中第i个(数组下标为i-1)元素的值
	if (i > L.length || i <= 0)
		return 1;
	return L.data[i - 1];
}


//struct Stu {
//	long id;
//	char name[20];
//};
//Stu stu;
//void test(Stu& s) {
//	s.id = 123456;
//}
//int main() {
//
//	test(stu);
//	printf("%ld ", stu.id);   结果  123456
//
//	return 0;
//}