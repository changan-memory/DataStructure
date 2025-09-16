#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <assert.h>

typedef struct HTNode {
	int weight;	//��ʾÿ������Ȩ��
	int parent, LChlid, RChild;	//��ʾ˫�׺����Һ���  �������е��±�
}HTNode, *HuffmanTree;

void Select(HuffmanTree HT, int i, int& s1, int& s2) {	// Ҫ���� 1 �� i (��Ҫ�����½����Ľ��)
	//int min_1 = 0, min_2 = 0;
	s1 = HT[1].weight;	//�洢 ��С �� �ڶ�С ��Ȩ��
	s2 = HT[2].weight;
	for (int j = 1; j <= i; j++) {
		if (HT[j].weight <= s1 && HT[j].parent == 0) {
			s2 = s1;
			s1 = HT[j].weight;
		}
		else if (HT[j].weight < s2 && HT[j].parent == 0)
			s2 = HT[i].weight;
	}
	
}
// ����һ���ṹ���� ��� ���, �����еĵ�һ���ռ䲻�Ž��  n��Ҷ�ӽ�㣬���� (2n-1) �����
// �����С��Ϊ 2n  �պÿ��Է���  1--(2n-1)

void creatHuffmanTree(HuffmanTree HT, int n) {
	if (n <= 1)
		return;
	int m = 2 * n - 1;	// �����й��� 2n-1�����
	HT = (HTNode*)malloc(sizeof(HTNode) * (m+1));
	assert(HT);	//����ʧ���򱨴�
	for (int i = 1; i <= m; i++) {	// �����н��� LChild RChild parent ��Ϊ0
		HT[i].LChlid = 0;
		HT[i].RChild = 0;
		HT[i].parent = 0;
	}
	// ���� ��������Ȩ��
	for (int i = 1; i <= n; i++)
		std:: cin >> HT[i].weight;
	// ��ʼ������ ���ɹ�������
	int s1 = 0, s2 = 0;
	for (int i = n + 1; i <= m; i++) {
		Select(HT, i-1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].LChlid = s1;
		HT[i].RChild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

int main() {
	HuffmanTree HT = NULL;
	creatHuffmanTree(HT, 8);




	return 0;
}