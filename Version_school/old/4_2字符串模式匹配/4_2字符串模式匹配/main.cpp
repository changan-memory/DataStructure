#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAXLEN 255


typedef struct {	// 第一个空间不放任何字符  从第二个空见开始存储字符串  这样字符串的下标和位序是一样的
	char ch[MAXLEN];
	int length;
}SString;

bool StrAssign(SString& S, char T[]) { //将字符串 T 的值 赋值给结构体 S   
	//赋值
	int i = 1;
	for (i = 1; i <= strlen(T)+1; i++) {
		S.ch[i] = T[i - 1];
	}
	S.length = i-2;
	return true;
}

int Index(SString& S, SString& T) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {	//比较从 1 到 尾的所有字符
		if (S.ch[i] == T.ch[j]) {	// 字符相等则 后移
			++i;
			++j;
		}
		else {	//不相等  则 i 和 j 回溯
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)	// j > T.length   则代表主串中有模式串
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