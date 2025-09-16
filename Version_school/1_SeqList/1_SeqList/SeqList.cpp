#include "SeqList.h"

// 初始化空间  设置初始状态
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

// 销毁
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
		// 开空间
		SLDataType* newSpace = (SLDataType*)malloc(sizeof(SLDataType) * L.capacity * 2);
		if (newSpace == NULL) {
			perror("malloc failed\n");
			return;
		}
		// 拷贝数据
		memcpy(newSpace, L.base, sizeof(SLDataType) * L.size);
		// 更新状态
		free(L.base);
		L.base = newSpace;
		L.capacity *= 2;
	}
}



// size 与capacity
size_t Size(SeqList& L) {
	return L.size;
}
size_t Capacity(SeqList& L) {
	return L.capacity;
}