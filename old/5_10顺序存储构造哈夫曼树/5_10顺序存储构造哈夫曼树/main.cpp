#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <assert.h>

typedef struct HTNode {
	int weight;	//表示每个结点的权重
	int parent, LChlid, RChild;	//表示双亲和左右孩子  在数组中的下标
}HTNode, *HuffmanTree;

void Select(HuffmanTree HT, int i, int& s1, int& s2) {	// 要遍历 1 到 i (需要包含新建立的结点)
	//int min_1 = 0, min_2 = 0;
	s1 = HT[1].weight;	//存储 最小 和 第二小 的权重
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
// 构造一个结构数组 存放 结点, 数组中的第一个空间不放结点  n个叶子结点，共有 (2n-1) 个结点
// 数组大小定为 2n  刚好可以放下  1--(2n-1)

void creatHuffmanTree(HuffmanTree HT, int n) {
	if (n <= 1)
		return;
	int m = 2 * n - 1;	// 数组中共有 2n-1个结点
	HT = (HTNode*)malloc(sizeof(HTNode) * (m+1));
	assert(HT);	//申请失败则报错
	for (int i = 1; i <= m; i++) {	// 将所有结点的 LChild RChild parent 置为0
		HT[i].LChlid = 0;
		HT[i].RChild = 0;
		HT[i].parent = 0;
	}
	// 输入 各个结点的权重
	for (int i = 1; i <= n; i++)
		std:: cin >> HT[i].weight;
	// 初始化过后 生成哈夫曼树
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