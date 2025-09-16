//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#define MaxLen 255
//
//#define CHUNKSIZE 80  //���Զ�����С
////typedef struct Chunk {
////	char ch[CHUNKSIZE];
////	struct Chunk* next;
////}Chunk;
////
////typedef struct {
////	Chunk *head, *tail;	//����ͷָ���βָ��
////	int curlen;	//���ĵ�ǰ����
////}LString;	//�ַ����Ŀ����ṹ
//
//typedef struct {
//	char ch[MaxLen + 1];
//	//�洢����һά����      �洢ʱ 0 ��λ�ò��洢��ֱ�Ӵ�1�ſ�ʼ�洢
//	// ��һ���ռ䲻�洢  ���һ���ռ�洢���� \0
//	int length;	//���ĵ�ǰ����
//}SString;
//
////BF�㷨
//int Index_BF(SString S, SString T, int pos) {	// S Ϊ����   T Ϊģʽ��
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
//int BF(char S[], char T[]) {	// S Ϊ����   T Ϊģʽ��
//	int i = 0, j = 0;
//	while (i < strlen(S) && j < strlen(T)) {	//�� 0 ��ʼ�洢�Ļ���i��jӦ����С���ַ����ĳ���
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
	char* ch;	//�����������ڴ�  ��ָ��ָ���ַ����Ļ���ַ
	int length;	//��ʾ��ǰ����
}HString;

void InitString(HString& S) {
	S.ch = (char*)malloc(sizeof(char) * MAXLEN);
	S.length = 0;
}
typedef struct {
	char ch[MAXLEN];
	int length;
}SString;
//�ַ����пպ���     
// �󴮳����� length ����
// ��մ� �� length��Ϊ 0 ���� 
bool StrEmpty(SString& S) {
	if (S.length == 0)
		return true;
	return false;
}
//�ַ����ĸ�ֵ����
bool StrAssign(SString& S, SString& T) { //���ַ��� T ��ֵ ��ֵ�� S   
	if (T.ch)	//�жϴ�����ַ����Ƿ�Ϊ��
		return false;
	//��ֵ
	int i = 1;
	while (i <= T.length +1) {
		S.ch[i] = T.ch[i]; //S �� T ����ͬ���͵Ľṹ��  ���Ը�ֵ�� ����Խ��
	}
	return true;
}

//���Ӵ� 
// �� Sub ����S �ĵ� pos ���ַ��� ���� Ϊlen���ַ���
bool SubString(SString& Sub, SString S, int pos, int len) {
	//�ж��Ӵ��Ƿ�Խ��
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos+len; i++)
		Sub.ch[i-pos+1] = S.ch[i];
	Sub.length = len;
	return true;
}
// ����0 S > T    0 S == t  С��0 S < T
int StrCmp(SString S, SString T) {
	for (int i = 1; i < S.length && i < T.length; i++) {
		if (S.ch[i] != S.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//������ �����ַ������
	return S.length - T.length;
}
int main() {
	return 0;
}