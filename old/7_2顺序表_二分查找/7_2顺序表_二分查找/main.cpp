#include <iostream>
using namespace std;

//˳����е�Ԫ������
typedef struct {
	int keyword; //�ؼ�����
	char others;	//������
}ElemType;

//����˳���
typedef struct {
	ElemType* base;	//ElemType* base;		˳����еĵ�һ��λ�ò����Ԫ��
	int length;		//  length�Ĵ�С  �����ϵ�һ���ռ�(��һ���ռ䲻���Ԫ��)
}SSTable;//Sequential Search Table

int Search_Bin(SSTable& ST, int& keyword) {
	int low = 1, high = ST.length, mid = 0;		//���������ֵ
	while (low <= high) {		//�������� Ϊ high < low
		mid = (low + high) / 2;
		if (ST.base[mid].keyword == keyword)
			return mid;
		else if (ST.base[mid].keyword < keyword)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;	//���� 0 ��ʾ ���в����ڸ�Ԫ��
}

//�ݹ鷨
int Search_Bin_Recur(SSTable& ST, int& keyword, int low, int high) {
	if (low > high)
		return 0;		//���Ҳ���ʱ ���� 0
	int mid = (low + high) / 2;
	if (keyword == ST.base[mid].keyword)
		return mid;
	else if (keyword < ST.base[mid].keyword)
		return Search_Bin_Recur(ST, keyword, low, mid - 1);	//�Ӳ��� return ������
	else
		return Search_Bin_Recur(ST, keyword, mid + 1, high);
}


int main() {
	
	return 0;
}