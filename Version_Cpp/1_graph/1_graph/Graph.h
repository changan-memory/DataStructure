#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <limits>
#include <string>
#include <queue>
#include <stack>

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

		// 广度优先遍历
		void BFS(const V& srcV)
		{
			int srci = GetVertexIndex(srcV);
			// 检查 srci 是否存在
			if (srci < 0 || srci >= _vertex.size())
			{
				throw invalid_argument("源顶点不存在");
			}

			int vertexCount = _vertex.size();
			// 标记数组 和 用于层序遍历的队列
			queue<int> q;
			vector<bool> visited(vertexCount, false);
			// 入队列的时候，将该顶点标记为 已访问
			q.push(srci);
			visited[srci] = true;

			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				// 出队列的时候 把相邻的顶点都 入队列
				for (int i = 0; i < vertexCount; ++i)
				{
					// 有关系的才可能入队
					if (_matrix[front][i] != MAX_W)
					{
						// 只入队没被标记过的顶点
						if (visited[i] == false)
						{
							q.push(i);
							visited[i] = true;		// 入队后标记该顶点
						}
					}
				}
				cout << front << ":" << _vertex[front] << endl;
			}
		}

		// x 度好友  
		void BFS_N_level_frend(const V& srcV)
		{
			int srci = GetVertexIndex(srcV);
			// 检查 srci 是否存在
			if (srci < 0 || srci >= _vertex.size())
			{
				throw invalid_argument("源顶点不存在");
			}

			int vertexCount = _vertex.size();
			// 标记数组 和 用于层序遍历的队列
			queue<int> q;
			vector<bool> visited(vertexCount, false);
			// 入队列的时候，将该顶点标记为 已访问
			q.push(srci);
			visited[srci] = true;

			int levelSize = 1;

			// 队列出队时，一次出一行，并把这一行下面所有的元素都入队
			while (!q.empty())
			{
				for (int i = 0; i < levelSize; ++i)
				{
					int front = q.front();
					q.pop();
					// 出队列的时候 把相邻的顶点都 入队列
					for (int i = 0; i < vertexCount; ++i)
					{
						// 有关系的才可能入队
						if (_matrix[front][i] != MAX_W)
						{
							// 只入队没被标记过的顶点
							if (visited[i] == false)
							{
								q.push(i);
								visited[i] = true;		// 入队后标记该顶点
							}
						}
					}
					cout << front << ":" << _vertex[front] << " ";
				}
				levelSize = q.size();
				cout << endl;
			}
		}

		// 深度优先遍历 递归版本
		void _DFS(const int srci, vector<bool>& visited)
		{
			cout << srci << ":" << _vertex[srci] << " ";	// 访问
			visited[srci] = true;		// 标记
			// 找一个相邻的 没被访问过的点 深度优先遍历
			for (int i = 0; i < _vertex.size(); ++i)
			{
				if (_matrix[srci][i] != MAX_W && visited[i] == false)	// 邻接且没有被访问过
				{
					_DFS(i, visited);
				}
			}
		}
		// 深度优先遍历 非递归版本  借助栈实现非递归
		// 非递归 DFS 的核心实现（用栈模拟递归）
		void _DFS_stack(const int srci, vector<bool>& visited)
		{
			int n = _vertex.size();

			// 访问起点
			cout << srci << ":" << _vertex[srci] << " ";
			visited[srci] = true;
			
			stack<int> st;
			st.push(srci);

			while (!st.empty())
			{
				int top = st.top();
				bool found = false;

				// 找一个未访问的邻接点
				for (int i = 0; i < n; ++i)
				{
					if (_matrix[top][i] != MAX_W && visited[i] == false)	// 邻接且没有被访问过
					{
						cout << i << ":" << _vertex[i] << " ";
						visited[i] = true;

						st.push(i);
						found = true;
						break;   // 只深入一个
					}
				}

				// 没有可走的路，回溯
				if (found == false)
					st.pop();
			}
		}

		void DFS(const V& src)
		{
			int srci = GetVertexIndex(src);
			// 检查 srci 是否存在
			if (srci < 0 || srci >= _vertex.size())
			{
				throw invalid_argument("源顶点不存在");
			}

			vector<bool> visited(_vertex.size(), false);
			_DFS(srci, visited);	// 从 srci 开始深度优先遍历
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
	void TestGraphDBFS()
	{
		string a[] = { "张三", "李四", "王五", "赵六", "周七" };
		Graph<string, int, INT_MAX> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("张三", "李四", 10);
		g1.AddEdge("张三", "王五", 20);
		g1.AddEdge("王五", "赵六", 40);
		g1.AddEdge("王五", "周七", 30);
		//g1.Print();
		//g1.BFS("张三");
		//g1.BFS_N_level_frend("张三");
		g1.DFS("张三");
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