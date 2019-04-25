#pragma once
#include <stdio.h>
#include <stdlib.h>

//冒泡排序：相邻数字比较
//每次比较结束将当前最大的数字沉底

void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int isSorted = 1;
		for (int j = 0; j < size - 1 - i; j++) {
			//
			if (arr[j]>arr[j+1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

