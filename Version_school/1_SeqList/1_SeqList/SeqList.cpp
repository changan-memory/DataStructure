#include "SeqList.h"

// ��ʼ���ռ�  ���ó�ʼ״̬
bool InitSeqList(SeqList& L) {
	L.base = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	if (L.base == NULL) {
		perror("malloc failed\n");
		return false;
	}
	L.capacity = INIT_CAPACITY;
	L.size = 0;
	return true;
}

// ����
bool DestroySeqList(SeqList& L) {
	if (L.base) {
		free(L.base);
		L.base = NULL;
		L.capacity = L.size = 0;
		return true;
	}
	return true;
}

void CheckCapacity(SeqList& L) {
	if (L.size == L.capacity) {
		// ���ռ�
		SLDataType* newSpace = (SLDataType*)malloc(sizeof(SLDataType) * L.capacity * 2);
		if (newSpace == NULL) {
			perror("malloc failed\n");
			return;
		}
		// ��������
		memcpy(newSpace, L.base, sizeof(SLDataType) * L.size);
		// ����״̬
		free(L.base);
		L.base = newSpace;
		L.capacity *= 2;
	}
}



// size ��capacity
size_t Size(SeqList& L) {
	return L.size;
}
size_t Capacity(SeqList& L) {
	return L.capacity;
}