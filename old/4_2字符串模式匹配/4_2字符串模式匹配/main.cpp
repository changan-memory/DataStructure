#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAXLEN 255


typedef struct {	// ��һ���ռ䲻���κ��ַ�  �ӵڶ����ռ���ʼ�洢�ַ���  �����ַ������±��λ����һ����
	char ch[MAXLEN];
	int length;
}SString;

bool StrAssign(SString& S, char T[]) { //���ַ��� T ��ֵ ��ֵ���ṹ�� S   
	//��ֵ
	int i = 1;
	for (i = 1; i <= strlen(T)+1; i++) {
		S.ch[i] = T[i - 1];
	}
	S.length = i-2;
	return true;
}

int Index(SString& S, SString& T) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {	//�Ƚϴ� 1 �� β�������ַ�
		if (S.ch[i] == T.ch[j]) {	// �ַ������ ����
			++i;
			++j;
		}
		else {	//�����  �� i �� j ����
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)	// j > T.length   �������������ģʽ��
		return i - T.length;
	else
		return 0;
}

int KMP(SString& S, SString& T) {

}

int main() {
	SString S;
	SString T;
	S.ch[0] = '0';
	T.ch[0] = '0';
	char arr1[] = "aaaaaaab";
	char arr2[] = "aab";
	StrAssign(S, arr1);
	StrAssign(T, arr2);
	printf("%s\n", S.ch);
	printf("%s\n", T.ch);
	printf("%d ", Index(S, T));
	return 0;
}