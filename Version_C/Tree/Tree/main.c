#include <stdio.h>

//��ͨ�����νṹ
typedef int TreeDataType;
typedef struct TreeNode {
	struct TreeNode* firstNode;		//��һ�����ӽ��
	struct TreeNode* nextBrother;	//ָ����һ���ֵܽ��
	TreeDataType data;
}TNode;

//��ͨ���� ��ʵ�����ô������㷺����Ҫ���ڲ���ϵͳ���ļ�ϵͳ
// ���ݽṹʵ���ϣ�����ʹ�õĸ�����Ƕ�����


int main() {

	printf("��ͨ���� ��ʵ�����ô������㷺����Ҫ���ڲ���ϵͳ���ļ�ϵͳ\n");
	printf("���ݽṹʵ���ϣ�����ʹ�õĸ�����Ƕ�����");
	return 0;
}