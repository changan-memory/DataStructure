#include "Queue.h"

void TestQueue() {
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 6);

	// �����Ĵ���
	/*while (!QueueEmpty(&queue)) {
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}*/
	
	printf("��β��%d  ��ЧԪ�ظ�����%d\n", QueueBack(&queue), QueueSize(&queue));
	printf("��ͷ��%d  ��ЧԪ�ظ�����%d\n", QueueFront(&queue), QueueSize(&queue));

	QueuePop(&queue);
	printf("��β��%d  ��ЧԪ�ظ�����%d\n", QueueBack(&queue), QueueSize(&queue));
	printf("��ͷ��%d  ��ЧԪ�ظ�����%d\n", QueueFront(&queue), QueueSize(&queue));

	QueuePop(&queue);
	printf("��β��%d  ��ЧԪ�ظ�����%d\n", QueueBack(&queue), QueueSize(&queue));
	printf("��ͷ��%d  ��ЧԪ�ظ�����%d\n", QueueFront(&queue), QueueSize(&queue));

	QueuePop(&queue);
	QueuePop(&queue);
	printf("������ЧԪ�ظ�����%d\n", QueueSize(&queue));
	while (!QueueEmpty(&queue)) {
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}

	QueueDestroy(&queue);
}

//�������õ�ջ֡  ��  ���ݽṹ��ջ
// �������õ�ջ֡  �ǲ���ϵͳ������ڴ�����Ļ���
// ��  ���ݽṹ��ջ

int main() {

	TestQueue();
	return 0;
}