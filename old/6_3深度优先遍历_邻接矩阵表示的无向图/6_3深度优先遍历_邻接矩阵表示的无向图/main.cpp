#include <iostream>
#include <stdlib.h>;
#include <assert.h>
#define MVNum 100

// 顶点表内存储的是顶点的数据，此处用 int替代，应该根据时期情况进行更改

typedef struct {
	int vexs[MVNum];	//创建顶点表  
	int arcs[MVNum][MVNum];	// 邻接矩阵  存储权重 此处用 int
	int vex_num, arc_num;	//顶点表不一定存满，表示当前图的定点数和边数  arc代表弧
}AMGraph;

int LocateVex(AMGraph& G, int& vex) {	//此处vex用了引用是因为vs2022提示可能会栈溢出了
	//在图G中查找顶点vex, 存在则返回其下标，不存在返回-1
	for (int i = 0; i < G.vex_num; ++i) {
		if (vex == G.vexs[i])
			return i;
	}
	return -1;
}
bool CreatUDN(AMGraph& G) {	//undigraph network 无向图
	std::cin >> G.vex_num >> G.arc_num;	//输入顶点数和边数
	for (int i = 0; i < G.vex_num; ++i)	//输入顶点的数据
		std::cin >> G.vexs[i];
	//初始化邻接矩阵的值，初始 MaxInt
	for (int i = 0; i < G.vex_num; ++i)
		for (int j = 0; j < G.vex_num; j++)
			G.arcs[i][j] = 0;
	//构造邻接矩阵
	for (int k = 0; k < G.arc_num; ++k) {
		int v1 = 0, v2 = 0, weight = 0, i = 0, j = 0;	//需要用到的局部变量
		std::cin >> v1 >> v2 >> weight;		//输入该权重的边需要依附的顶点  权值
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);	//返回输入的顶点的下标
		//G.arcs[i][j] = weight;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return true;
}

void DFS(AMGraph& G, int v) {//假设有6 个节点 v 0 - 5   传入的v 代表第 i 个结点 i 应该与存储顶点的数组下标一致
	int* visited = (int*)malloc(sizeof(int) * G.vex_num);	//访问过的元素 记录数组
	assert(visited);
	std::cout << G.vexs[v];	//访问结点的数据
	visited[v] = true;		//访问过后标记为 true
	for (int w = 0; w < G.vex_num; ++w)
		if (G.arcs[v][w] != 0 && (!visited[w]))
			DFS(G, w);
	free(visited);
}
int main() {

	return 0;
}