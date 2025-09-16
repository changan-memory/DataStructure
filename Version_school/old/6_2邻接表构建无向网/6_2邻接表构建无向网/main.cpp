#include <iostream>
#define MVNum 100

typedef struct ArcNode {	//�����еĽ��    �߽��
	int adjvex;				// �洢		�ñ���ָ��Ľ�� �������е��±�
	struct ArcNode* next_arc;	//ָ����һ���ߵ�ָ��
	int weight;		//�����ڽ���������������Ҫ�洢����Ϣ
}ArcNode;

// �洢����Ľ��  
typedef struct VNode {
	int data;	//�����ڵ�����
	ArcNode* firstArc;	//��ͷָ��
}VNode, AdjList[MVNum];
//�ȼ��� typedef struct VNode VNode;  typedef struct VNode[MVNum] AdjList
       

typedef struct {
	AdjList vertices;	//������ڽӱ��һά����
	int vex_num, arc_num;	//ʵ�ʵĶ������ͱߵĸ���
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
		i = LocateVex(G, v1);	//��ֵ����  ���غ�v1���±�
		j = LocateVex(G, v2);	//��ֵ����  ���غ�v2���±� 
		ArcNode* p1 = new ArcNode;	//ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));
		std::cin >> p1->weight;			//����Ȩֵ
		p1->adjvex = j;					//���ڽӽ����±긳ֵ�������н���adjvex
		//�����������������ͷ�巨
		p1->next_arc = G.vertices[i].firstArc;	//�½���nextָ��  ָ��  ��ͷָ�������
		G.vertices[i].firstArc = p1;			//����  ��ͷָ�� �½��
		//�編����
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