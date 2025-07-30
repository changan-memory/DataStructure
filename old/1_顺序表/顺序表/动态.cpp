#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10//Ĭ����󳤶�
typedef struct {
	int* data;		//ָ��̬���������ָ��
	int MaxSize;	//˳�����������
	int length;		//˳���ĵ�ǰ����
}SeqList;

void InitList(SeqList& L) {
	L.data = (int*)malloc(sizeof(int) * InitSize);	//ָ��̬����Ŀռ�
	L.length = 0;									//δ��������ǰ����ʼ����Ϊ0
	L.MaxSize = InitSize;							//������󳤶�
}

void IncreaseSize(SeqList& L, int len) {	//�����ӵ�˳���   ��Ҫ���ӵĳ���
	int* p = L.data;						//
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));//����һƬ���򿪱��˿ռ�
	for (int i = 0; i < L.length; i++) {//��֮ǰ�ռ��е�����ת��
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;//�ı���󳤶�
	free(p);//�ͷ�֮ǰ�Ŀռ�
}
int GetElem(SeqList& L, int i) {	//����˳����е�i��(�����±�Ϊi-1)Ԫ�ص�ֵ
	if (i > L.length || i <= 0)
		return 1;
	return *(L.data+i-1);
}
int LocateEle(SeqList& L, int ele) {
	for (int i = 0; i < L.length; i++)
		if (ele == L.data[i])
			return i + 1;	//������λ�� i+1
}
//int main() {
//	SeqList L;
//	InitList(L);
//	IncreaseSize(L, 0);
//	return 0;
//}
