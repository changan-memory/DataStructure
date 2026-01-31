#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <limits>
using namespace std;

namespace matrix
{
	// 一般存储无向图，
	template<class V, class W, W MAX_W = INT_MAX,  bool Direction = false>		// 顶点V  和  权值W  是否有向 Direction
	class Graph
	{
	public:
		// 创建图的几种方式
		// 1. IO 输入
		// 2. 提前写在文件中，同意读取
		// 3. 手动添加
		Graph(const V* vertex, size_t n)		// 传入顶点的数组  以及   顶点的个数  
		{
			_vertex.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertex.push_back(vertex[i]);		// 添加顶点
				_indexMap[vertex[i]] = i;			// 建立 顶点 到下标的映射
			}
			// 初始化矩阵
			_matrix.resize(n);
			for (auto& e:_matrix)
			{
				e.resize(n, MAX_W);
			}
		}

		// 考虑有向图添加边 和 无向图 的添加边
		void _AddEdge(const size_t srci, const size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}
		void AddEdge(const V& srcV, const V& dstV, const W& w)
		{
			const size_t srci = GetVertexIndex(srcV);
			const size_t dsti = GetVertexIndex(dstV);
			_AddEdge(srci, dsti, w);
		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			// 传入的顶点可能不存在
			if (it != _indexMap.end())	// 存在
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}
		}
		void Print()
		{
			cout << " ";
			for (size_t i = 0; i < _matrix.size(); ++i)
				printf("%3d", i);
			cout << endl;

			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i;
				for (size_t j = 0; j < _matrix.size(); ++j)
				{
					if (_matrix[i][j] == INT_MAX)
					{
						printf("%3c", '*');
					}
					else
					{
						printf("%3d", _matrix[i][j]);
					}
				}
				cout << endl;
			}
		}

	private:
		vector<V> _vertex;		// 顶点集合
		map<V, int> _indexMap;	// 顶点映射下标
		vector<vector<W>> _matrix;	// 邻接矩阵
	};

	void TestGraph()
	{
		matrix::Graph<char, int, INT_MAX, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);
		g.Print();
	}
}
