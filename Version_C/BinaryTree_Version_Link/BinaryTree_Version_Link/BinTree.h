#pragma once
//��(����洢)ֻ�ʺϱ�ʾ��ȫ������������һ��Ķ��������Ƽ�����ʽ�洢
//��ͨ�Ķ���������ɾ�����û������ģ�ֻ�и���ͨ�Ķ���������һЩ����(��������������)��������
//��ͨ��������ѧϰ��ɾ��ģ���Ҫѧϰ ǰ�� ���� ���� ���� ����

//�� ������ ������   
//ǰ��  �� �� �� 
//����  �� �� ��
//����  �� �� ��	ǰ�к�˵���� �� ��ǰ ���� �ں�
//���� ���� һ��һ��ı���

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int BinTDataType;
typedef struct BinaryTreeNode
{
	BinTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinTNode;


//�������������
BinTNode* BuyNode(BinTDataType data);
//�ֶ�����һ�ö����� �����Ա���
BinTNode* CreatTree();

//ǰ�� ���� �������
//�ݹ�Ĺ��̣��ǲ��Ͻ���ջ֡�Ĺ��̣������еĲ����ͺ����嶼����ջ֡��
//�ݹ�Ĺ��̲�һ����ֻ�Ƿ��ʸ���ʱ����ͬ
void PreOrder(BinTNode* root);
void InOrder(BinTNode* root);
void PostOrder(BinTNode* root);
//��ȡ���Ľ�����
int TreeSize(BinTNode* root);
//�����ĸ߶�(���)
int TreeHeight(BinTNode* root);

//���k��Ľ��ĸ���
int TreeKLevel(BinTNode* root, int k);

//����ֵΪdata�Ľ��,���ؽ���ָ�룬ʹ�ú���ͬʱ�����޸ĵĹ���
BinTNode* BinTFind(BinTNode* root, BinTDataType data);




