#include <iostream>
#include <stdio.h>
using namespace std;



typedef struct HTable{
	int* HashTable;		//����ָ��
	int length;		//���ڴ洢��
}HTable;



// �ж�һ�����Ƿ�Ϊ����
int isPrime(int& num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
// ��С�ڵ��ڸ��������������
int findMaxPrime(int& num) {
    for (int i = num; i >= 2; i--) {
        if (isPrime(i)) {
            return i;
        }
    }
    return -1; // ��ʾδ�ҵ�
}

//���ŵ�ַ��
int Hash(int& data, HTable& HT) {
    //����������  key mod p   pΪС�ڵ��ڱ�������
    return data / findMaxPrime(HT.length);
}

void SetHashTable(int* data, HTable& HT) {
    HT.length = sizeof(*data) / sizeof(data[0]);
    HT.HashTable = new int(HT.length + 2);//��ϣ��ĳ���Ӧ�ø���ʵ�ʵ����ݳ��Ⱥ�������������
    
    for (int i = 0; i < HT.length; ++i) {
        HT.HashTable[Hash(data[i], HT)] = data[i];
    }
}


int main() {

    int arr[] = { 15, 23, 27, 38, 53, 61, 70 };
    HTable HT;
    SetHashTable(arr, HT);
    for (int i = 0; i < HT.length; ++i) {
        cout << HT.HashTable[i] << " ";
    }
	return 0;
}