#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//˳����е�Ԫ������
typedef struct {
	int key; //�ؼ�����
	char others;	//������
}ElemType;


//����˳���
typedef struct {
	ElemType* base;	//ElemType* base;
	int length;
}SSTable;//Sequential Search Table
SSTable ST;

int Search_Seq(SSTable ST, int key) {
	for (int i = ST.length; i >= 1; --i) {
		if (key == ST.base[i].key)
			return i;
	}
	return 0;
}

int Search_Seq_1(SSTable ST, int key) {
	int i = 0;
	ST.base[0].key = key;
	for (i = ST.length; ST.base[i].key != key; --i);
	return i;

}

int main() {


	return 0;
}