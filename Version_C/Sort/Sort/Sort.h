#pragma once
#include <stdio.h>
#include <stdlib.h>


void printArray(int* arr, int size);

// 统一排升序

// 直接插入排序
void insertSort(int* arr, int size);		

// 希尔排序:  是对直接插入排序的优化
void shellSort(int* arr, int size);
void shellSort_1(int* arr, int size);
