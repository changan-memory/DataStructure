#include "Queue.h"

void TestQueue() {
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 6);

	// 遍历的代码
	/*while (!QueueEmpty(&queue)) {
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}*/
	
	printf("队尾：%d  有效元素个数：%d\n", QueueBack(&queue), QueueSize(&queue));
	printf("队头：%d  有效元素个数：%d\n", QueueFront(&queue), QueueSize(&queue));

	QueuePop(&queue);
	printf("队尾：%d  有效元素个数：%d\n", QueueBack(&queue), QueueSize(&queue));
	printf("队头：%d  有效元素个数：%d\n", QueueFront(&queue), QueueSize(&queue));

	QueuePop(&queue);
	printf("队尾：%d  有效元素个数：%d\n", QueueBack(&queue), QueueSize(&queue));
	printf("队头：%d  有效元素个数：%d\n", QueueFront(&queue), QueueSize(&queue));

	QueuePop(&queue);
	QueuePop(&queue);
	printf("队列有效元素个数：%d\n", QueueSize(&queue));
	while (!QueueEmpty(&queue)) {
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}

	QueueDestroy(&queue);
}

//函数调用的栈帧  和  数据结构的栈
// 函数调用的栈帧  是操作系统层面对内存区域的划分
// 和  数据结构的栈

int main() {

	TestQueue();
	return 0;
}