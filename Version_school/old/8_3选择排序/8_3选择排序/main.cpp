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

//��ѡ������
void SelectSort(SqList& L) {
	int i = 0, j = 0, index = 0;
	for (i = 1; i <= L.length; ++i) {
		index = i;		//��� i ��Ԫ����С
		for (j = i + 1; j <= L.length; ++j) {		// �ӵ� i+1 ��λ������ ����С��Ԫ�ص��±�
			if (L.data[j].Keyword < L.data[index].Keyword)
				index = j;
		}
		// ����ҵ����±� �� i ����ȣ���������Ԫ�������и�С�� �򽻻�
		if (index != i) {
			RedType temp = L.data[i];
			L.data[i] = L.data[index];
			L.data[index] = temp;
		}
	}
}

//�������ɸѡ�㷨
// �� k Ϊ�������� ����Ϊ �����
void HeapAdjust_max(SqList& L, int k, int length) {
	L.data[0] = L.data[k];		// �� ������� �ϵ�Ԫ�ش����� 
	for (int i = 2 * k; i <= length; i *= 2) {		//	iָ�������������
		if (i < length && L.data[i].Keyword < L.data[i + 1].Keyword)	//�ж����������ĸ�����
			++i;									// iָ�� ���������и�����Ǹ�
		if (L.data[0].Keyword >= L.data[i].Keyword)		// �ж� �����������и�����Ǹ�  �ĸ�����
			break;										// �������������ô���϶�����
		else {		//�ӽڵ� �� ����� ��
			L.data[k] = L.data[i];		// ��ô ���ӽڵ��ֵ ���ڸ���
			k = i;					//���Ҹ��ӽڵ� ��Ϊ�µĸ�
		}
	}
	L.data[k] = L.data[0];		//ѭ�������󣬱�ɸѡ����ֵ��������λ��
}


// �� k Ϊ�������� ����Ϊ С����
void HeapAdjust_min(SqList& L, int k, int length) {
	L.data[0] = L.data[k];		// �� ������� �ϵ�Ԫ�ش����� 
	for (int i = 2 * k; i <= length; i *= 2) {		//	iָ�������������
		if (i < length && L.data[i + 1].Keyword < L.data[i].Keyword)	//�ж����������ĸ���С
			++i;									// iָ�� ���������и�С���Ǹ�
		if (L.data[0].Keyword <= L.data[i].Keyword)		// �ж� �����������и�С���Ǹ�  �ĸ���С
			break;										// ���������С����ô���϶�����
		else {		//�ӽڵ� �� ����� С
			L.data[k] = L.data[i];		// ��ô ���ӽڵ��ֵ ���ڸ���
			k = i;					//���Ҹ��ӽڵ� ��Ϊ�µĸ�
		}
	}
	L.data[k] = L.data[0];		//ѭ�������󣬱�ɸѡ����ֵ��������λ��
}

void BuildHeap(SqList& L) {
	for (int i = L.length / 2; i >= 1; --i) {		
		HeapAdjust_min(L, i, L.length);		//����ΪС����
		//HeapAdjust_max(L, i, L.length);		//����Ϊ�����
	}
}

void HeapSort(SqList& L) {
	int i = 0;
	//����
	for (int i = L.length / 2; i >= 1; --i) {
		//HeapAdjust_min(L, i, L.length);		//����ΪС����
		HeapAdjust_max(L, i, L.length);		//����Ϊ�����
	}
	// ��Ԫ�����ָ���� �������������һ��������λ��
	for (i = L.length; i > 1; i--) {
		//��������(������ϵ���)�����һ��������λ��
		RedType temp = L.data[1];
		L.data[1] = L.data[i];
		L.data[i] = temp;
		HeapAdjust_max(L, 1, i-1);
	}
		
}


////���鴫�ξͿ��Ըı� ԭ����
//void tsort(int arr[], int size) {
//	int index = 0;
//	for (int i = 1; i <= size; i++) {
//		index = i;
//		for (int j = i + 1; j <= size; j++) {
//			if (arr[j] < arr[index])
//				index = j;
//		}
//		if (index != i) {
//			int temp = arr[i];
//			arr[i] = arr[index];
//			arr[index] = temp;
//		}
//	}
//}


int main() {
	int arr[] = { 0, 9, 8, 7, 2, 4, 3, 7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	//tsort(arr, sz-1);
	cout << endl;
	for (int i = 0; i < sz; i++) {
		cout  << arr[i] << " ";
	}
	return 0;
}