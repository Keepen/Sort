#pragma once
#include <stdio.h>
#include <stdlib.h>

//ѡ��һ����׼ֵ��ѡ���������Ϊ��׼ֵ
//�����ұ�Ϊ��
//�������������ߣ�����С�������ұߣ��˹�����Ҫ�ָ�����
//�����㷨��ֱ����
//    1.С����ĳ���Ϊ0����û��������
//	  2.С����ĳ���Ϊ1����������


//Hover�ָ�
int partition1(int arr[], int left, int right) {
	//begin��end�����������
	int begin = left;
	int end = right;
	int pivot = arr[right];
	while (begin<end) {
		while (begin < end&&arr[begin] <= pivot) {
			begin++;
		}
		//����arr[begin]һ�����ڻ�׼ֵ
		while (begin < end&&arr[end] >= pivot) {
			end--;
		}
		//����arr[end]һ��С�ڻ�׼ֵ
		//����begin��end�±������
		int temp = arr[end];
		arr[end] = arr[begin];
		arr[begin] = temp;
	}
	//��ѭ����������ʱ�������Ѿ����ֳ�������
	//ǰ�벿�֣�С����
	//��벿�֣�������
	//��󣺻�׼ֵ
	//����׼ֵ�ŵ�����λ��
	arr[begin] = pivot;
	return begin;
}

//�ڿӷ����ָ�����
int partition2(int arr[], int left, int right) {
	int begin = left;
	int end = right;
	int pivot = arr[right];
	//��ǰ����begin�����ߣ������Ȼ�׼ֵ��ľͷŵ���׼ֵ��λ�ã�
	//end��ǰ�ߣ������Ȼ�׼ֵС�ľͷŵ��ղ�begin��λ��
	//��󽫻�׼ֵ�begin��end������λ��
	while (begin < end) {
		while (begin<end && arr[begin] <= pivot) {
			begin++;
		}
		//����begin�ǵ�һ�����ڻ�׼ֵ�������±���
		arr[end] = arr[begin];
		//end��ʼ�ߣ��Ӻ���ǰ��
		while (begin<end && arr[end] >= pivot) {
			end--;
		}
		//����end���±���ǵ�һ��С�ڻ�׼ֵ�����ֵ��±�
		//���������begin��λ��
		arr[begin] = arr[end];
	}
	//������begin��end������ʱ����
	arr[begin] = pivot;
	//begin�������ڻ�׼ֵ���±�
	return begin;
}

//ǰ���±귨
int partition3(int arr[], int left, int right) {
	//��������ֳ�������
	//1.[0,d]С����
	//2.[d,d]��׼ֵ
	//3.[d+1,i]������
	int d = left;
	int pivot = arr[right];
	//��ʼ����
	for (int i = left; i < right; i++) {
		if (arr[i] < pivot) {
			
			int temp = arr[i];
			arr[i] = arr[d];
			arr[d] = temp;
			d++;
		}
		
	}
	//��ʱd����pivotӦ�����ڵ�λ����
	int temp = pivot;
	arr[right] = arr[d];
	arr[d] = temp;
	return d;
}

void quickSortInner(int arr[], int low, int high) {
	//1.�һ�׼ֵ��ѡ�����ұ�
	//2.�����������䣬С�����󣬴�����ң����ػ�׼ֵ�±�
	//����������������

	//��1��С�����size==1��������
	if (low == high) {
		return;
	}
	//��2��С�����size==0��û��������
	if (low > high) {
		return;
	}
	//��׼ֵ���±�
	int dest = partition3(arr, low, high);
	//[left,right]���ֳ�������
	//	1.С����
	//	2.��׼ֵ���±�
	//	3.������


	//����С����
	quickSortInner(arr, low, dest-1);
	//���������
	quickSortInner(arr, dest+1, high);
}



void quickSort(int arr[], int size) {
	int low = 0;
	int high = size - 1;
	quickSortInner(arr, low, high);
}