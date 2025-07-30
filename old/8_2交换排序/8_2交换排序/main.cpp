#include <iostream>
#include <string>
using namespace std;

#define MaxSize 20		//���¼������20��
typedef struct {
	int Keyword;	//��ؼ���Ϊ ����
	string otherInfo;		//����������
}RedType;		//record type

typedef struct {
	RedType data[MaxSize + 1];	//˳��� data[0]  һ�������ڱ�
	int length;		//˳���ĳ���
}SqList;

//ð������
void Bubble_Sort(SqList& L) {
	int i = 0, j = 0;
	//int n = L.length;
	RedType temp;
	for (i = 1; i <= L.length - 1; ++i) {	//i��ʾð�����������   ֻ��Ҫ�� (�ܳ���-1) ��
		for (j = 1; j <= L.length - i; ++j) {		//j��ʾ Ԫ���±�   ÿ�˵ıȽϴ��� + ���� = �ܳ���
			if (L.data[j].Keyword > L.data[j + 1].Keyword) {	//������˳��ͽ���
				temp = L.data[j];
				L.data[j] = L.data[j + 1];
				L.data[j + 1] = temp;
			}
		}
	}
}

void Bubble_Sort_V2(SqList& L) {
	int i = 0, j = 0;
	int flag = 1;	//flag ��Ϊ�Ƿ��н����ı�־�� 
	//�����ĳһ����δ���������������Ѿ��ź�����, �����ٽ���ʣ�µ�������
	//int n = L.length;
	RedType temp;
	for (i = 1; (i <= L.length - 1) && (flag == 1); ++i) {	//i��ʾð�����������   ֻ��Ҫ�� (�ܳ���-1) ��
		flag = 0;
		for (j = 1; j <= L.length - i; ++j) {		//j��ʾ Ԫ���±�   ÿ�˵ıȽϴ��� + ���� = �ܳ���
			if (L.data[j].Keyword > L.data[j + 1].Keyword) {	//������˳��ͽ���
				temp = L.data[j];
				L.data[j] = L.data[j + 1];
				L.data[j + 1] = temp;
				flag = 1;		//�������� flag ��Ϊ 1 ���û����������flag Ϊ 0
			}
		}
	}
}

//��������
int Partition(SqList& L, int low, int high) {
	L.data[0] = L.data[low];
	int pivotKey = L.data[low].Keyword;

	while (low < high){
		while (low < high && L.data[high].Keyword >= pivotKey)	//�ں���  �ұ�����С��  ��ǰ��
			--high;
		L.data[low] = L.data[high];
		while (low < high && L.data[low].Keyword <= pivotKey)	//��ǰ��  �ұ�������  �ź���
			++low;
		L.data[high] = L.data[low];
	}

	L.data[low] = L.data[0];
	return low;
}

void QSort(SqList& L, int low, int high) {
	int pivot_loc = 0;
	if (low < high) {
		pivot_loc = Partition(L, low, high);	//pivot_loc Ϊ����Ԫ���ź����λ��

		//�ֱ���������ߵ��ӱ��������
		QSort(L, low, pivot_loc - 1);		//�Ե��ӱ�ݹ�����
		QSort(L, pivot_loc + 1, high);		// �Ը��ӱ�ݹ�����
	}

}

int main() {
	SqList L;
	QSort(L, 1, L.length);
	
	return 0;
}


////ð������
//void Bubble_Sort_test(SqList& L) {
//	int i = 0, j = 0;
//	//int n = L.length;
//	RedType temp;
//	for (i = 1; i <= L.length - 1; ++i) 
//	{	
//		for (j = 1; j <= L.length - i; ++j) 
//		{		
//			if (L.data[j].Keyword > L.data[j + 1].Keyword) 
//			{	
//				temp = L.data[j];
//				L.data[j] = L.data[j + 1];
//				L.data[j + 1] = temp;
//			}
//		}
//	}
//}