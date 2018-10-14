#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

void Mege(int array[], int left, int mid, int right, int exar[])//合并两个有序的小序列
{
	int left_index = left;
	int right_index = mid;
	int exar_index = left;
	while (left_index < mid&&right_index < right)
	{
		if (array[left_index] <= array[right_index])
			exar[exar_index++] = array[left_index++];
		else
			exar[exar_index++] = array[right_index++];
	}
	while (left_index < mid)
		exar[exar_index++] = array[left_index++];
	while (right_index < right)
		exar[exar_index++] = array[right_index++];
	//注意这儿是从left开始的，不能写成从0开始，否则结构是随机值
	for (int i = left; i < right; i++)
	{
		array[i] = exar[i];
	}
}

void _MergeSort(int array[], int left, int right,int exar[])//递归实现归并排序
{
	if (left + 1 == right)
		return;//这种情况说明只有一个元素,说明小序列已经有序，递归出口
	if (left >= right)
		return;//这种情况说明没有元素
	int mid = left + (right - left) / 2;
	_MergeSort(array, left, mid, exar);//注意此时的区间为左闭右开的[left,mid)
	_MergeSort(array, mid, right,exar);//[mid,right)因此mid不用加一
	//合并两个有序的小序列
	Mege(array, left, mid, right, exar);//exar是额外的辅助空间
}

void MergeSort(int array[], int size)//可以用于外部排序处理当数据量大时的排序情况
{
	int *exar = (int *)malloc(4*size);
	_MergeSort(array, 0, size, exar);
	free(exar);
}

void test()
{
	int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	MergeSort(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}