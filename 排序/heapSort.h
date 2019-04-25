#pragma once
#include <stdio.h>
#include <stdlib.h>

//С��

//���ϵ���
void adjustDown(int arr[], int size,int index) {
	while (1) {
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int min = left;

		//�ж��Ƿ���Ҷ�ӽ��
		if (left >= size) {
			break;
		}
		//�ж��Ƿ����Һ��ӣ�������min��ֵ
		if (right<size && arr[left]>arr[right]) {
			min = right;
		}
		//�ж��Ƿ�����ѵ����ʣ�������˳�
		if (arr[index] <= arr[min]) {
			break;
		}
		//������ѵ����ʣ�����
		int temp = arr[index];
		arr[index] = arr[min];
		arr[min] = temp;
		//����index��ֵ
		index = min;
	}
}

//���ϵ���
void adjustUp(int arr[], int size, int index) {
	while (1) {
		int parent = (index - 1) / 2;
		//�ж��Ƿ�����Ԫ�أ��Ǿ��˳�
		if (index == 0) {
			break;
		}
		//������Ԫ��,���ж��Ƿ�����ѵ�����
		if (arr[parent] <= arr[index]) {
			break;
		}
		//������ѵ����ʣ�����
		int temp = arr[index];
		arr[index] = arr[parent];
		arr[parent] = temp;
		//����index��ֵ
		index = parent;
	}
}

//���ѣ�
//�ҵ����һ����Ҷ�ӽ�㣬����ѭ�����ϵ���
void createHeap(int arr[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		//�����һ����Ҷ�ӽڵ㿪ʼ�����ϵ���
		adjustUp(arr, size, i);
	}
}

//����
void heapSort(int arr[], int size) {
	//�Ƚ���
	createHeap(arr, size);
	//����ֵ��ĩβ��Ԫ�ؽ���λ�ã��ٶѻ�����ѭ��
	for (int i = 0; i < size; i++) {
		int temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[0];
		arr[0] = temp;
		adjustDown(arr, size - 1 - i, 0);
	}
}


