#include "Stack.h"

void StackTest() {
	Stack st;
	StackInit(&st);	//��ʼ��
	StackPush(&st, 1);	//��ջ
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//��ջ
	//while(st.top != 0){}  //��֪��top����ָ��ջ��Ԫ�أ�����ջ��Ԫ�ص���һ������˲��Ƽ�����д
	while (!StackEmpty(&st)) {
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	//����ջ
	StackDestroy(&st);
}
//����ƥ��   ��дһ���ò�ƥ����������жϵ�˼·
bool isValid(char* s) {
    Stack st;
    StackInit(&st);
    bool flag = true;   //����ƥ��
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            StackPush(&st, s[i]); // ��������ջ
        else {
            if (StackEmpty(&st)) {  // ջΪ��ʱ��˵��s��ֻ�������Ż� sΪ��
                flag = false;
                break;  // һ��������ƥ�䣬ֱ������ѭ��
            }
            char temp = StackTop(&st); // ��ȡջ��Ԫ��
            if ((temp == '(' && s[i] == ')') ||
                (temp == '[' && s[i] == ']') ||
                (temp == '{' && s[i] == '}')) {
                StackPop(&st); // ƥ��ɹ���ջ��Ԫ�س�ջ
            }
            else {
                flag = false;  // ƥ��ʧ��
                break;  // ƥ��ʧ�ܺ�ֱ������ѭ��
            }
        }
    }
    // ���ջ��Ϊ�գ���ʾ����δƥ���������
    if (!StackEmpty(&st)) {
        flag = false;
    }
    StackDestroy(&st); // ����ջ����ֹ�ڴ�й©
    return flag;
}


int main() {

	StackTest();
	return 0;
}