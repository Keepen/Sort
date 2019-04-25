#pragma once
#include <stdio.h>
#include <stdlib.h>

//插入排序
//有序区间：[0,i-1]
//待排数字：arr[i]
//无序区间：[i+1,size-1]

//遍历整个数组
//1.将待排数字与有序区间内部的数字进行比较，
//2.找到合适的位置将其插入
//3.插入后，将有序区间的数字进行搬运

//排升序
void insertSort(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		//每次处理一个数字
		//int pos;
		//从左到右遍历有序区间
		int j;
		//[0,i-1]有序区间遍历,找到合适位置
		//即第一个大于等于目标数字的位子
		for (j = 0; j < i; j++) {
			if (arr[j] >= arr[i]) {
				break;
			}
		}
		//现在j就是要将该数字插入到有序区间的下标了
		int key = arr[i];
		//将有序区间的数字进行向后移动
		for (int k = i-1; k >= j; k--) {
			arr[k + 1] = arr[k];
		}
		arr[j] = key;
	}
}