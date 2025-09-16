#include <iostream>
#include <string>
using namespace std;

#define MaxSize 20		//���¼������20��
typedef struct {
	int Keyword;	//��ؼ���Ϊ ����
	string otherInfo;		//����������
}RedType;		//record type

typedef struct {
	RedType data[MaxSize+1];	//˳��� data[0]  һ�������ڱ�
	int length;		//˳���ĳ��Ȳ���data[0]
}SqList;

//˳���������
//˳�򷨶�λ����λ��
void InsertSort(SqList& L) {
	int i = 0, j = 0;		
	for (i = 2; i <= L.length; ++i) {	// i Ϊ�������Ԫ�ص��±�
		//�������ı�ǰ���С���Ϳ�ʼ�ƶ���������ִ���κβ���
		if (L.data[i].Keyword < L.data[i-1].Keyword) {

			L.data[0] = L.data[i];	//���������ݱ�ǰһ��С���͸���Ϊ�ڱ�
			for (j = i - 1; L.data[j].Keyword > L.data[0].Keyword; --j) {
				L.data[j + 1] = L.data[j];		//��ǰԪ�رȴ�����Ԫ�ش� �ͺ���
			}
			L.data[j + 1] = L.data[0];
		}
	}
}

//���ַ���λ����λ��
void BInsertSort(SqList& L) {
	int i = 0, j = 0;
	int low = 0, high = 0, mid = 0;
	for (int i = 2; i <= L.length; ++i) {	//�ӵڶ���Ԫ�ؿ�ʼ��
		L.data[0] = L.data[i];		//����Ϊ�ڱ�

		//�������ı�ǰ���С���Ϳ�ʼ���� ���� �ƶ���������ִ���κβ���
		if (L.data[i].Keyword < L.data[i-1].Keyword) {		
			low = 1, high = i - 1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (L.data[0].Keyword < L.data[mid].Keyword)
					high = mid - 1;
				else
					low = mid + 1;
			}	//low �� high ��ȵ�ʱ��Ҳ������ѭ�� ������ high �� low С1
			for (j = i - 1; j >= high + 1; --j)		//�����ƶ�Ԫ��
				L.data[j + 1] = L.data[j];
			L.data[high + 1] = L.data[0];		//������
		}	
	}
}

//ϣ������
//��ͨ��������Ĳ���Ϊ1�� ϣ������Ĳ���Ϊ dk
void ShellInsert(SqList& L, int dk) {
	int i = 0, j = 0;
	for (i = dk + 1; i <= L.length; ++i) {		//�ӵ�һ��ĵڶ���Ԫ�ؿ�ʼ
		if (L.data[i].Keyword < L.data[i - dk].Keyword) {		//�������ı�ǰ���С�������ڱ�
			L.data[0] = L.data[i];

			//�ƶ�Ԫ��
			for (j = i - dk; j > 0 && (L.data[0].Keyword < L.data[j].Keyword); j = j - dk) {
				L.data[j + dk] = L.data[i];
			}
			L.data[j + dk] = L.data[0];		//���ֵ
		}
	}
}


void ShellSort(SqList& L, int dlta[], int t) {	//LΪ����������Ա� dlat[]Ϊ��������  
												//t ΪҪʹ�õ����������е�Ԫ�صĸ���  0-(t-1)
	for (int k = 0; k < t; ++k)					
		ShellInsert(L, dlta[k]);				//һ������Ϊ dlta[k] �Ĳ�������
}

int main() {
	/*RedType r1;
	r1.Keyword = 1;
	r1.otherInfo = "���";
	RedType r2;
	r2 = r1;
	cout << r2.Keyword << " " << r2.otherInfo << endl;*/
	SqList L;
	L.length = 20;
	int j = 20;
	for (int i = 1; i <= L.length; i++) {
		L.data[i].Keyword = j--;
	}
	for (int i = 1; i <= L.length; i++) {
		cout << L.data[i].Keyword << " ";
	}
	cout << endl;
	InsertSort(L);
	//int arr[] = {5, 1};
	//ShellSort(L, arr, 2);
	for (int i = 1; i <= L.length; i++) {
		cout << L.data[i].Keyword << " ";
	}
	return 0;
}