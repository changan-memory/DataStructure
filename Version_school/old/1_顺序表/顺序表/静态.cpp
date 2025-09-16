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
	if (i<1 || i>L.length + 1)//�ж�i�Ƿ���Ч
		return false;
	if (L.length >= MaxSize)//�ж�˳����Ƿ����
		return false;
	for (int j = L.length; j >= i; j--) {//����
		L.data[j] = L.data[j - 1];	//����i��Ԫ�ؼ�֮���Ԫ�غ���
	}
	L.data[i - 1] = ele;	//��λ��i������Ԫ��ele
	L.length++;				//˳����ܳ���+1
	return true;
}
bool ListDelete(Sqlist& L, int i, int& ele) {
	if (i<1 || i>L.length + 1)//�ж�i�Ƿ���Ч
		return false;
	ele = L.data[i - 1];//��ɾ����Ԫ����Ҫ���ظ����ú�������
	for (int j = L.length; j >= i; j--)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}
int GetEle(Sqlist &L, int i) {	//����˳����е�i��(�����±�Ϊi-1)Ԫ�ص�ֵ
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
//	printf("%ld ", stu.id);   ���  123456
//
//	return 0;
//}