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

//简单选择排序
void SelectSort(SqList& L) {
	int i = 0, j = 0, index = 0;
	for (i = 1; i <= L.length; ++i) {
		index = i;		//设第 i 个元素最小
		for (j = i + 1; j <= L.length; ++j) {		// 从第 i+1 个位置往后 找最小的元素的下标
			if (L.data[j].Keyword < L.data[index].Keyword)
				index = j;
		}
		// 如果找到的下标 与 i 不相等，代表后面的元素里面有更小的 则交换
		if (index != i) {
			RedType temp = L.data[i];
			L.data[i] = L.data[index];
			L.data[index] = temp;
		}
	}
}

//堆排序的筛选算法
// 以 k 为根的子树 调整为 大根堆
void HeapAdjust_max(SqList& L, int k, int length) {
	L.data[0] = L.data[k];		// 先 将根结点 上的元素存起来 
	for (int i = 2 * k; i <= length; i *= 2) {		//	i指向根结点的左子树
		if (i < length && L.data[i].Keyword < L.data[i + 1].Keyword)	//判断左右子树哪个更大
			++i;									// i指向 左右子树中更大的那个
		if (L.data[0].Keyword >= L.data[i].Keyword)		// 判断 根结点和子树中更大的那个  哪个更大
			break;										// 如果根结点更大，那么符合堆排序
		else {		//子节点 比 根结点 大
			L.data[k] = L.data[i];		// 那么 把子节点的值 放在根上
			k = i;					//并且该子节点 称为新的根
		}
	}
	L.data[k] = L.data[0];		//循环结束后，被筛选结点的值放入最终位置
}


// 以 k 为根的子树 调整为 小根堆
void HeapAdjust_min(SqList& L, int k, int length) {
	L.data[0] = L.data[k];		// 先 将根结点 上的元素存起来 
	for (int i = 2 * k; i <= length; i *= 2) {		//	i指向根结点的左子树
		if (i < length && L.data[i + 1].Keyword < L.data[i].Keyword)	//判断左右子树哪个更小
			++i;									// i指向 左右子树中更小的那个
		if (L.data[0].Keyword <= L.data[i].Keyword)		// 判断 根结点和子树中更小的那个  哪个更小
			break;										// 如果根结点更小，那么符合堆排序
		else {		//子节点 比 根结点 小
			L.data[k] = L.data[i];		// 那么 把子节点的值 放在根上
			k = i;					//并且该子节点 称为新的根
		}
	}
	L.data[k] = L.data[0];		//循环结束后，被筛选结点的值放入最终位置
}

void BuildHeap(SqList& L) {
	for (int i = L.length / 2; i >= 1; --i) {		
		HeapAdjust_min(L, i, L.length);		//建立为小根堆
		//HeapAdjust_max(L, i, L.length);		//建立为大根堆
	}
}

void HeapSort(SqList& L) {
	int i = 0;
	//建堆
	for (int i = L.length / 2; i >= 1; --i) {
		//HeapAdjust_min(L, i, L.length);		//建立为小根堆
		HeapAdjust_max(L, i, L.length);		//建立为大根堆
	}
	// 将元素输出指的是 将最大的数和最后一个数交换位置
	for (i = L.length; i > 1; i--) {
		//将最大的数(根结点上的树)和最后一个数交换位置
		RedType temp = L.data[1];
		L.data[1] = L.data[i];
		L.data[i] = temp;
		HeapAdjust_max(L, 1, i-1);
	}
		
}


////数组传参就可以改变 原数据
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