#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


//// 建立了 下标和人名索引的并查集
//template<class T>
//class UnionFindSet
//{
//public:
//	// 给了一个包含人名的数组，把他存入一个 vector 中即可，可以通过编号找人
//	UnionFindSet(const T* arr, size_t size)
//	{
//		for (size_t i = 0; i < size; ++i)
//		{
//			_arr.push_back(arr[i]);
//			_indexMap[arr[i]] = i;
//		}
//	}
//private:
//	vector<T> _arr;				// 用编号找人
//	map<T, int> _indexMap;		// 用人找编号
//};


// 这里没有人名，假设给出的都是数字
// 并查集  逻辑结构是一个森林
class UnionFindSet
{
public:
	// 用 n 个数字构造并查集, 0-n 为下标， vector 中存数字
	// 存负数: 代表当前 下标所代表的元素 为根
	// 存 >=0 的数: 该数为 当前元素的父节点的 下标
	UnionFindSet(size_t n)
		:_ufs(n, -1)	// 
	{}

	// 提供如下成员函数
	
	void Union(int index1, int index2)	// 将两个成员合并成一个集合
	{
		int root1 = FindRoot(index1);
		int root2 = FindRoot(index2);

		if (root1 == root2)		// 两元素的根相同，即本身就在同一个集合，则不合并
			return;

		// 将元素合并到小集合    _ufs[root] 越小（越负），集合越大
		if (_ufs[root1] > _ufs[root2])
			std::swap(root1, root2);

		// 合并的逻辑
		_ufs[root1] += _ufs[root2];		// 
		_ufs[root2] = root1;
	}

	// 可以在边找的过程中，加一个压缩路径的过程
	int FindRoot(int index)	const	// 找当前元素的根结点的下标
	{
		int parent = index;		// 刚开始，每个元素都是一个独立的的根
		// 找根小于0的位置
		while (_ufs[parent] >= 0)
		{
			parent = _ufs[parent];
		}

		return parent;
	}

	bool IsInSet(int index1, int index2) const	// 判断两个元素是否在同一个集合
	{
		int root1 = FindRoot(index1);
		int root2 = FindRoot(index2);
		return root1 == root2;		// 两个元素有相同的根，则在同一个集合
	}

	// 数组中有几个值是负数，就有几个集合
	size_t SetCount() const  // 返回当前并查集中 集合的个数
	{
		size_t count = 0;
		for (size_t i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0)
				++count;
		}
		return count;
	}
private:
	vector<int> _ufs;	
};