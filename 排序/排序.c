//������
//ȡ��ֵ��������ٶѻ�����ѭ��
//���򡪡����
//���򡪡�С��

//�ȶ��ԣ�������󱣳�ԭ����ͬ�����ֵ����λ�ñ��ֲ���

//�������򣺣������㷨��
//����ǰ�벿����Զ����
//����������ַŵ�ǰ�벿�ֶ��ǵ�λ��
#include <stdio.h>
#include <stdlib.h>
#include "heapSort.h"
#include "insertSort.h"
#include "bubbleSort.h"
#include "quickSort.h"

void test() {
	int arr[] = { 9,3,2,5,7,6,10,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("δ����");
	for (int i = 0; i < size; ++i) {
		printf("%d  ", arr[i]);
	}
	//heapSort(arr, size);
	
	//quickSort(arr, size);
	//insertSort(arr, size);
	bubbleSort(arr, size);
	printf("\n\n��������");
	for (int i = 0; i < size; ++i) {
		printf("%d  ", arr[i]);
	}
}

int main() {
	test();
	system("pause");
	return 0;
}
