//堆排序：
//取最值，放最后，再堆化，又循环
//升序——大堆
//降序——小堆

//稳定性：排完序后保持原来相同的数字的相对位置保持不变

//插入排序：（减治算法）
//数组前半部分永远有序
//将后面的数字放到前半部分而是的位置
#include <stdio.h>
#include <stdlib.h>
#include "heapSort.h"
#include "insertSort.h"
#include "bubbleSort.h"
#include "quickSort.h"

void test() {
	int arr[] = { 9,3,2,5,7,6,10,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("未排序：");
	for (int i = 0; i < size; ++i) {
		printf("%d  ", arr[i]);
	}
	//heapSort(arr, size);
	
	//quickSort(arr, size);
	//insertSort(arr, size);
	bubbleSort(arr, size);
	printf("\n\n插入排序：");
	for (int i = 0; i < size; ++i) {
		printf("%d  ", arr[i]);
	}
}

int main() {
	test();
	system("pause");
	return 0;
}
