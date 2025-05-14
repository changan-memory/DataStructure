#include "Stack.h"

void StackTest() {
	Stack st;
	StackInit(&st);	//初始化
	StackPush(&st, 1);	//入栈
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//出栈
	//while(st.top != 0){}  //不知道top到底指向栈顶元素，还是栈顶元素的下一个，因此不推荐这样写
	while (!StackEmpty(&st)) {
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	//销毁栈
	StackDestroy(&st);
}
//括号匹配   再写一个用不匹配进行往下判断的思路
bool isValid(char* s) {
    Stack st;
    StackInit(&st);
    bool flag = true;   //假设匹配
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            StackPush(&st, s[i]); // 左括号入栈
        else {
            if (StackEmpty(&st)) {  // 栈为空时，说明s内只有右括号或 s为空
                flag = false;
                break;  // 一旦遇到不匹配，直接跳出循环
            }
            char temp = StackTop(&st); // 获取栈顶元素
            if ((temp == '(' && s[i] == ')') ||
                (temp == '[' && s[i] == ']') ||
                (temp == '{' && s[i] == '}')) {
                StackPop(&st); // 匹配成功，栈顶元素出栈
            }
            else {
                flag = false;  // 匹配失败
                break;  // 匹配失败后，直接跳出循环
            }
        }
    }
    // 如果栈不为空，表示还有未匹配的左括号
    if (!StackEmpty(&st)) {
        flag = false;
    }
    StackDestroy(&st); // 销毁栈，防止内存泄漏
    return flag;
}


int main() {

	StackTest();
	return 0;
}