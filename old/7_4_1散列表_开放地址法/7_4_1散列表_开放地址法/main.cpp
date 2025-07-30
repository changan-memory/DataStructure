#include <iostream>
#include <stdio.h>
using namespace std;



typedef struct HTable{
	int* HashTable;		//数组指针
	int length;		//用于存储表长
}HTable;



// 判断一个数是否为素数
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
// 求小于等于给定数的最大素数
int findMaxPrime(int& num) {
    for (int i = num; i >= 2; i--) {
        if (isPrime(i)) {
            return i;
        }
    }
    return -1; // 表示未找到
}

//开放地址法
int Hash(int& data, HTable& HT) {
    //除留余数法  key mod p   p为小于等于表长的质数
    return data / findMaxPrime(HT.length);
}

void SetHashTable(int* data, HTable& HT) {
    HT.length = sizeof(*data) / sizeof(data[0]);
    HT.HashTable = new int(HT.length + 2);//哈希表的长度应该根据实际的数据长度和性能需求设置
    
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