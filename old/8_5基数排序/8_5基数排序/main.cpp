#include <iostream>
#include <string>
using namespace std;

//������������Ա�һ��������ʵ��
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode, *LinkList;

typedef struct {
	LinkNode* front, *rear;
	int data;
}LinkQueue;

//��������������Ϊ�������֣�ÿһλ������ 0-9
	//�����Ҫ��ʼ�� 10 ������
LinkQueue* LQ[10];	// 0-9 ���� ��λ ʮλ ��λ �ȵȵ�����


//���������� ���ݵ������е����ݵ����֣����뵽��Ӧ����ʽ������

//����������������   ������Ҫɨ�貢���������ȥ
void print(LinkList& L,LinkQueue* LQ) {		//���� L ��һ���б�ͷ�ĵ�����
	LinkNode* pMove = L->next;
	while (pMove != nullptr) {
		int num = pMove->data % 10;
	}
}


int main() {

	

	return 0;
}