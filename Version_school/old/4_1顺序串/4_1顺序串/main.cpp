//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#define MaxLen 255
//
//#define CHUNKSIZE 80  //可自定义块大小
////typedef struct Chunk {
////	char ch[CHUNKSIZE];
////	struct Chunk* next;
////}Chunk;
////
////typedef struct {
////	Chunk *head, *tail;	//串的头指针和尾指针
////	int curlen;	//串的当前长度
////}LString;	//字符串的块链结构
//
//typedef struct {
//	char ch[MaxLen + 1];
//	//存储串的一维数组      存储时 0 号位置不存储，直接从1号开始存储
//	// 第一个空间不存储  最后一个空间存储的是 \0
//	int length;	//串的当前长度
//}SString;
//
////BF算法
//int Index_BF(SString S, SString T, int pos) {	// S 为主串   T 为模式串
//	int i = pos, j = 1;
//	while (i <= S.length && j <= T.length) {
//		if (S.ch[i] == T.ch[j]) {
//			++i;
//			++j;
//		}
//		else {
//			i = i - j + 2;
//			j = 1;
//		}
//	}
//	if (j > T.length)
//		return i - T.length;
//	else
//		return 0;
//}
//
//int BF(char S[], char T[]) {	// S 为主串   T 为模式串
//	int i = 0, j = 0;
//	while (i < strlen(S) && j < strlen(T)) {	//从 0 开始存储的话，i和j应该是小于字符串的长度
//		if (S[i] == T[j]) {
//			i++;
//			j++;
//		}
//		else {
//			i = i - j + 2;
//			j = 0;
//		}
//	}
//	if (j >= strlen(T))   
//		return i - strlen(T);
//	else
//		return -1;
//}
//
//
//
//int main() {
//	char arr1[20] = "abcdefg";
//	char arr2[20] = "fg";
//	int x = BF(arr1, arr2);
//	printf("%d ", x);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXLEN 255

typedef struct {
	char* ch;	//按串长分配内存  该指针指向字符串的基地址
	int length;	//表示当前串长
}HString;

void InitString(HString& S) {
	S.ch = (char*)malloc(sizeof(char) * MAXLEN);
	S.length = 0;
}
typedef struct {
	char ch[MAXLEN];
	int length;
}SString;
//字符串判空函数     
// 求串长返回 length 即可
// 清空串 将 length改为 0 即可 
bool StrEmpty(SString& S) {
	if (S.length == 0)
		return true;
	return false;
}
//字符串的赋值函数
bool StrAssign(SString& S, SString& T) { //将字符串 T 的值 赋值给 S   
	if (T.ch)	//判断传入的字符串是否为空
		return false;
	//赋值
	int i = 1;
	while (i <= T.length +1) {
		S.ch[i] = T.ch[i]; //S 和 T 是相同类型的结构体  所以赋值后 不会越界
	}
	return true;
}

//求子串 
// 用 Sub 返回S 的第 pos 个字符起 长度 为len的字符串
bool SubString(SString& Sub, SString S, int pos, int len) {
	//判断子串是否越界
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos+len; i++)
		Sub.ch[i-pos+1] = S.ch[i];
	Sub.length = len;
	return true;
}
// 大于0 S > T    0 S == t  小于0 S < T
int StrCmp(SString S, SString T) {
	for (int i = 1; i < S.length && i < T.length; i++) {
		if (S.ch[i] != S.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//长度内 所有字符都相等
	return S.length - T.length;
}
int main() {
	return 0;
}