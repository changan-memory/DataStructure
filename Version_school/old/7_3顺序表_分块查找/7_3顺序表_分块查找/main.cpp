#include <iostream>
using namespace std;

//顺序表中的元素类型
typedef struct {
	int key; //关键字域
	char others;	//其他域
}ElemType;

//定义顺序表
typedef struct {
	ElemType* base;	//ElemType* base;
	int length;
}SSTable;//Sequential Search Table

typedef struct {
	int MaxData;	//块中的最大数据
	int index;		//块中第一个数据的下标
}TNode;//Table node

typedef struct {
	TNode* Node;
	int length;		//索引表的长度
}IndexTable;

int SearchMax(SSTable& ST, int& n) {		//查找每一块内 元素的最大值
	int Max = ST.base[0].key;
	for (int i = 0; i < ST.length / n; ++i) {
		if (ST.base[i].key >= Max)
			Max = ST.base[i].key;
	}
	return Max;

}


void InitIndexTable(SSTable& ST, IndexTable& ITable, int n) {	//n 代表每一块的数据个数
	ITable.length = ST.length / n + 1;//索引表的长度 为 数据总数/块数
	ITable.Node = new TNode[ITable.length];		
	//给索引表的下标 和 最大元素赋值
	for (int i = 0; i < ITable.length; ++i) {
		ITable.Node[i].index = 1 + i * n;
		ITable.Node[i].MaxData = SearchMax(ST, n);
	}
}


int main() {

	return 0;
}