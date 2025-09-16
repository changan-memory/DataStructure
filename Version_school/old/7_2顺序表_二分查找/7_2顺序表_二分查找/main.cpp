#include <iostream>
using namespace std;

//顺序表中的元素类型
typedef struct {
	int keyword; //关键字域
	char others;	//其他域
}ElemType;

//定义顺序表
typedef struct {
	ElemType* base;	//ElemType* base;		顺序表中的第一个位置不存放元素
	int length;		//  length的大小  不算上第一个空间(第一个空间不存放元素)
}SSTable;//Sequential Search Table

int Search_Bin(SSTable& ST, int& keyword) {
	int low = 1, high = ST.length, mid = 0;		//放置区间初值
	while (low <= high) {		//结束条件 为 high < low
		mid = (low + high) / 2;
		if (ST.base[mid].keyword == keyword)
			return mid;
		else if (ST.base[mid].keyword < keyword)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;	//返回 0 表示 表中不存在该元素
}

//递归法
int Search_Bin_Recur(SSTable& ST, int& keyword, int low, int high) {
	if (low > high)
		return 0;		//查找不到时 返回 0
	int mid = (low + high) / 2;
	if (keyword == ST.base[mid].keyword)
		return mid;
	else if (keyword < ST.base[mid].keyword)
		return Search_Bin_Recur(ST, keyword, low, mid - 1);	//加不加 return 都可以
	else
		return Search_Bin_Recur(ST, keyword, mid + 1, high);
}


int main() {
	
	return 0;
}