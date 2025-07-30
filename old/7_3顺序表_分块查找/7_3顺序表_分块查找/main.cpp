#include <iostream>
using namespace std;

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

typedef struct {
	int MaxData;	//���е��������
	int index;		//���е�һ�����ݵ��±�
}TNode;//Table node

typedef struct {
	TNode* Node;
	int length;		//������ĳ���
}IndexTable;

int SearchMax(SSTable& ST, int& n) {		//����ÿһ���� Ԫ�ص����ֵ
	int Max = ST.base[0].key;
	for (int i = 0; i < ST.length / n; ++i) {
		if (ST.base[i].key >= Max)
			Max = ST.base[i].key;
	}
	return Max;

}


void InitIndexTable(SSTable& ST, IndexTable& ITable, int n) {	//n ����ÿһ������ݸ���
	ITable.length = ST.length / n + 1;//������ĳ��� Ϊ ��������/����
	ITable.Node = new TNode[ITable.length];		
	//����������±� �� ���Ԫ�ظ�ֵ
	for (int i = 0; i < ITable.length; ++i) {
		ITable.Node[i].index = 1 + i * n;
		ITable.Node[i].MaxData = SearchMax(ST, n);
	}
}


int main() {

	return 0;
}