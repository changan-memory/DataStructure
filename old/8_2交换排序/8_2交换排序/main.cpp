#include <iostream>
#include <string>
using namespace std;

#define MaxSize 20		//设记录不超过20个
typedef struct {
	int Keyword;	//设关键字为 整形
	string otherInfo;		//其他数据项
}RedType;		//record type

typedef struct {
	RedType data[MaxSize + 1];	//顺序表 data[0]  一般用作哨兵
	int length;		//顺序表的长度
}SqList;

//冒泡排序
void Bubble_Sort(SqList& L) {
	int i = 0, j = 0;
	//int n = L.length;
	RedType temp;
	for (i = 1; i <= L.length - 1; ++i) {	//i表示冒泡排序的趟数   只需要排 (总长度-1) 趟
		for (j = 1; j <= L.length - i; ++j) {		//j表示 元素下标   每趟的比较次数 + 趟数 = 总长度
			if (L.data[j].Keyword > L.data[j + 1].Keyword) {	//不符合顺序就交换
				temp = L.data[j];
				L.data[j] = L.data[j + 1];
				L.data[j + 1] = temp;
			}
		}
	}
}

void Bubble_Sort_V2(SqList& L) {
	int i = 0, j = 0;
	int flag = 1;	//flag 作为是否有交换的标志， 
	//如果在某一趟中未发生交换，代表已经排好序了, 不用再进行剩下的趟数了
	//int n = L.length;
	RedType temp;
	for (i = 1; (i <= L.length - 1) && (flag == 1); ++i) {	//i表示冒泡排序的趟数   只需要排 (总长度-1) 趟
		flag = 0;
		for (j = 1; j <= L.length - i; ++j) {		//j表示 元素下标   每趟的比较次数 + 趟数 = 总长度
			if (L.data[j].Keyword > L.data[j + 1].Keyword) {	//不符合顺序就交换
				temp = L.data[j];
				L.data[j] = L.data[j + 1];
				L.data[j + 1] = temp;
				flag = 1;		//发生交换 flag 置为 1 如果没发生交换，flag 为 0
			}
		}
	}
}

//快速排序
int Partition(SqList& L, int low, int high) {
	L.data[0] = L.data[low];
	int pivotKey = L.data[low].Keyword;

	while (low < high){
		while (low < high && L.data[high].Keyword >= pivotKey)	//在后面  找比中轴小的  放前面
			--high;
		L.data[low] = L.data[high];
		while (low < high && L.data[low].Keyword <= pivotKey)	//在前面  找比中轴大的  放后面
			++low;
		L.data[high] = L.data[low];
	}

	L.data[low] = L.data[0];
	return low;
}

void QSort(SqList& L, int low, int high) {
	int pivot_loc = 0;
	if (low < high) {
		pivot_loc = Partition(L, low, high);	//pivot_loc 为枢轴元素排好序的位置

		//分别对枢轴两边的子表进行排序
		QSort(L, low, pivot_loc - 1);		//对低子表递归排序
		QSort(L, pivot_loc + 1, high);		// 对高子表递归排序
	}

}

int main() {
	SqList L;
	QSort(L, 1, L.length);
	
	return 0;
}


////冒泡排序
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