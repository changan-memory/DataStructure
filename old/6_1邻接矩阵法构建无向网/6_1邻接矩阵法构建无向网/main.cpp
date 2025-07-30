#include <iostream>
#define MaxInt 32767
#define MVNum 100

// ������ڴ洢���Ƕ�������ݣ��˴��� int�����Ӧ�ø���ʱ��������и���

typedef struct {
	int vexs[MVNum];	//���������  
	int arcs[MVNum][MVNum];	// �ڽӾ���  �洢Ȩ�� �˴��� int
	int vex_num, arc_num;	//�����һ����������ʾ��ǰͼ�Ķ������ͱ���  arc����
}AMGraph;

int LocateVex(AMGraph& G, int& vex) {	//�˴�vex������������Ϊvs2022��ʾ���ܻ�ջ�����
	//��ͼG�в��Ҷ���vex, �����򷵻����±꣬�����ڷ���-1
	for (int i = 0; i < G.vex_num; ++i) {
		if (vex == G.vexs[i])
			return i;
	}
	return -1;
}
bool CreatUDN(AMGraph& G) {	//undigraph network ������
	std::cin >> G.vex_num >> G.arc_num;	//���붥�����ͱ���
	for (int i = 0; i < G.vex_num; ++i)	//���붥�������
		std::cin >> G.vexs[i];
	//��ʼ���ڽӾ����ֵ����ʼ MaxInt
	for (int i = 0; i < G.vex_num; ++i)
		for (int j = 0; j < G.vex_num; j++)
			G.arcs[i][j] = MaxInt;
	//�����ڽӾ���
	for (int k = 0; k < G.arc_num; ++k) {
		int v1 = 0, v2 = 0, weight = 0, i = 0, j = 0;	//��Ҫ�õ��ľֲ�����
		std::cin >> v1 >> v2 >> weight;		//�����Ȩ�صı���Ҫ�����Ķ���  Ȩֵ
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);	//��������Ķ�����±�
		G.arcs[i][j] = weight;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return true;
}
int main() {

	return 0;
}