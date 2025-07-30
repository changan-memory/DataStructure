#include "SeqList.h"

//传入assert的值为真时， 通过   为假  报错， 并在终端中显示错误所在行

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

	//可以用任意位置插入代替尾插
	//SLInsert(ps, ps->size, data);
}
void SLPopBack(SeqList* ps) {
	//size的值为 0 时， 就不能再缩小了
	//暴力检查
	assert(ps->size > 0);
	//温柔的检查
	if (ps->size == 0)
		return;

	ps->size--;

	//SLErase(ps, ps->size - 1);
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
	assert(ps);
	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size) {
		ps->base[begin - 1] = ps->base[begin];
		begin++;
	}
	ps->size--;
}

void checkCapacity(SeqList* ps) {
	assert(ps);
	//扩容
	// 一个一个插的时候，会到size == capacity的临界点， 因此只需检查临界点
	if (ps->size == ps->capacity) {
		//将容量扩至原来的两倍
		SLDataType* newSpace = (SLDataType*)realloc(ps->base, sizeof(SLDataType) * ps->capacity * 2);
		if (newSpace == NULL) {
			perror("realloc failed");
			return;
		}
		// realloc 函数 扩容会有两种情况  一种是开辟一个新的空间   另一种是在原空间的基础上扩容
		ps->base = newSpace;
		ps->capacity *= 2;
	}
}

void SLInsert(SeqList* ps, int pos, SLDataType data) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	checkCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos) {
		ps->base[end + 1] = ps->base[end];
		end--;
	}
	ps->base[pos] = data;
	ps->size++;
}

void SLErase(SeqList* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size - 1);

	int begin = pos + 1;
	while (begin <= ps->size) {
		ps->base[begin - 1] = ps->base[begin];
		begin++;
	}
	ps->size--;
	
}

int FindSL(SeqList* ps, SLDataType ele) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		if (ps->base[i] == ele)
			return i;
	}
	return -1;
}
//打印顺序表
void SLPrint(SeqList* ps) {
	assert(ps && ps->base);
	for (int i = 0; i < ps->size; ++i) {
		printf("%d ", ps->base[i]);
	}
	printf("\n");
}