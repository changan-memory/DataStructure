#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100

// ���еĽ�㶼��������

// ���ӽ��Ҫ�γ�һ������
typedef struct CTNode {
	int child;		// ��ŵ��Ǻ��ӽ�� �������е��±�
	struct CTNode* next;
}* ChildPtr;

// ˫�׽��Ľ������
typedef struct {
	int data;
	ChildPtr firstchild; //��������ͷָ��    ����ָ���������ָ��
	int parent;  //��˫�׵Ļ����ϸ�������
	//������һ�����ͣ���ʾ��ǰ��� ��  ˫�׽��  �ڽṹ�������е��±�
}CTBox;

// 
typedef struct {
	CTBox nodes[MAXSIZE];
	int pos_root, count_node;	//��¼������λ�� �͵�ǰ�Ѵ洢�Ľ����Ŀ
}CTree;




int main() {



	return 0;
}