#pragma once
#include <stdio.h>
#include <stdlib.h>

//小堆

//向上调整
void adjustDown(int arr[], int size,int index) {
	while (1) {
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int min = left;

		//判断是否是叶子结点
		if (left >= size) {
			break;
		}
		//判断是否有右孩子，并调整min的值
		if (right<size && arr[left]>arr[right]) {
			min = right;
		}
		//判断是否满足堆的性质，满足就退出
		if (arr[index] <= arr[min]) {
			break;
		}
		//不满足堆的性质，交换
		int temp = arr[index];
		arr[index] = arr[min];
		arr[min] = temp;
		//更新index的值
		index = min;
	}
}

//向上调整
void adjustUp(int arr[], int size, int index) {
	while (1) {
		int parent = (index - 1) / 2;
		//判断是否是首元素，是就退出
		if (index == 0) {
			break;
		}
		//不是首元素,，判断是否满足堆的性质
		if (arr[parent] <= arr[index]) {
			break;
		}
		//不满足堆的性质，交换
		int temp = arr[index];
		arr[index] = arr[parent];
		arr[parent] = temp;
		//更新index的值
		index = parent;
	}
}

//建堆：
//找到最后一个非叶子结点，进行循环向上调整
void createHeap(int arr[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		//从最后一个非叶子节点开始，向上调整
		adjustUp(arr, size, i);
	}
}

//排序
void heapSort(int arr[], int size) {
	//先建堆
	createHeap(arr, size);
	//将最值与末尾的元素交换位置，再堆化，后循环
	for (int i = 0; i < size; i++) {
		int temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[0];
		arr[0] = temp;
		adjustDown(arr, size - 1 - i, 0);
	}
}


