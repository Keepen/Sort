#pragma once
#include <stdio.h>
#include <stdlib.h>

//选定一个基准值：选择最边上作为基准值
//以最右边为例
//比它大的在它左边，比它小的在它右边：此过程需要分割数组
//分治算法：直到：
//    1.小区间的长度为0——没有数字了
//	  2.小区间的长度为1——有序了


//Hover分割
int partition1(int arr[], int left, int right) {
	//begin、end遍历真个数组
	int begin = left;
	int end = right;
	int pivot = arr[right];
	while (begin<end) {
		while (begin < end&&arr[begin] <= pivot) {
			begin++;
		}
		//现在arr[begin]一定大于基准值
		while (begin < end&&arr[end] >= pivot) {
			end--;
		}
		//现在arr[end]一定小于基准值
		//交换begin和end下标的数字
		int temp = arr[end];
		arr[end] = arr[begin];
		arr[begin] = temp;
	}
	//大循环结束：此时该数组已经被分成三部分
	//前半部分：小区间
	//后半部分：大区间
	//最后：基准值
	//将基准值放到合适位置
	arr[begin] = pivot;
	return begin;
}

//挖坑法：分割数组
int partition2(int arr[], int left, int right) {
	int begin = left;
	int end = right;
	int pivot = arr[right];
	//从前往后，begin向右走，碰到比基准值大的就放到基准值的位置，
	//end向前走，碰到比基准值小的就放到刚才begin的位置
	//最后将基准值填到begin于end相遇的位置
	while (begin < end) {
		while (begin<end && arr[begin] <= pivot) {
			begin++;
		}
		//现在begin是第一个大于基准值的数的下标了
		arr[end] = arr[begin];
		//end开始走，从后往前走
		while (begin<end && arr[end] >= pivot) {
			end--;
		}
		//现在end的下标就是第一个小于基准值的数字的下标
		//将该数字填到begin的位置
		arr[begin] = arr[end];
	}
	//现在是begin和end相遇的时候了
	arr[begin] = pivot;
	//begin就是现在基准值的下标
	return begin;
}

//前后下标法
int partition3(int arr[], int left, int right) {
	//整个数组分成三部分
	//1.[0,d]小区间
	//2.[d,d]基准值
	//3.[d+1,i]大区间
	int d = left;
	int pivot = arr[right];
	//开始遍历
	for (int i = left; i < right; i++) {
		if (arr[i] < pivot) {
			
			int temp = arr[i];
			arr[i] = arr[d];
			arr[d] = temp;
			d++;
		}
		
	}
	//此时d就是pivot应该所在的位置了
	int temp = pivot;
	arr[right] = arr[d];
	arr[d] = temp;
	return d;
}

void quickSortInner(int arr[], int low, int high) {
	//1.找基准值，选择最右边
	//2.遍历整个区间，小的在左，大的在右，返回基准值下标
	//遍历结束的条件：

	//（1）小区间的size==1，有序了
	if (low == high) {
		return;
	}
	//（2）小区间的size==0，没有数字了
	if (low > high) {
		return;
	}
	//基准值的下标
	int dest = partition3(arr, low, high);
	//[left,right]被分成三部分
	//	1.小区间
	//	2.基准值的下标
	//	3.大区间


	//处理小区间
	quickSortInner(arr, low, dest-1);
	//处理大区间
	quickSortInner(arr, dest+1, high);
}



void quickSort(int arr[], int size) {
	int low = 0;
	int high = size - 1;
	quickSortInner(arr, low, high);
}