#include "SeqList.h"

void SLInit(SeqList* ps) {
	assert(ps);
	ps->base = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	if (ps->base == NULL) {
		perror("malloc failed");
		return;
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

void SLDestroy(SeqList* ps) {
	assert(ps);
	free(ps->base);
	ps->base = NULL;
	ps->capacity = ps->size = 0;
	
}
// 尾插与尾删
void SLPushBack(SeqList* ps, SLDataType data) {
	assert(ps);

	checkCapacity(ps);

	//插入数据
	ps->base[ps->size++] = data;
}
void SLPopBack(SeqList* ps) {
	//size的值为 0 时， 就不能再缩小了
	//暴力检查
	assert(ps->size > 0);	//传入assert的值为真时， 通过，为家
	//温柔的检查
	if (ps->size == 0)
		return;

	ps->size--;
}
// 头插与头删
void SLPushFront(SeqList* ps, SLDataType data){
	assert(ps);
	int end = ps->size - 1;
	checkCapacity(ps);	//检查顺序表是否为满的
	while (end >= 0) {
		ps->base[end + 1] = ps->base[end];
		end--;
	}
	ps->base[0] = data;
	ps->size++;
}
void SLPopFront(SeqList* ps, SLDataType data) {

}

void checkCapacity(SeqList* ps) {

	assert(ps);
	//扩容
	// 一个一个插的时候，会到size == capacity的临界点， 因此只需检查临界点
	if (ps->size == ps->capacity) {
		SLDataType* newSpace = (SLDataType*)realloc(ps->base, sizeof(SLDataType) * ps->capacity * 2);
		if (newSpace == NULL) {
			perror("realloc failed");
			return;
		}
		// realloc 扩容会有两种情况
		ps->base = newSpace;
		ps->capacity *= 2;
	}
}


//打印顺序表
void SLPrint(SeqList* ps) {
	assert(ps && ps->base);
	for (int i = 0; i < ps->size; ++i) {
		printf("%d ", ps->base[i]);
	}
	printf("\n");
}