#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <limits>
#include <string>
using namespace std;

namespace matrix
{
	// 一般存储无向图，
	template<class V, class W, W MAX_W = INT_MAX,  bool Direction = false>		// 顶点V  和  权值W  是否有向 Direction
	class Graph
	{
	public:
		// 创建图的几种方式
		// 1. IO 输入  -- 不方便测试， oj 中更适合
		// 2. 图的结构关系 提前写到文件中，读取文件
		// 3. 手动添加边
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

		void Print1()
		{
			// 打印顶点和下标映射关系
			for (size_t i = 0; i < _vertex.size(); ++i)
			{
				cout << _vertex[i] << "-" << i << " ";
			}
			cout << endl << endl;

			cout << "  ";
			for (size_t i = 0; i < _vertex.size(); ++i)
			{
				cout << i << " ";
			}
			cout << endl;

			// 打印矩阵
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " ";
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (_matrix[i][j] != MAX_W)
						cout << _matrix[i][j] << " ";
					else
						cout << "#" << " ";
				}
				cout << endl;
			}
			cout << endl << endl;

			// 打印所有的边
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						cout << _vertex[i] << "-" << _vertex[j] << ":" << _matrix[i][j] << endl;
					}
				}
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
		//g.Print();
		g.Print1();
	}
}


// 
namespace link_table
{
	// 邻接表，vector 中挂的是 边的指针，边中存储了 dst顶点的 下标
	template<class W>
	struct Edge
	{
		int _srci;	// 起始顶点的下标		看有无存起始顶点下标的需求
		int _dsti;	// 结束顶点的下标
		W _w;		// 边的权值

		Edge<W>* _next;

		Edge(int srci, int dsti, const W& w)
			:_srci(srci)
			,_dsti(dsti)
			,_w(w)
			,_next(nullptr)
		{ }
	};

	// 链接表存储 无需整形的最大值
	template<class V, class W, bool Direction = false>		// 顶点V  和  权值W  是否有向 Direction
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		// 创建图的几种方式
		// 1. IO 输入  -- 不方便测试， oj 中更适合
		// 2. 图的结构关系 提前写到文件中，读取文件
		// 3. 手动添加边
		Graph(const V* vertex, size_t n)		// 传入顶点的数组  以及   顶点的个数  
		{
			_vertex.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertex.push_back(vertex[i]);		// 添加顶点
				_indexMap[vertex[i]] = i;			// 建立 顶点 到下标的映射
			}
			// 初始化邻接表
			_table.resize(n, nullptr);
		}

		// 考虑有向图添加边 和 无向图 的添加边
		// 添加 从 src 到 dst 的边
		void _AddEdge(const size_t srci, const size_t dsti, const W& w)
		{
			// vector 中存放 Edge*  类似哈希表
			// 添加时  头插边
			Edge* edge = new Edge(srci, dsti, w);
			edge->_next = _table[srci];
			_table[srci] = edge;

			// 无向图时，再单独处理
			if (Direction == false)
			{
				Edge* edge = new Edge(dsti, srci, w);
				edge->_next = _table[dsti];
				_table[dsti] = edge;
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
			for (int i = 0; i < _vertex.size(); ++i)
			{
				cout << "[" << i << "]->" << _vertex[i] << endl;
			}
			cout << endl;

			for (int i = 0; i < _vertex.size(); ++i)
			{
				cout << _vertex[i] << "[" << i << "]->";

				Edge* cur = _table[i];
				while (cur)
				{
					cout << "[" << _vertex[cur->_dsti] << ":" << cur->_dsti << ":" << cur->_w << "]->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}

	private:
		vector<V> _vertex;		// 顶点集合
		map<V, int> _indexMap;	// 顶点映射下标
		vector<Edge*> _table;	// 邻接表
	};

	void TestGraph()
	{
		/*link_table::Graph<char, int, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);
		g.Print();*/

		string a[] = { "张三", "李四", "王五", "赵六" };
		link_table::Graph<string, int, true> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.Print();
	}
}



// 相对来说都是稠密图，后面的算法方便表示