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
// β����βɾ
void SLPushBack(SeqList* ps, SLDataType data) {
	assert(ps);

	checkCapacity(ps);

	//��������
	ps->base[ps->size++] = data;
}
void SLPopBack(SeqList* ps) {
	//size��ֵΪ 0 ʱ�� �Ͳ�������С��
	//�������
	assert(ps->size > 0);	//����assert��ֵΪ��ʱ�� ͨ����Ϊ��
	//����ļ��
	if (ps->size == 0)
		return;

	ps->size--;
}
// ͷ����ͷɾ
void SLPushFront(SeqList* ps, SLDataType data){
	assert(ps);
	int end = ps->size - 1;
	checkCapacity(ps);	//���˳����Ƿ�Ϊ����
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
	//����
	// һ��һ�����ʱ�򣬻ᵽsize == capacity���ٽ�㣬 ���ֻ�����ٽ��
	if (ps->size == ps->capacity) {
		SLDataType* newSpace = (SLDataType*)realloc(ps->base, sizeof(SLDataType) * ps->capacity * 2);
		if (newSpace == NULL) {
			perror("realloc failed");
			return;
		}
		// realloc ���ݻ����������
		ps->base = newSpace;
		ps->capacity *= 2;
	}
}


//��ӡ˳���
void SLPrint(SeqList* ps) {
	assert(ps && ps->base);
	for (int i = 0; i < ps->size; ++i) {
		printf("%d ", ps->base[i]);
	}
	printf("\n");
}