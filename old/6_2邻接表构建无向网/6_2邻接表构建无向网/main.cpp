#include <iostream>
#define MVNum 100

typedef struct ArcNode {	//链表中的结点    边结点
	int adjvex;				// 存储		该边所指向的结点 在数组中的下标
	struct ArcNode* next_arc;	//指向下一条边的指针
	int weight;		//可以在结点中添加其他的需要存储的信息
}ArcNode;

// 存储顶点的结点  
typedef struct VNode {
	int data;	//顶点内的数据
	ArcNode* firstArc;	//表头指针
}VNode, AdjList[MVNum];
//等价于 typedef struct VNode VNode;  typedef struct VNode[MVNum] AdjList
       

typedef struct {
	AdjList vertices;	//这就是邻接表的一维数组
	int vex_num, arc_num;	//实际的顶点数和边的个数
}ALGraph;

int LocateVex(ALGraph G, int v_x) {
	for (int i = 0; i < G.vex_num; ++i)
		if (v_x == G.vertices[i].data)
			return i;
}

bool CreatUDG(ALGraph& G) {
	std::cin >> G.vex_num >> G.arc_num;
	for (int i = 0; i < G.vex_num; ++i) {
		std::cin >> G.vertices[i].data;
		G.vertices[i].firstArc = NULL;
	}
	for (int k = 0; k < G.arc_num; ++k) {
		int v1 = 0, v2 = 0, i = 0, j = 0;
		std::cin >> v1 >> v2;
		i = LocateVex(G, v1);	//按值查找  返回和v1的下标
		j = LocateVex(G, v2);	//按值查找  返回和v2的下标 
		ArcNode* p1 = new ArcNode;	//ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));
		std::cin >> p1->weight;			//输入权值
		p1->adjvex = j;					//将邻接结点的下标赋值给链表中结点的adjvex
		//接下来两行是链表的头插法
		p1->next_arc = G.vertices[i].firstArc;	//新结点的next指针  指向  表头指向的区域
		G.vertices[i].firstArc = p1;			//再让  表头指向 新结点
		//如法炮制
		ArcNode* p2 = new ArcNode;
		std::cin >> p2->weight;
		p2->adjvex = i;
		p2->next_arc = G.vertices[i].firstArc;
		G.vertices[j].firstArc = p2;
	}
	return true;
}


int main() {

	ALGraph G;
	CreatUDG(G);
	return 0;
}