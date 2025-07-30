#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct HTNode {
	int weight;	//��ʾÿ������Ȩ��
	int parent, LChlid, RChild;	//��ʾ˫�׺����Һ���  �������е��±�
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) {

	HC = new char* [n + 1];		//��� ����������ַ�������
	char* code = new char[n];	//��ʱ���ÿһ���������  �ӵ����ڶ����ռ俪ʼ  ���Ŵ��
	code[n - 1] = '\0';		//���һλ���ó� \0  Ϊ�ַ����ı�־
	int start = 0, f_Node = 0, now_Node = 0;	//������� ��ʼ��
	for (int i = 1; i <= n; i++) {	// �������� ���ݽ��
		start = n - 1;  f_Node = HT[i].parent;  now_Node = i;
		while (f_Node != 0) {			// ֻҪ��ǰ����  ���ڵ� ����  �ͽ���ѭ��
			--start;
			if (now_Node == HT[f_Node].LChlid )		//����ǰ����� ���ڵ����  ����  �� ����
				code[start] = '0';
			else
				code[start] = '1';
			now_Node = f_Node;			//�ٽ��������ң�֪�����ڵ� û�и��ڵ�
			f_Node = HT[f_Node].parent;	// ��Ӧ�ĸ��ڵ��� ���ڵ�ĸ��ڵ�
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &code[start]);
	}
	delete[]code;
}
int main() {
	

	return 0;
}