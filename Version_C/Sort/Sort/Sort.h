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
void quickSort(int* arr, int left, int right);		// 原始快排
void quickSort_1(int* arr, int left, int right);	// 使用随机的 key 优化快排性能
void quickSort_2(int* arr, int left, int right);	// 使用三数取中作为 key 优化快排性能
void quickSort_3(int* arr, int left, int right);	// 快排的挖坑法

// 以下四个 partition 函数是将 以上快排中 单趟排序的逻辑抽象出来
int partition(int* arr, int left, int right);		// 原始单趟快排
int partition_1(int* arr, int left, int right);		// 使用随机的 key 优化快排性能
int partition_2(int* arr, int left, int right);		// 使用三数取中作为 key 优化快排性能
int partition_3(int* arr, int left, int right);		// 快排的挖坑法
int partition_4(int* arr, int left, int right);		// 双指针数组分区法

void quickSort_partition(int* arr, int left, int right);
void quickSort_partition_optimize(int* arr, int left, int right);	// 快排的小区间优化

void quickSortNonR(int* arr, int left, int right);	// 为防止栈溢出，快排的非递归写法

void mergeSort(int* arr, int size);
	

