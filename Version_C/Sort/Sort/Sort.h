#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

void printArray(int* arr, int size);

// 统一排升序

// 写的时候，先写单趟排序，再拓展到所有趟

// 直接插入排序
void insertSort(int* arr, int size);		

// 希尔排序:  是对直接插入排序的优化
void shellSort(int* arr, int size);
void shellSort_1(int* arr, int size);

// 选择排序
void SelectSort(int* arr, int size);
void selectSort(int* arr, int size);

// 冒泡排序
void bubbleSort(int* arr, int size);

// 快速排序
void quickSort(int* arr, int left, int right);
void quickSort_1(int* arr, int left, int right);	// 使用随机的 key 优化快排性能
void quickSort_2(int* arr, int left, int right);	// 使用三数取中作为 key 优化快排性能


